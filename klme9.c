#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main()
{
    for(int i = 0; i < 134; i++){
        char *my_error = strerror(i);
        printf("%d. %s\n", i, my_error);
    }
    return 0;
}