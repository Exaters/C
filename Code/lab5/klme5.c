#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int main() {
    int *arr, *arr2d2;
    int k, i, size;
    k = 1;
    size = 1;


    srand( time(NULL) );

    arr = (int*)malloc(10 * sizeof(int));
    arr2d2 = (int*)malloc(0);
    int size_arr2 = 0;
    // заполнение массива
    for (int i = 0; i < 10; i++) {
        arr[i] = rand() % 7 - 6 + 3;
        printf("|%d |  ",arr[i]);
    }

    printf("\nResult array: ");
    for (int i = 0; i < 10; i++)
        for (int j = i + 1; j < 10; j++)
            if ( (arr[i] == -arr[j]) && (arr[i] != 0) ) {
                arr2d2 = realloc(arr2d2,size_arr2 * sizeof(int));
                arr2d2[k] = arr[i];
                printf("%d|",arr[i]);
                break;
            } else if (arr[i] == 0)
                continue;

    // Освобождение памяти
    free(arr);

    printf("\n");
    while (i  < size){
        printf("|%d |  ",arr2d2[i]);
        i++;
    }


    return 0;
}