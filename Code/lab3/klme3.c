#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int main() {
    int numbers[3][5];
    int i, j, sum;

    sum = 0;

    srand( time(NULL) );
	
	// заполнение массива
    for (i = 0; i < 5; i++) 
        for (j = 0; j < 3; j++) 
            numbers[i][j] = rand() % 7 - 1 + 1; 
		
	for (i = 0; i < 5; i = i + 2)
        for (j = 0; j < 3; j++)
            if (numbers[i][j] % 2 == 0) {
                sum++;
                printf("\n%d s", sum);
            }
				
    for (i = 0; i < 5; i++){
        printf("\n");
        for (j = 0; j < 3; j++)
            printf("%d|", numbers[i][j]);
    }

	printf("\n%d sum", sum);
    printf("\nend");
	
    return 0;
}
