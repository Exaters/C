#include "three.c"
#include "Student.c"
#define lol_0 return 0; // macro

#define sum_quadro(a) {( \
    typeof(a) _a = a;                         \
(_a)*(_a) + (_a)*(_a))}

int sum_quadro_func(a){
    return a * a + a * a;
}

int main() {
    int AAAAA = 5;

    printf("%d\t", AAAAA);
    printf("%d\t", sum_quadro_func(AAAAA));
    printf("%d\t", sum_quadro(AAAAA));
    printf("%d\n", AAAAA);

    printf("%d\t", AAAAA);
    printf("%d\t", sum_quadro_func(AAAAA));
    printf("%d\t", sum_quadro(AAAAA + 3));
    printf("%d\n", AAAAA);

    printf("%d\t", AAAAA);
    printf("%d\t", sum_quadro_func(AAAAA));
    printf("%d\t", sum_quadro(AAAAA++));
    printf("%d\n", AAAAA);
}
