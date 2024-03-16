#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// student
typedef struct 
{
    char lastname[50];
    char firstname[50];
    char gender;
    int age;
    char group[50];
    int math_mark;
    int physics_mark;
    int chemistry_mark;
}Student;

// node
typedef struct Node
{
    Student data;
    struct Node* next;
}Node;

// new node
struct Node* new_node(Student student)
{
    struct Node* node = (Node*)malloc(sizeof(Node));
    node->data = student;
    node->next = NULL;
    return node;
}

// is empty stack
int is_empty(Node* pointer) {
    return !pointer;
}

// stack push
void push(Node** pointer, Student student)
{
    Node* node = new_node(student);
    node->next = *pointer;
    *pointer = node;
    printf("student %s %s push to stack success\n", student.lastname, student.firstname);
}

// stack pop
Student pop(Node** pointer)
{
    if (is_empty(*pointer)) {
        printf("stack is empty\n");
        exit(1);
    }
    Node* tmp = *pointer;
    *pointer = (*pointer)->next;
    Student popped = tmp->data;
    free(tmp);
    return popped;
}

// get root of stack
Student get_root(Node* pointer)
{
    if (is_empty(pointer)) {
        printf("no data\n");
        exit(1);
    }
    return pointer->data;
}

// print male student in same groupe
void print_male_student_in_groupe(Node* pointer, const char* groupe)
{
    printf("Список студентов мужского пола из группы %s:\n", groupe);
    while (pointer != NULL) {
        if (strcmp(pointer->data.group, groupe) == 0 && pointer->data.gender == 'M') {
            printf("Фамилия: %s, Имя: %s, Возраст: %d, Группа: %s \n", pointer->data.lastname, pointer->data.firstname, pointer->data.age, pointer->data.group);
        }
        pointer = pointer->next;
    }
}

//void randomise_push_students()
//{
//    int i = 0;
//    char stud[10];
//    Student stud
//
//}

// Пример использования стека
int main() {
    system("chcp 65001");
    Node* pointer = NULL;

    Student student1 = {"Иванов", "Иван", 'М', 20, "ИСП207", 4, 4, 5};
    Student student2 = {"Петров", "Петр", 'Ж', 21, "ИСП206", 3, 4, 4};
    Student student3 = {"Сидорова", "Елена", 'М', 19, "ИСП207", 5, 3, 4};
    Student student4 = {"Смирнов", "Алексей", 'Ж', 22, "ИСП206", 4, 5, 4};

    push(&pointer, student1);
    push(&pointer, student2);
    push(&pointer, student3);
    push(&pointer, student4);

    print_male_student_in_groupe(pointer, "ИСП206");

    return 0;
}
