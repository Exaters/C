#include <stdio.h>


void findminmax(int arr[], int size, int* min, int* max) {
    if (size == 0)
        return;

    if (arr[0] < *min)
        *min = arr[0];

    if (arr[0] > *max)
        *max = arr[0];

    findminmax(arr + 1, size - 1, min, max);
}

void replaceminmax(int arr[], int size, int min, int max) {
    if (size == 0)
        return;

    if (arr[0] == min)
        arr[0] = max;

    replaceminmax(arr + 1, size - 1, min, max);
}

int main() {
    int arr[] = {6, 8, 7, 6, 3, 8, 1, 1};
    int size = 8;

    printf("before minmax: ");
    for (int i = 0; i < 8; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int min = arr[0];
    int max = arr[0];

    findminmax(arr, size, &min, &max);
    replaceminmax(arr, size, min, max);

    printf("after minmax: ");
    for (int i = 0; i < 8; i++)
        printf("%d ", arr[i]);

    return 0;
}
