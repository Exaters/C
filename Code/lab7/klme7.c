#include <stdio.h>
#include <string.h>
#include <ctype.h>


int countofwords(char* text) {
    int count = 0;
    char* word = strtok(text, " ");
    char simvols[] = "bcdfghjklmnpqrstvwxyz"; //переменная содержит все согласные, в английском языке

    while (word != NULL) {
        if (strchr(simvols, tolower(word[0])) != NULL)
            count++;
        word = strtok(NULL, " ");
    }

    return count;
}

int main() {
    char text[100];
    printf("Insert text: ");
    fgets(text, sizeof(text), stdin);

    int result = countofwords(text);
    printf("count of words: %d\n", result);

    return 0;
}
