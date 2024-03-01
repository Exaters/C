#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void mvidel(int);

void fillradn(int *arr, int size);

void output(int *arr, int size);

void sravn(int *arr, int size);

int pulse(int a, int b);

int minusi(int a, int b);

int mnogopluse(int a, int b);

int mnogominusi(int a, int b);

int main() {
    //присваивание указателям на функцию - функций
    void(*fillrand)(int*, int);
    fillrand=fillradn;
    void(*outptu)(int*, int);
    outptu=output;
    void(*sranv)(int*, int);
    sranv=sravn;

    int size = 10;
    mvidel(size);
//    int *arr = (int *) malloc(size * sizeof(int));

    fillrand(arr, size);
    outptu(arr, size);
    sranv(arr, size);

    free(arr);
    return 0;
}

int* mvidel(int size) {
    int* arr = (int *) malloc(size * sizeof(int));
    return arr;
}

void fillradn(intarr, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 7 - 6 + 3;
    }
}

void output(int *arr, int size) {
    for (int i = 0; i < size; i++)
        printf("|%d |  ", arr[i]);
    printf("\n");
}

void sravn(int *arr, int size) {
    printf("Result array: ");
    for (int i = 0; i < size; i++)
        for (int j = i + 1; j < size; j++)
            if ((arr[i] == -arr[j]) && (arr[i] != 0)) {
                printf("%d arr| ", arr[i]);
                break;
            } else if (arr[i] == 0) {
                continue;
            }
}