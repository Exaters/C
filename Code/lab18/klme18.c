#include <stdio.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>

int countofwords(wchar_t* text) {
    int count = 0;
    wchar_t* word = wcstok(text, L" ");
    wchar_t simvols[] = L"bcdfghjklmnpqrstvwxyz"; // variable contains all consonants in English

    while (word != NULL) {
        if (wcschr(simvols, towlower(word[0])) != NULL)
            count++;
        word = wcstok(NULL, L" ");
    }

    return count;
}

void saveResults(const char* filename, int count) {
    FILE* file = fopen(filename, "wb");
    if (file != NULL) {
        fwrite(&count, sizeof(int), 1, file);
        fclose(file);
    } else {
        printf("Failed to open file for writing.\n");
    }
}

int main() {
    setlocale(LC_ALL, "");

    wchar_t text[100];

    printf("Do you want to read from a file (0) or enter from console (1)? ");
    int choice;
    scanf("%d", &choice);
    getchar(); // Consume the newline character

    if (choice == 0) {
        printf("Enter '0' to read from text file or '1' to read from binary file: ");
        int fileChoice;
        scanf("%d", &fileChoice);
        getchar(); // Consume the newline character

        if (fileChoice == 0) {
            FILE* textFile = fopen("input_text.txt", "r");
            if (textFile == NULL) {
                printf("Failed to open text file.\n");
                return 1;
            }
            fgetws(text, sizeof(text)/sizeof(wchar_t), textFile);
            fclose(textFile);
        } else if (fileChoice == 1) {
            FILE* binaryFile = fopen("input_binary.bin", "rb");
            if (binaryFile == NULL) {
                printf("Failed to open binary file.\n");
                return 1;
            }
            fread(text, sizeof(wchar_t), sizeof(text)/sizeof(wchar_t), binaryFile);
            fclose(binaryFile);
        } else {
            printf("Invalid choice.\n");
            return 1;
        }
    } else if (choice == 1) {
        printf("Enter text: ");
        fgetws(text, sizeof(text)/sizeof(wchar_t), stdin);
    } else {
        printf("Invalid choice.\n");
        return 1;
    }

    int result = countofwords(text);
    printf("Count of words: %d\n", result);

    printf("Do you want to save the result to a file (0) or display only (1)? ");
    int outputChoice;
    scanf("%d", &outputChoice);

    if (outputChoice == 0) {
        FILE* textOutput = fopen("output_text.txt", "w");
        if (textOutput != NULL) {
            fwprintf(textOutput, L"Count of words: %d\n", result);
            fclose(textOutput);
        } else {
            printf("Failed to open text output file.\n");
        }

        saveResults("output_binary.bin", result);
    }

    return 0;
}
