//Лабораторная работа №10
//Тема: Структуры
//Разработать структуру "Студент", в состав которой входят следующие свойства:
//Фамилия, Имя, Пол, Возраст, Группа, Оценка по математике, Оценка по физике, Оценка по химии.
//Структура обязана содержать в себе все функции, которые принимают объект этой структуры в качестве входного параметра
//(по аналогии с указателем this в Python ООП).
//Вывод в консоль должен содержать в себе исходные данные и результат.
//Использование статических и динамических массивов, состоящих из объектов структур, ЗАПРЕЩАЕТСЯ
//(можно списки/стеки и любые другие типы коллекций на свое усмотрение).
//12. Вывести студентов мужского пола из определённой группы;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// представление студента
typedef struct Student {
    char last_name[50];
    char first_name[50];
    char gender;
    int age;
    char group[50];
    int math_mark;
    int physics_mark;
    int chemistry_mark;
};

// нода стэка
typedef struct Node {
    struct Student;
    struct Node* next;
};

int main()
{
    system("chcp 65001");
    printf( "Дезинтеграция Мира");

    Student Evgeniy = {.surename = "Evgenievich", .name = "Evgeniy" , .gender = "m", .age = 18, .groupe ="ISP206", .math_mark = 3, .physic_mark = 4, .chemistry_mark = 5};

    return 0;
};