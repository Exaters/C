#include <stdio.h>

// signatures
int pulse(int a, int b);
int minusi(int a, int b);
int mnogopluse(int a, int b);

int mnogominusi(int a, int b);

int main() {
    // Создание массива указателей на функции
    int (*operations[4])(int, int) = {pulse, minusi, mnogopluse, mnogominusi};

    int choice, result, num1, num2;

    printf("Insert nums : ");
    scanf("%d %d", &num1, &num2);

    // Вывод доступных операций
    printf("choose oper:\n");
    printf("1. +\n");
    printf("2. -\n");
    printf("3. *\n");
    printf("4. /\n");
    printf("Your choice: ");
    scanf("%d", &choice);

    // Проверка на корректность выбора операции
    if (choice < 1 || choice > 4) {
        printf("err incorrect oper\n");
        return 1;
    }

    printf("Result: %d\n", operations[choice - 1](num1, num2));

    return 0;
}

// func init
int pulse(int a, int b) {
    return a + b;
}

int minusi(int a, int b) {
    return a - b;
}

int mnogopluse(int a, int b) {
    return a * b;
}

int mnogominusi(int a, int b) {
    if (b != 0) {
        return a / b;
    } else {
        printf("Ошибка: деление на ноль\n");
        return 0;
    }
}
