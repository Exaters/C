void Normal_Side_Spaces(wchar_t* text) {
    wchar_t* readPtr = text;
    wchar_t* writePtr = text;
    int inWord = 0;

    while (*readPtr != L'\0') {
        if (iswspace(*readPtr)) {
            if (inWord) {
                *writePtr++ = L' ';
                inWord = 0;
            }
        } else {
            *writePtr++ = *readPtr;
            inWord = 1;
        }
        readPtr++;
    }
    if (writePtr > text && iswspace(*(writePtr - 1))) {
        writePtr--;
    }
    *writePtr = L'\0';
}

int Count_Of_Words(wchar_t* text) {
    int count = 0;
    wchar_t* word = wcstok(text, L" ");
    wchar_t consonants[] = L"bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ"; // variable contains all consonants in English

    while (word != NULL) {
        if (wcschr(consonants, word[0]) != NULL)
            count++;
        word = wcstok(NULL, L" ");
    }

    return count;
}

void Save_Results(wchar_t* filename, int count) {
    FILE* file = fopen(filename, "wb");
    if (file != NULL) {
        fwrite(&count, sizeof(int), 1, file);
        fclose(file);
    } else {
        printf("Failed to open file for writing.\n");
    }
}