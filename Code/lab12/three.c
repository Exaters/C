#include "three.h"

const char last_names[10][20] = {
        "Natasha", "Masha", "Ilya", "Artem", "Sasha",
        "Valya", "Vasya", "Kuzya", "Buzya", "Misha"
};

const char first_names[10][20] = {
        "Ivanov", "Petrov", "Sidorov", "Smirnov", "Popov",
        "Kuznetsov", "Vasiliev", "Mikhailov", "Novikov", "Fedorov"
};

const char genders[2][10] = {
        "Male", "Female"
};

struct List* list_init() {
    struct List* result = malloc(sizeof(struct List));
    result->head = NULL;
    result->tail = NULL;
    result->append = list_append;
    result->print = print_students;
    result->print_male_students_in_group = print_male_students_in_group;
    result->free_list = free_list;
    return result;
}

void list_append(struct List* list, struct Student* student) {
    struct StudentNode* node = malloc(sizeof(struct StudentNode));
    node->data = student;
    node->next = NULL;
    if (list->tail == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }
}

void print_students(const struct List* list) {
    struct StudentNode* current = list->head;
    while (current != NULL) {
        printf("last name: %s\n", current->data->last_name);
        printf("first name: %s\n", current->data->first_name);
        printf("gender: %s\n", current->data->gender);
        printf("group: %d\n", current->data->group);
        printf("age: %d\n", current->data->age);
        printf("math mark: %d\n", current->data->math_mark);
        printf("physics mark: %d\n", current->data->physics_mark);
        printf("chemistry mark: %d\n\n", current->data->chemistry_mark);
        current = current->next;
    }
}

void print_male_students_in_group(const struct List* list, int group) {
    struct StudentNode* current = list->head;
    bool male_student_in_group = false;

    while (current != NULL) {
        if (current->data->group == group && (strstr(current->data->gender, "Male"))) {
            printf("last_name: %s\n", current->data->last_name);
            printf("first name: %s\n", current->data->first_name);
            printf("gender: %s\n", current->data->gender);
            printf("group: %d\n", current->data->group);
            printf("age: %d\n", current->data->age);
            printf("math mark: %d\n", current->data->math_mark);
            printf("physics mark: %d\n", current->data->physics_mark);
            printf("chemistry mark: %d\n\n", current->data->chemistry_mark);
            male_student_in_group = true;
        }
        current = current->next;
    }

    if (!male_student_in_group) {
        printf("No male students found in group %d\n", group);
    }
}

void free_list(struct List* list) {
    struct StudentNode* current = list->head;
    while (current != NULL) {
        struct StudentNode* next = current->next;
        free(current->data);
        free(current);
        current = next;
    }
    free(list);
}
