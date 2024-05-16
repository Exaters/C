#include "three.h"
#include "Student.h"

int main() {
    struct List* my_new_list = list_init();
    srand(time(NULL));

    for (int i = 0; i < 10; i++) {
        my_new_list->append(
                my_new_list,
                student_init(
                        last_names[rand() % 10],
                        first_names[rand() % 10],
                        genders[rand() % 2],
                        rand() % 5 + 1,
                        rand() % 7 + 15,
                        rand() % 4 + 2,
                        rand() % 4 + 2,
                        rand() % 4 + 2
                )
        );
    }

    printf("All students:\n");
    my_new_list->print(my_new_list);

    int group_to_check = 4;
    printf("Male students from group %d:\n", group_to_check);
    my_new_list->print_male_students_in_group(my_new_list, group_to_check);

    my_new_list->free_list(my_new_list);

    printf("%s\n", UNIQUE_MACRO);
    int number = 5;
    printf("Square of %d is %d\n", number, SQUARE(number));

    return 0;
}
