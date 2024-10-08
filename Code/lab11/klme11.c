// Лабораторная работа №10
// Тема: Структуры
// Разработать структуру "Студент", в состав которой входят следующие свойства:
// Фамилия, Имя, Пол, Возраст, Группа, Оценка по математике, Оценка по физике, Оценка по химии.
// Структура обязана содержать в себе все функции, которые принимают объект этой структуры в качестве входного параметра
// (по аналогии с указателем this в Python ООП).
// Вывод в консоль должен содержать в себе исходные данные и результат.
// Использование статических и динамических массивов, состоящих из объектов структур, ЗАПРЕЩАЕТСЯ
// (можно списки/стеки и любые другие типы коллекций на свое усмотрение).
// 12. Вывести студентов мужского пола из определённой группы;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

const char last_names[10][20] = {
        "Natasha", "Masha", "Ilya", "Artem", "Sasha", "Valya", "Vasya", "Kuzya", "Buzya", "Misha"
};

const char first_names[10][20] = {
        "Ivanov", "Petrov", "Sidorov", "Smirnov", "Popov", "Kuznetsov", "Vasiliev", "Mikhailov", "Novikov", "Fedorov"
};

const char genders[2][10] = {
        "Male", "Female"
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
    struct StudentNode* left;
    struct StudentNode* right;
};

struct StudentTree {
    struct StudentNode* root;
    void (*insert)(struct StudentTree* tree, struct Student* student);
    void (*print)(const struct StudentTree* tree);
    void (*print_male_students_in_group)(const struct StudentTree* tree, int group);
    void (*free_tree)(struct StudentTree* tree);
};

struct StudentTree* tree_init();
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
void tree_insert(struct StudentTree* tree, struct Student* student);
void tree_insert_node(struct StudentNode** node, struct Student* student);
void print_students(const struct StudentTree* tree);
void print_students_node(const struct StudentNode* node);
void print_male_students_in_group(const struct StudentTree* tree, int group);
void print_male_students_in_group_node(const struct StudentNode* node, int group, bool* found);
void free_tree(struct StudentTree* tree);
void free_tree_node(struct StudentNode* node);

int main() {
    struct StudentTree* my_tree = tree_init();
    srand(time(NULL));

    for (int i = 0; i < 10; i++) {
        my_tree->insert(
                my_tree,
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

    printf("All students:\n");
    my_tree->print(my_tree);

    int group_to_check = 4;
    printf("Male students from group %d:\n", group_to_check);
    my_tree->print_male_students_in_group(my_tree, group_to_check);

    my_tree->free_tree(my_tree);
    return 0;
}

struct StudentTree* tree_init() {
    struct StudentTree* result = malloc(sizeof(struct StudentTree));
    result->root = NULL;
    result->insert = tree_insert;
    result->print = print_students;
    result->print_male_students_in_group = print_male_students_in_group;
    result->free_tree = free_tree;
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
) {
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

void tree_insert(struct StudentTree* tree, struct Student* student) {
    tree_insert_node(&tree->root, student);
}

void tree_insert_node(struct StudentNode** node, struct Student* student) {
    if (*node == NULL) {
        *node = malloc(sizeof(struct StudentNode));
        (*node)->data = student;
        (*node)->left = NULL;
        (*node)->right = NULL;
    } else if (strcmp(student->last_name, (*node)->data->last_name) < 0) {
        tree_insert_node(&(*node)->left, student);
    } else {
        tree_insert_node(&(*node)->right, student);
    }
}

void print_students(const struct StudentTree* tree) {
    print_students_node(tree->root);
}

void print_students_node(const struct StudentNode* node) {
    if (node != NULL) {
        print_students_node(node->left);
        printf("last name: %s\n", node->data->last_name);
        printf("first name: %s\n", node->data->first_name);
        printf("gender: %s\n", node->data->gender);
        printf("group: %d\n", node->data->group);
        printf("age: %d\n", node->data->age);
        printf("math mark: %d\n", node->data->math_mark);
        printf("physics mark: %d\n", node->data->physics_mark);
        printf("chemistry mark: %d\n\n", node->data->chemistry_mark);
        print_students_node(node->right);
    }
}

void print_male_students_in_group(const struct StudentTree* tree, int group) {
    bool male_student_in_group = false;
    print_male_students_in_group_node(tree->root, group, &male_student_in_group);

    if (!male_student_in_group) {
        printf("No male students found in group %d\n", group);
    }
}

void print_male_students_in_group_node(const struct StudentNode* node, int group, bool* found) {
    if (node != NULL) {
        print_male_students_in_group_node(node->right, group, found);
        if (node->data->group == group && strcmp(node->data->gender, "Male") == 0) {
            printf("last name: %s\n", node->data->last_name);
            printf("first name: %s\n", node->data->first_name);
            printf("gender: %s\n", node->data->gender);
            printf("group: %d\n", node->data->group);
            printf("age: %d\n", node->data->age);
            printf("math mark: %d\n", node->data->math_mark);
            printf("physics mark: %d\n", node->data->physics_mark);
            printf("chemistry mark: %d\n\n", node->data->chemistry_mark);
            *found = true;
        }
        print_male_students_in_group_node(node->left, group, found);
    }
}

void free_tree(struct StudentTree* tree) {
    free_tree_node(tree->root);
    free(tree);
}

void free_tree_node(struct StudentNode* node) {
    if (node != NULL) {
        free_tree_node(node->left);
        free_tree_node(node->right);
        free(node->data);
        free(node);
    }
}
