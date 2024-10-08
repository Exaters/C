#include <stdlib.h>


struct Student {
    char last_name[20];
    char first_name[30];
    char gender[10];
    int group;
    int age;
    int math_mark;
    int physics_mark;
    int chemistry_mark;
    void (*hello)(struct Student* student);
};

struct Student* student_init(
        const char* last_name,
        const char first_name[30],
        const char *gender,
        int group,
        int age,
        int math_mark,
        int physics_mark,
        int chemistry_mark
);
void hello(struct Student* student);