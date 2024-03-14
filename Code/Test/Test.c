#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Структура для представления студента
struct Student {
    char lastName[50];
    char firstName[50];
    char gender;
    int age;
    char group[50];
    int mathGrade;
    int physicsGrade;
    int chemistryGrade;
};

// Структура для представления узла стека
struct Node {
    struct Student data;
    struct Node* next;
};

// Функция для создания нового узла
struct Node* newNode(struct Student student) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    if (!node) {
        printf("Memory allocation error\n");
        exit(1);
    }
    node->data = student;
    node->next = NULL;
    return node;
}

// Функция для проверки, пуст ли стек
int isEmpty(struct Node* root) {
    return !root;
}

// Функция для добавления элемента в стек
void push(struct Node** root, struct Student student) {
    struct Node* node = newNode(student);
    node->next = *root;
    *root = node;
    printf("Student %s %s pushed to stack\n", student.lastName, student.firstName);
}

// Функция для удаления элемента из стека
struct Student pop(struct Node** root) {
    if (isEmpty(*root)) {
        printf("Stack underflow\n");
        exit(1);
    }
    struct Node* temp = *root;
    *root = (*root)->next;
    struct Student popped = temp->data;
    free(temp);
    return popped;
}

// Функция для получения верхнего элемента стека без его удаления
struct Student peek(struct Node* root) {
    if (isEmpty(root)) {
        printf("Stack is empty\n");
        exit(1);
    }
    return root->data;
}

// Функция для вывода студентов мужского пола из определенной группы
void printMaleStudentsInGroup(struct Node* root, const char* targetGroup) {
    printf("Список студентов мужского пола из группы %s:\n", targetGroup);
    while (root != NULL) {
        if (strcmp(root->data.group, targetGroup) == 0 && root->data.gender == 'M') {
            printf("Фамилия: %s, Имя: %s, Возраст: %d\n", root->data.lastName, root->data.firstName, root->data.age);
        }
        root = root->next;
    }
}

// Пример использования стека
int main() {
    system("cpch 65001");
    struct Node* root = NULL;

    struct Student student1 = {"Иванов", "Иван", 'M', 20, "ИСП207", 4.5, 4.0, 4.8};
    struct Student student2 = {"Петров", "Петр", 'M', 21, "ИСП206", 3.8, 4.2, 3.9};
    struct Student student3 = {"Сидорова", "Елена", 'F', 19, "ИСП207", 4.2, 3.7, 4.5};
    struct Student student4 = {"Смирнов", "Алексей", 'M', 22, "ИСП206", 4.0, 3.5, 4.1};

    push(&root, student1);
    push(&root, student2);
    push(&root, student3);
    push(&root, student4);

    printMaleStudentsInGroup(root, "ИСП206");

    return 0;
}
