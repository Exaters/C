#include "three.c"
#include "Student.c"


#define lol_0 return 0; // macro

void load_students_from_file(const char* filename, struct List* list) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file for reading\n");
        return;
    }

    char last_name[20];
    char first_name[30];
    char gender[10];
    int group;
    int age;
    int math_mark;
    int physics_mark;
    int chemistry_mark;

    while (fscanf(file, "%s %s %s %d %d %d %d %d",
                  last_name, first_name, gender, &group, &age,
                  &math_mark, &physics_mark, &chemistry_mark)) {
        struct Student* student = student_init(last_name, first_name, gender,
                                               group, age, math_mark,
                                               physics_mark, chemistry_mark);
        if (student != NULL) {
            list->append(list, student);
        }
    }

    fclose(file);
}

void save_students_to_file(const char* filename, const struct List* list) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing\n");
        return;
    }

    struct StudentNode* current = list->head;
    while (current != NULL) {
        fprintf(file, "%s %s %s %d %d %d %d %d\n",
                current->data->last_name, current->data->first_name,
                current->data->gender, current->data->group,
                current->data->age, current->data->math_mark,
                current->data->physics_mark, current->data->chemistry_mark);
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
        load_students_from_file("students.txt", my_new_list);
    }

    printf("All students:\n");
    my_new_list->print(my_new_list);

    char save_to_file;
    printf("Do you want to save students to file? (y or n): ");
    scanf(" %c", &save_to_file);
    if (save_to_file == 'y' || save_to_file == 'Y') {
        save_students_to_file("students.txt", my_new_list);
    }

    int group_to_check = 4;
    printf("Male students from group %d:\n", group_to_check);
    my_new_list->print_male_students_in_group(my_new_list, group_to_check);

    my_new_list->free_list(my_new_list);

    printf(MARCO); // why not ?

    lol_0
}
