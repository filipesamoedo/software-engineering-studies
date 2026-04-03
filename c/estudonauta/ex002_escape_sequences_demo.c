#include <stdio.h>
#include <locale.h>

/*
    Exercise: EX002 - Escape Sequences Demonstration

    Description:
    This program demonstrates the use of special escape sequences
    in the C programming language using printf.

    Concepts practiced:
    - escape sequences
    - formatted console output
    - special characters in strings
*/

void main(){
    setlocale(LC_ALL, "Portuguese");

    printf("<<< EX002 - Especiais >>>\n\n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf(" \\a\t=\t\tBeep\n");
    printf(" \\n\t=\t\tNova linha\n");
    printf(" \\t\t=\t\tTabulação\n");
    printf(" \\\\t\t=\t\tBarra\n");
    printf(" %%%%\t=\t\tPorcentagem\n");
    printf(" \\?\t=\t\tInterrogação\n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
}
