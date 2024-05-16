all: main

main: main.o three.o Student.o
    gcc -o main main.o three.o Student.o

main.o: main.c three.h Student.h
    gcc -c main.c

three.o: three.c three.h
    gcc -c three.c

Student.o: Student.c Student.h
    gcc -c Student.c

clean:
    rm -f main *.o
