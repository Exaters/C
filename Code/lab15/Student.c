#include "Student.h"


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
