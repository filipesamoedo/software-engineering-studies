/*
Escape Plan – Island Code (Master Level)
Inventory Management System in C
===========================================================
Description
-----------
This program simulates an inventory management system used
during a fictional escape mission scenario.

Instead of a "backpack", the program uses the concept of an
"Inventory", because the stored items include large structural
components that would not realistically fit inside a backpack,
such as beams, power components, or structural parts.

The system allows the user to:

• Add components to the inventory
• Remove components
• Display all components
• Organize the inventory using sorting algorithms
• Search for a component using binary search

The inventory is implemented using a struct array.

===========================================================
Computer Science Concepts Practiced
===========================================================

This project was designed to practice important programming
and algorithm concepts in C, including:

• Structs and data modeling
• Arrays of structures
• Modular programming with functions
• Input validation and defensive programming
• String manipulation
• Sorting algorithms
• Binary search
• Algorithm performance measurement using time functions

Sorting algorithms implemented:

• Bubble Sort (alphabetical order by component name)
• Insertion Sort (grouping by component type)
• Selection Sort (ordering by assembly priority)

Search algorithm implemented:

• Binary Search (requires inventory sorted by name)

The program also measures:

• Number of comparisons performed by each algorithm
• Execution time using the clock() function

===========================================================
Important Implementation Improvements
===========================================================

1) String Input Supporting Spaces and Accents

The program reads text using fgets(), which allows users
to enter names with:

• Spaces
• Uppercase and lowercase letters
• Accented characters

Example valid inputs:

"Motherboard"
"Power Supply"
"Placa Mãe"
"Painel Solar"

The function removerQuebraLinha() removes the newline
character inserted by fgets().

String comparisons are performed using strcmp(), which
correctly compares multi-word strings.

-----------------------------------------------------------
2) Safe Integer Input (Input Validation)

User input is protected using the function:

    lerInteiro()

Instead of reading integers directly with scanf(), the
program reads a full line using fgets() and then validates
the input with sscanf().

This prevents the program from crashing if the user types
a letter or word instead of a number.

Example invalid inputs safely handled:

"abc"
"ten"
"3x"

If invalid input is detected, the program asks the user
to enter a valid number again.

This technique is an example of defensive programming
and improves program robustness.

-----------------------------------------------------------

4) Buffer Handling and Input Stability

Functions were added to properly handle input buffers and
avoid common C input problems such as leftover characters
in the input stream.

===========================================================
Educational Purpose
===========================================================

This project is designed for educational purposes in
algorithm analysis and structured programming in C.

It demonstrates how classical algorithms interact with
real program structures such as inventory systems.
===========================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 20

// =======================
// STRUCT
// =======================
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
    int prioridade;
} Componente;

// =======================
// PROTOTIPOS
// =======================

void limparBuffer();
int lerInteiro();

void adicionarComponente(Componente inventario[], int *qtd);
void descartarComponente(Componente inventario[], int *qtd);
void mostrarComponentes(Componente inventario[], int qtd);

void bubbleSortNome(Componente inventario[], int qtd, int *comparacoes);
void insertionSortTipo(Componente inventario[], int qtd, int *comparacoes);
void selectionSortPrioridade(Componente inventario[], int qtd, int *comparacoes);

int buscaBinariaPorNome(Componente inventario[], int qtd, char chave[], int *comparacoes);

void organizarInventario(Componente inventario[], int qtd, int *ordenadoPorNome);
void medirTempo(void (*algoritmo)(), Componente inventario[], int qtd);

void removerQuebraLinha(char *str);

// =======================
// FUNÇÃO PRINCIPAL
// =======================

int main() {

    Componente inventario[MAX];
    int qtd = 0;
    int opcao;
    int ordenadoPorNome = 0;

    do {

        printf("\n===========================================\n");
        printf("Plano de Fuga - Código da Ilha (Nível Mestre)\n");
        printf("Itens no Inventário: %d/%d\n", qtd, MAX);
        printf("Status da Ordenação por Nome: %s\n",
               ordenadoPorNome ? "ORDENADO" : "NAO ORDENADO");

        printf("\n1. Adicionar Componente\n");
        printf("2. Descartar Componente\n");
        printf("3. Listar Componentes [Inventario]\n");
        printf("4. Organizar Inventario [Ordenar Componentes]\n");
        printf("5. Busca Binaria por Componente-Chave [por nome]\n");
        printf("0. ATIVAR TORRE DE FUGA (Sair)\n");

        printf("\nEscolha uma opcao: ");

        opcao = lerInteiro();

        switch(opcao) {

        case 1:
            adicionarComponente(inventario, &qtd);
            ordenadoPorNome = 0;
            break;

        case 2:
            descartarComponente(inventario, &qtd);
            break;

        case 3:
            mostrarComponentes(inventario, qtd);
            break;

        case 4:
            organizarInventario(inventario, qtd, &ordenadoPorNome);
            break;

        case 5: {

            if(!ordenadoPorNome) {
                printf("\nInventario precisa estar ORDENADO POR NOME para busca binaria.\n");
                printf("Pressione Enter para continuar...");
                getchar();
                printf("\n");
                break;
            }

            char chave[30];
            int comparacoes = 0;

            printf("\nDigite o nome do componente-chave: ");
            fgets(chave, 30, stdin);
            removerQuebraLinha(chave);

            clock_t inicio = clock();
            int pos = buscaBinariaPorNome(inventario, qtd, chave, &comparacoes);
            clock_t fim = clock();
            double tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

            if(pos != -1) {
                printf("\nComponente encontrado!");
                printf("\nNome: %s Tipo: %s Quantidade: %d Prioridade: %d\n",
                       inventario[pos].nome,
                       inventario[pos].tipo,
                       inventario[pos].quantidade,
                       inventario[pos].prioridade);
                printf("\nComparacoes: %d\n", comparacoes);
                printf("Tempo: %f segundos\n", tempo);
            } else {
                printf("\nComponente nao encontrado. Comparacoes: %d\n", comparacoes);
                printf("Tempo: %f segundos\n", tempo);
            }
            break;
        }

        case 0:
            printf("\nAtivando Torre de Fuga...\n");
            break;

        default:
            printf("\nOpcao invalida.\n");
        }

    } while(opcao != 0);

    return 0;
}

// =======================
// FUNÇÕES AUXILIARES
// =======================

int lerInteiro() {

    char buffer[50];
    int numero;
    char extra;

    while(1) {

        fgets(buffer, sizeof(buffer), stdin);

        if(sscanf(buffer,"%d %c",&numero,&extra) == 1)
            return numero;

        printf("Ops, voce digitou uma letra ou palavra. Digite um numero: ");
    }
}

void removerQuebraLinha(char *str) {

    str[strcspn(str,"\n")] = 0;
}

// =======================
// ADICIONAR COMPONENTE
// =======================

void adicionarComponente(Componente inventario[], int *qtd) {

    if(*qtd >= MAX) {
        printf("\nInventario cheio!\n");
        return;
    }

    printf("\nNome do componente: ");
    fgets(inventario[*qtd].nome,30,stdin);
    removerQuebraLinha(inventario[*qtd].nome);

    printf("Tipo do componente [Estrutural, Eletrônico, Energia]: ");
    fgets(inventario[*qtd].tipo,20,stdin);
    removerQuebraLinha(inventario[*qtd].tipo);

    printf("Quantidade: ");
    inventario[*qtd].quantidade = lerInteiro();

    printf("Prioridade (1 a 10): ");
    inventario[*qtd].prioridade = lerInteiro();

    (*qtd)++;

    printf("\nComponente adicionado!\n");
}

// =======================
// DESCARTAR COMPONENTE
// =======================

void descartarComponente(Componente inventario[], int *qtd) {

    if(*qtd == 0) {
        printf("\nInventario vazio.\n");
        return;
    }

    int i;

    mostrarComponentes(inventario, *qtd);

    printf("\nDigite o numero do componente para descartar: ");
    int pos = lerInteiro();

    if(pos < 1 || pos > *qtd) {
        printf("Posicao invalida.\n");
        return;
    }

    for(i = pos-1; i < *qtd-1; i++)
        inventario[i] = inventario[i+1];

    (*qtd)--;

    printf("\nComponente removido.\n");
}

// =======================
// MOSTRAR COMPONENTES
// =======================

void mostrarComponentes(Componente inventario[], int qtd) {

    if(qtd == 0) {
        printf("\nInventario vazio.\n");
        return;
    }

    printf("\n======= INVENTARIO =======\n");

    for(int i=0;i<qtd;i++) {

        printf("%d) Nome: %s | Tipo: %s | Quantidade: %d | Prioridade: %d\n",
               i+1,
               inventario[i].nome,
               inventario[i].tipo,
               inventario[i].quantidade,
               inventario[i].prioridade);
    }
    printf("\nPressione Enter para continuar...");
    getchar();
    printf("\n");
}

// =======================
// BUBBLE SORT (NOME)
// =======================

void bubbleSortNome(Componente inventario[], int qtd, int *comparacoes) {

    int i,j;
    Componente temp;

    *comparacoes = 0;

    for(i=0;i<qtd-1;i++) {

        for(j=0;j<qtd-1-i;j++) {

            (*comparacoes)++;

            if(strcmp(inventario[j].nome, inventario[j+1].nome) > 0) {

                temp = inventario[j];
                inventario[j] = inventario[j+1];
                inventario[j+1] = temp;
            }
        }
    }
}

// =======================
// INSERTION SORT (TIPO)
// =======================

void insertionSortTipo(Componente inventario[], int qtd, int *comparacoes) {

    int i,j;
    Componente chave;

    *comparacoes = 0;

    for(i=1;i<qtd;i++) {

        chave = inventario[i];
        j = i-1;

        while(j>=0 && strcmp(inventario[j].tipo, chave.tipo) > 0) {

            (*comparacoes)++;

            inventario[j+1] = inventario[j];
            j--;
        }

        inventario[j+1] = chave;
    }
}

// =======================
// SELECTION SORT (PRIORIDADE)
// =======================

void selectionSortPrioridade(Componente inventario[], int qtd, int *comparacoes) {

    int i,j,min;
    Componente temp;

    *comparacoes = 0;

    for(i=0;i<qtd-1;i++) {

        min = i;

        for(j=i+1;j<qtd;j++) {

            (*comparacoes)++;

            if(inventario[j].prioridade < inventario[min].prioridade)
                min = j;
        }

        temp = inventario[i];
        inventario[i] = inventario[min];
        inventario[min] = temp;
    }
}

// =======================
// BUSCA BINARIA
// =======================

int buscaBinariaPorNome(Componente inventario[], int qtd, char chave[], int *comparacoes) {

    int inicio = 0;
    int fim = qtd - 1;
    int meio;

    *comparacoes = 0;

    while(inicio <= fim) {

        meio = (inicio + fim)/2;

        (*comparacoes)++;

        int cmp = strcmp(chave, inventario[meio].nome);

        if(cmp == 0)
            return meio;

        else if(cmp > 0)
            inicio = meio + 1;

        else
            fim = meio - 1;
    }

    return -1;
}

// =======================
// ORGANIZAR INVENTARIO
// =======================

void organizarInventario(Componente inventario[], int qtd, int *ordenadoPorNome) {

    if(qtd == 0) {
        printf("\nInventario vazio.\n");
        return;
    }

    printf("\n1. Por nome (ordem alfabetica)\n");
    printf("2. Por tipo\n");
    printf("3. Por prioridade de montagem\n");
    printf("0. Cancelar\n");

    printf("\nEscolha: ");

    int opcao = lerInteiro();

    int comparacoes = 0;
    clock_t inicio,fim;

    switch(opcao) {

    case 1:

        inicio = clock();
        bubbleSortNome(inventario, qtd, &comparacoes);
        fim = clock();

        *ordenadoPorNome = 1;

        printf("\nOrdenado por nome.\n");
        break;

    case 2:

        inicio = clock();
        insertionSortTipo(inventario, qtd, &comparacoes);
        fim = clock();

        *ordenadoPorNome = 0;

        printf("\nOrdenado por tipo.\n");
        break;

    case 3:

        inicio = clock();
        selectionSortPrioridade(inventario, qtd, &comparacoes);
        fim = clock();

        *ordenadoPorNome = 0;

        printf("\nOrdenado por prioridade.\n");
        break;

    default:
        return;
    }

    double tempo = ((double)(fim-inicio))/CLOCKS_PER_SEC;

    printf("Comparacoes: %d\n", comparacoes);
    printf("Tempo: %f segundos\n", tempo);

    mostrarComponentes(inventario, qtd);
}
