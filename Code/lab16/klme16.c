#include "three.c"
#include "errno.h"
#include "Student.c"
#define lol_0 return 0; // macro


int main() {
    struct List* my_new_list = list_init();
    srand(time(NULL));

    errno = 0;
    char *my_error = strerror(1);
    printf("%d. %s\n",my_error);

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
