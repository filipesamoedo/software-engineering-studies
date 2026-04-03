#include <stdio.h>
#include <locale.h>

/*
    Exercise: EX001 - Student Grade Listing

    Description:
    This program prints a formatted list of students and their respective grades
    using basic output functions in C.

    Concepts practiced:
    - printf formatting
    - tabulation using \t
    - basic console output
    - locale configuration
*/

void main(){
    setlocale(LC_ALL, "Portuguese");

    printf("<<< EX001 - Listagem >>>\n\n");
    printf("Listagem de Alunos\n");
    printf("Nome\t\tNota\n");
    printf("--------------------\n");
    printf("Ana Beatriz\t8.5\n");
    printf("Bianca Martins\t9.0\n");
    printf("Cláudio Sá\t5.5\n");
    printf("Giovana Silva\t7.5\n");
}
