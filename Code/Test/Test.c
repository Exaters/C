#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



// student
typedef struct {
    char lastname[50];
    char firstname[50];
    char gender;
    int age;
    int group;
    int math_mark;
    int physics_mark;
    int chemistry_mark;
} Student;

//const char arrays
const char mail_names[30][30] = {
        "ivan",
        "ilya",
        "arteem",
        "gleb",
        "nikita",
        "danil",
        "anton"
};

const char mail_lastnames[30][30] = {
        "ivanov",
        "ilyin",
        "arteemov",
        "glebov",
        "nikitin",
        "danilov",
        "antonov"
};

const char fem_names[30][30] = {
        "liza",
        "vika",
        "anya",
        "olya",
        "sweeta",
        "nonna",
        "nastya"
};

const char fem_lastnames[30][30] = {
        "ivanova",
        "ilyina",
        "arteemova",
        "glebova",
        "nikitina",
        "danilova",
        "antonova"
};

//struct List {
//    struct Node* head;
//    struct Node* end;
//    unsigned long int size;
//    void (*insert)(struct List* list, struct Student* student, int index);
//    struct Student* (*erase)(struct List* list, int index);
//    struct Student* (*get)(struct List* list, int index);
//    void (*append)(struct List* list, struct Student* student);
//    void (*free_list)(struct List* list);
//};

char generate_gender();

int generate_age();

//void generate_random_student(Student *student) {
//    if (generate_gender() == 'M') {
//        strcpy(student->firstname, mail_names[rand() % 7]);
//        strcpy(student->lastname, mail_lastnames[rand() % 7]);
//    } else {
//        strcpy(student->firstname, fem_names[rand() % 7]);
//        strcpy(student->lastname, fem_lastnames[rand() % 7]);
//    }
//
//    student->gender = generate_gender();
//    student->age = generate_age();
//
//    student->group = 200; // Default group
//
//
//}

// node
typedef struct Node {
    Student* student;
    struct Node* next;
}Node;

// new node
struct Node* new_node(Student* student) {
    struct Node* node = (Node*)malloc(sizeof(Node));
    node->student;
    node->next = NULL;
    return node;
}

// is empty stack
int is_empty(Node* pointer) {
    return !pointer;
}

// stack push
void push(Node** pointer, Student* student) {
    Node* node = new_node(student);
    node->next = *pointer;
    *pointer = node;
    printf("student %s %s push to stack success\n", student->lastname, student->firstname);
}

// stack pop
Student pop(Node** pointer) {
    if (is_empty(*pointer)) {
        printf("stack is empty\n");
        exit(1);
    }
    Node* tmp = *pointer;
    *pointer = (*pointer)->next;
    Student popped = *tmp->student;
    free(tmp);
    return popped;
}

//// get root of stack
//Student get_root(Node* pointer) {
//    if (is_empty(pointer)) {
//        printf("no data\n");
//        exit(1);
//    }
//    return pointer->data;
//}

// print male student in same groupe
void print_male_student_in_groupe(Node* pointer, int groupe) {
    printf("Список студентов мужского пола из группы %s:\n", groupe);
    while (pointer != NULL) {
        if (pointer->student->gender == 'M' && (pointer->student->group == groupe)) {
            printf("Фамилия: %s, Имя: %s, Возраст: %d, Группа: %s \n", pointer->student->lastname, pointer->student->firstname, pointer->student->age, pointer->student->group);
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
    srand(time(NULL));

    Node* pointer = NULL;

    const int size_stud = 10;
    for (int i = 0; i < size_stud; i++) {
        Student* student = malloc(sizeof(Student));
        if (rand() % 2 == 1) {
             //malloc(sizeof(Student));
//                    {"", "", 'M', rand() % 5 + 18, rand() % 5 + 1, rand() % 3 + 3, rand() % 3 + 3, rand() % 3 + 3};
//            strcpy(&student->gender, (const char *) 'M');
            student->gender = 'M';
            student->age = rand() % 5 + 18;
            student->group = rand() % 5 + 1;
            strcpy(student->firstname, mail_names[rand() % 10]);
            strcpy(student->lastname, mail_lastnames[rand() % 10]);
            push(&pointer, student);
        } else {
//            Student* student = {"", "", 'F', rand() % 5 + 18, rand() % 5 + 1, rand() % 3 + 3, rand() % 3 + 3, rand() % 3 + 3};
//            strcpy(student->firstname, fem_names[rand() % 10]);
//            strcpy(student->lastname, fem_lastnames[rand() % 10]);
//            push(&pointer, student);
        }
    }

    print_male_student_in_groupe(pointer,6);

    return 0;
}

//char generate_gender() {
//    if (rand() % 2 == 0) {
//        return 'M';
//    } else {
//        return 'F';
//    }
//}
//
//// Age between 16 and 20
//int generate_age() {
//    return 16 + rand() % 5;
//}
