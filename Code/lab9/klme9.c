#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int oddorevenfunc();
int minmaxarrayfunc();
int oddsringevennumber();
int* videlenie(int);
void fillrand(int*, int);
void output(int*, int);
void sravnenie(int*, int);

int main() {
    int (*funcpointer)();
    funcpointer = oddorevenfunc;
    funcpointer();
    funcpointer = minmaxarrayfunc;
    funcpointer();
    funcpointer = oddsringevennumber;
    funcpointer();

    int* (*vidlenie)(int);
    vidlenie = videlenie;

    int size = 10;
    videlenie(size);
    int* arr = vidlenie(size);

    void(*arrimp)(int*, int);
    arrimp = fillrand;
    arrimp(arr, size);
    arrimp = output;
    arrimp(arr, size);
    arrimp = sravnenie;
    arrimp(arr, size);

    free(arr);
    return 0;
}

///////////////////////////////////////////////////////////////////////////

int* videlenie(int size) {
    int* arr = (int *) malloc(size * sizeof(int));
    return arr;
}

void fillrand(int* arr, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 7 - 6 + 3;
    }
}

void output(int* arr, int size) {
    for (int i = 0; i < size; i++)
        printf("|%d |  ", arr[i]);
    printf("\n");
}

void sravnenie(int* arr, int size) {
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


int oddorevenfunc() {
    int b;int a;
    for (size_t i = 0; i < 2; i++) {
        printf("\nPlease insert integer number");
        printf("\n" );
        scanf("%d",&a);
        b= a%2;
        if (b != 0) {
            printf("\nodd number");

        } else {
            printf("\neven number");
        }
    }
    return 0;

}

int minmaxarrayfunc()
{
    int numbers[7];
    srand(time(NULL));
    for(int i=0;i<8;i++) {
        numbers[i]= rand() %6;
    }

    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    for(int i=0;i<8;i++) {
        printf( "%d " , numbers[i]);
    }

    printf("\n");

    int max=numbers[0];
    int min=numbers[0];

    for(int i=0;i<8;i++) {
        if (numbers[i] > max) {
            max=numbers[i];
        }
    }

    printf("%d \n",max); // отладка

    for(int i=0;i<8;i++) {
        if (numbers[i] <=  min) {
            min=numbers[i];
        }
    }

    printf("%d \n",min); // отладка


    for(int i=0;i<8;i++)
        if  (numbers[i] == min) {
            numbers[i]=max;
        }


    for(int i=0;i<8;i++) {
        printf( "%d " , numbers[i]);
    }

    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");

}

int oddsringevennumber() {
    int numbers[3][5];
    int i, j, sum;

    sum = 0;

    srand(time(NULL));

    // заполнение массива
    for (i = 0; i < 3; i++)
        for (j = 0; j < 5; j++)
            numbers[i][j] = rand() % 7 - 1 + 1;

    for (i = 0; i < 3; i++)
        for (j = 0; j < 5; j++)
            if (numbers[i][j] % 2 == 0) {
                sum++;
                printf("\n%d s", sum);
            }

    for (i = 0; i < 3; i++) { //
        printf("\n");
        for (j = 0; j < 5; j++) //
            printf("%d|", numbers[i][j]);
    }

    printf("\n%d sum", sum);
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}
