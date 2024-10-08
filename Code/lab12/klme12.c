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
    struct StudentNode* left;
    struct StudentNode* right;
};

struct StudentTree {
    struct StudentNode* root;
    void* (*insert)(void* tree, void* student);
    void* (*print)(void* tree);
    void* (*print_male_students_in_group)(void* tree, void* group);
    void* (*free_tree)(void* tree);
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
void* tree_insert(void* tree, void* student);
void tree_insert_node(struct StudentNode** node, struct Student* student);
void* print_students(const void* tree);
void print_students_node(const struct StudentNode* node);
void* print_male_students_in_group(const void* tree, void* group);
void print_male_students_in_group_node(const struct StudentNode* node, int group, bool* found);
void* free_tree(void* tree);
void free_tree_node(struct StudentNode* node);

struct GroupPar {
    const struct StudentTree* tree;
    int group;
};

int main() {
    struct StudentTree* my_tree = tree_init();
    srand(time(NULL));

    for (int i = 0; i < 10; i++) {
        struct Student* student = student_init(
                last_names[rand() % 10],
                first_names[rand() % 10],
                genders[rand() % 2],
                rand() % 5 + 1, // Генерация случайной группы от 1 до 5
                rand() % 7 + 15,
                rand() % 4 + 2,
                rand() % 4 + 2,
                rand() % 4 + 2
        );
        my_tree->insert(my_tree, student);
    }

    printf("All students:\n");
    my_tree->print(my_tree);

    int group_to_check = 4;
    struct GroupPar group_param = {my_tree, group_to_check};
    printf("Male students from group %d:\n", group_to_check);
    my_tree->print_male_students_in_group(my_tree, &group_param);

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

void* tree_insert(void* tree, void* student) {
    struct StudentTree* t = (struct StudentTree*) tree;
    tree_insert_node(&t->root, (struct Student*) student);
    return NULL;
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

void* print_students(const void* tree) {
    const struct StudentTree* t = (const struct StudentTree*) tree;
    print_students_node(t->root);
    return NULL;
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

void* print_male_students_in_group(const void* tree, void* param) {
    const struct StudentTree* t = (const struct StudentTree*) tree;
    struct GroupPar* group_param = (struct GroupPar*) param;
    bool male_student_in_group = false;
    print_male_students_in_group_node(t->root, group_param->group, &male_student_in_group);

    if (!male_student_in_group) {
        printf("No male students found in group %d\n", group_param->group);
    }
    return NULL;
}

void print_male_students_in_group_node(const struct StudentNode* node, int group, bool* found) {
    if (node != NULL) {
        print_male_students_in_group_node(node->left, group, found);
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
        print_male_students_in_group_node(node->right, group, found);
    }
}

void* free_tree(void* tree) {
    struct StudentTree* t = (struct StudentTree*) tree;
    free_tree_node(t->root);
    free(t);
    return NULL;
}

void free_tree_node(struct StudentNode* node) {
    if (node != NULL) {
        free_tree_node(node->left);
        free_tree_node(node->right);
        free(node->data);
        free(node);
    }
}
