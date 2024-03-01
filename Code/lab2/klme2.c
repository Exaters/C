#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int main() {
    int numbers[7];
    int i;
    srand(time(NULL));

    for(i = 0; i < 8; i++)
        numbers[i]= rand() %6;

    for(i = 0; i < 8; i++)
        printf( "%d " , numbers[i]);

    int max=numbers[0];
    int min=numbers[0];

    for(i = 0; i < 8; i++)
        if (numbers[i] > max)
            max=numbers[i];

    printf("\n%d ",max); // отладка

    for(i = 0; i < 8; i++)
        if (numbers[i] <=  min)
            min=numbers[i];

    printf("\n%d \n",min); // отладка

    for(i = 0; i < 8; i++)
        if (numbers[i] == min)
            numbers[i]=max;

    for(i = 0; i < 8; i++)
        printf( "%d " , numbers[i]);

    return 0;
}