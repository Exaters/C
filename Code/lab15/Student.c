#include "Student.h"


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


struct Student* student_init(
        const char* last_name,
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

