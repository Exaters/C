#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

const char last_names[10][20] = {
        "Natasha",
        "Masha",
        "Ilya",
        "Artem",
        "Sasha",
        "Valya",
        "Vasya",
        "Kuzya",
        "Buzya",
        "Misha"
};

const char first_names[10][20] = {
        "Ivanov",
        "Petrov",
        "Sidorov",
        "Smirnov",
        "Popov",
        "Kuznetsov",
        "Vasiliev",
        "Mikhailov",
        "Novikov",
        "Fedorov"
};

const char genders[2][10] = {
        "Male",
        "Female"
};

struct Student {
    char last_name[20];
    char first_name[30];
    char gender[10];
    int group;
    int age;
    int math_mark;
    int physics_mark;
    int chemistry_mark;
};

struct StudentNode {
    struct Student* data;
    struct StudentNode* next;
};

struct List {
    struct StudentNode* head;
    struct StudentNode* tail;
    void (*append)(struct List* list, struct Student* student);
    void (*print)(const struct List* list);
    void (*print_male_students_in_group)(const struct List* list, int group);
    void (*free_list)(struct List* list);
};

struct List* list_init();
struct Student* student_init(
        const char last_name[20],
        const char first_name[30],
        const char *gender,
        int group,
        int age,
        int math_mark,
        int physics_mark,
        int chemistry_mark
);
void list_append(struct List* list, struct Student* student);
void print_students(const struct List* list);
void print_male_students_in_group(const struct List* list, int group);
void free_list(struct List* list);

int main()
{
    struct List* my_new_list = list_init();
    srand(time(NULL));

    for (int i = 0; i < 10; i++)
    {
        my_new_list->append(
                my_new_list,
                student_init(
                        last_names[rand() % 10],
                        first_names[rand() % 10],
                        genders[rand() % 2],
                        rand() % 5 + 1, // Генерация случайной группы от 1 до 5
                        rand() % 7 + 15,
                        rand() % 4 + 2,
                        rand() % 4 + 2,
                        rand() % 4 + 2
                )
        );
    }

    printf("all students:\n");
    my_new_list->print(my_new_list);

    int group_to_check = 4;
    printf("male students from group %d:\n", group_to_check);
    my_new_list->print_male_students_in_group(my_new_list, group_to_check);

    my_new_list->free_list(my_new_list);
    return 0;
}

struct List* list_init()
{
    struct List* result = malloc(sizeof(struct List));
    result->head = NULL;
    result->tail = NULL;
    result->append = list_append;
    result->print = print_students;
    result->print_male_students_in_group = print_male_students_in_group;
    result->free_list = free_list;
    return result;
}

struct Student* student_init(
        const char last_name[20],
        const char first_name[30],
        const char *gender,
        int group,
        int age,
        int math_mark,
        int physics_mark,
        int chemistry_mark
)
{
    struct Student* student = malloc(sizeof(struct Student));
    strcpy(student->last_name, last_name);
    strcpy(student->first_name, first_name);
    strcpy(student->gender, gender);
    student->group = group;
    student->age = age;
    student->math_mark = math_mark;
    student->physics_mark = physics_mark;
    student->chemistry_mark = chemistry_mark;
    return student;
}

void list_append(struct List* list, struct Student* student)
{
    struct StudentNode* node = malloc(sizeof(struct StudentNode));
    node->data = student;
    node->next = NULL;
    if (list->tail == NULL)
    {
        list->head = node;
        list->tail = node;
    } else
    {
        list->tail->next = node;
        list->tail = node;
    }
}

void print_students(const struct List* list)
{
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

void print_male_students_in_group(const struct List* list, int group)
{
    struct StudentNode* current = list->head;
    bool male_student_in_group = false;

    while (current != NULL)
    {
        if (current->data->group == group && (strstr(current->data->gender, "Male")))
        {
            printf("last_name: %s\n", current->data->last_name);
            printf("first_name: %s\n", current->data->first_name);
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

    if (!male_student_in_group)
    {
        printf("No male students found in group %d\n", group);
    }
}

void free_list(struct List* list)
{
    struct StudentNode* current = list->head;
    while (current != NULL) {
        struct StudentNode* next = current->next;
        free(current->data);
        free(current);
        current = next;
    }
    free(list);
}
