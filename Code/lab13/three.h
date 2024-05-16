#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

extern const char last_names[10][20];
extern const char first_names[10][20];
extern const char genders[2][10];

#define MARCO "This is a MARCO" // why not?
#define RAND_RANGE(min, max) ((min) + rand() % ((max) - (min) + 1))

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
void list_append(struct List* list, struct Student* student);
void print_students(const struct List* list);
void print_male_students_in_group(const struct List* list, int group);
void free_list(struct List* list);

