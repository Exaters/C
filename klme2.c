#include<stdio.h>
int main()
{
    int numbers[7];
    srand(time(NULL));
    for(int i=0;i<8;i++) {
        numbers[i]= rand() %6;
    }
    
    for(int i=0;i<8;i++) {
        printf( "%d " , numbers[i]);
    }
    
    printf("\n \r");
    
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
    
    return 0;
}