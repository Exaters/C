#include <stdio.h>


int main(){
    int a;int b;
    for (size_t i = 0; i < 10; i++)
    {
        printf("\nPlease insert integer number");
        printf("\n"  "");
        scanf("%d",&a);
        b= a%2;
        if (b != 0)
        {
            printf("\n odd number");

        }else
        {
            printf("\n even number");
        }
    }
    return 0;
}