#include <stdio.h>
int main(void)
{
  int a;int b;
  for (size_t i = 0; i < 10; i++)
  {
  printf("Hellow Awery nyan!");
  printf("\nPlease insert integer number\r");
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