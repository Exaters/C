#include "Student.h"
#include <string.h>


void load_students_from_binary_file(const char* filename, struct List* list) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file for reading\n");
        exit(errno);
    }

    struct Student student;
    while (fread(&student, sizeof(struct Student), 1, file) == 1) {
        struct Student* new_student = student_init(student.last_name, student.first_name, student.gender,
                                                   student.group, student.age, student.math_mark,
                                                   student.physics_mark, student.chemistry_mark);
        if (new_student != NULL) {
            list->append(list, new_student);
        }
    }

    fclose(file);
}

void save_students_to_binary_file(const char* filename, const struct List* list) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error opening file for writing\n");
        exit(errno);
    }

    struct StudentNode* current = list->head;
    while (current != NULL) {
        fwrite(current->data, sizeof(struct Student), 1, file);
        current = current->next;
    }

    fclose(file);
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
    if (errno == 12){
        perror("Memory allocation error\n");
        exit(errno);
    }
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
