#include "three.c"
#include "Student.c"


#define lol_0 return 0; // macro

void load_students_from_binary_file(const char* filename, struct List* list) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file for reading\n");
        return;
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
        return;
    }

    struct StudentNode* current = list->head;
    while (current != NULL) {
        fwrite(current->data, sizeof(struct Student), 1, file);
        current = current->next;
    }

    fclose(file);
}

int main() {
    struct List* my_new_list = list_init();
    srand(time(NULL));

    for (int i = 0; i < 10; i++) {
        my_new_list->append(
                my_new_list,
                student_init(
                        last_names[RAND_RANGE(0, 9)],
                        first_names[RAND_RANGE(0, 9)],
                        genders[RAND_RANGE(0, 1)],
                        RAND_RANGE(1, 5),
                        RAND_RANGE(15, 21),
                        RAND_RANGE(2, 5),
                        RAND_RANGE(2, 5),
                        RAND_RANGE(2, 5)
                )
        );
    }

    char read_from_file;
    printf("Do you want to read students from file? (y or n): ");
    scanf(" %c", &read_from_file);
    if (read_from_file == 'y' || read_from_file == 'Y') {
        load_students_from_binary_file("students.bin", my_new_list);
    }

    printf("All students:\n");
    my_new_list->print(my_new_list);

    char save_to_file;
    printf("Do you want to save students to file? (y or n): ");
    scanf(" %c", &save_to_file);
    if (save_to_file == 'y' || save_to_file == 'Y') {
        save_students_to_binary_file("students.bin", my_new_list);
    }

    int group_to_check = 4;
    printf("Male students from group %d:\n", group_to_check);
    my_new_list->print_male_students_in_group(my_new_list, group_to_check);

    my_new_list->free_list(my_new_list);

    printf(MARCO); // why not ?

    lol_0
}
