#include "three.c"
#include "Student.c"


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


    printf("All students:\n");
    my_new_list->print(my_new_list);

    int group_to_check = 4;
    printf("Male students from group %d:\n", group_to_check);
    my_new_list->print_male_students_in_group(my_new_list, group_to_check);

    my_new_list->free_list(my_new_list);

    printf(MARCO); // why not ?

    return 0;
}
