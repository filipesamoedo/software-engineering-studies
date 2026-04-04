/*
===============================================================================
Inventory System using Array (Sequential List)

Description
-----------
This program simulates an inventory/backpack system commonly found in games.
The objective of this exercise is to implement and analyze a data structure
based on arrays (sequential lists) and evaluate its behavior in common
operations such as insertion, removal, listing and search.

The system allows the following operations:

- Insert new item
- Remove item by name
- List all items
- Sequential search
- Sorting items by name
- Binary search (after sorting)

Data Structure: Array
---------------------
In this implementation, items are stored in a fixed-size array. This approach
provides fast direct access to elements using their index.

Advantages
----------
- Fast access to elements (O(1)) using index.
- Supports efficient algorithms like Binary Search.
- Simple memory layout and cache-friendly.

Search Methods Implemented
--------------------------
1. Sequential Search
   - Checks items one by one.
   - Worst case: O(n)
   - May require scanning the entire array.

2. Binary Search
   - Only possible after sorting the array.
   - Divides the search space in half each iteration.
   - Complexity: O(log n)
   - Requires significantly fewer comparisons than sequential search.

Important Note
--------------
Binary search only works if the array is sorted. In this program the
items are sorted by name using the Bubble Sort algorithm before
executing the binary search.

Memory Allocation Characteristics
---------------------------------
Arrays require memory to be allocated beforehand using a fixed size.

Advantages:
- Predictable memory usage.
- Fast access by index.

Disadvantages:
- If the array is not fully used, memory remains allocated but unused.
- If the maximum capacity is reached, new items cannot be added
  without resizing the array.

Conclusion
----------
Arrays are efficient when:
- Fast indexed access is required.
- The maximum number of elements is known in advance.
- Binary search can be applied after sorting.

However, arrays are less flexible when dealing with dynamic data sizes,
which motivates the comparison with linked lists in the second
implementation of this exercise.

-------------------------------------------------------------------------------
Extra: Validação de Entrada de Dados

A linguagem C possui um comportamento conhecido no uso da função scanf
quando ocorre entrada de dados incompatível com o formato esperado.

Neste caso, o menu espera um número inteiro (%d). Caso o usuário digite
um valor não numérico (por exemplo: letras ou símbolos), o scanf falha
na leitura e não consome o caractere inválido presente no buffer de entrada.

Isso faz com que o programa entre em um loop infinito, pois a próxima
leitura tenta processar novamente o mesmo caractere inválido.

Para evitar esse problema clássico da linguagem C, implementei
uma verificação do valor de retorno da função scanf. Caso a leitura
não seja bem-sucedida, o programa:

1. Exibe uma mensagem de erro ao usuário.
2. Limpa o buffer de entrada utilizando getchar() até encontrar '\n'.
3. Define um valor inválido para a variável de controle do menu.

Essa abordagem garante maior robustez na interação com o usuário
e impede que o programa fique preso em loops infinitos devido
a entradas inválidas.

===============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITENS 100

/*
===========================================================
STRUCT ITEM
Representa um item dentro da mochila do jogo
===========================================================
*/
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;


/*
===========================================================
VARIÁVEIS GLOBAIS
===========================================================
*/

// vetor que representa a mochila
Item mochila[MAX_ITENS];

// quantidade atual de itens no vetor
int totalItens = 0;

// contadores de comparações das buscas
int comparacoesSequencial = 0;
int comparacoesBinaria = 0;


/*
===========================================================
PROTÓTIPOS DAS FUNÇÕES
===========================================================
*/
void inserirItemVetor();
void listarItens();
void removerItemVetor();
void buscarSequencialVetor();
void ordenarVetor();
void buscaBinariaVetor();


/*
===========================================================
MENU PRINCIPAL
Permite testar todas as funcionalidades
===========================================================
*/
int main() {

    int opcao;

    do {

        printf("\n====== SISTEMA DE MOCHILA (VETOR) ======\n");
        printf("1 - Inserir item\n");
        printf("2 - Remover item\n");
        printf("3 - Listar itens\n");
        printf("4 - Buscar item (Sequencial)\n");
        printf("5 - Ordenar itens\n");
        printf("6 - Buscar item (Binária)\n");
        printf("0 - Sair\n");

        printf("\nEscolha uma opção: ");
        if (scanf("%d", &opcao) != 1) {

            printf("\nEntrada inválida! Digite apenas números.\n");

            // limpa o buffer
            while (getchar() != '\n');

            opcao = -1;
        }

        switch (opcao) {

            case 1:
                inserirItemVetor();
                break;

            case 2:
                removerItemVetor();
                break;

            case 3:
                listarItens();
                break;

            case 4:
                buscarSequencialVetor();
                break;

            case 5:
                ordenarVetor();
                break;

            case 6:
                buscaBinariaVetor();
                break;

            case 0:
                printf("\nEncerrando...\n");
                break;

            default:
                printf("\nOpção inválida!\n");
        }

    } while (opcao != 0);

    return 0;
}

/*
===========================================================
FUNÇÃO: inserirItemVetor
Insere um novo item na mochila (no final do vetor)
===========================================================
*/
void inserirItemVetor() {

    if (totalItens >= MAX_ITENS) {
        printf("\nMochila cheia!\n");
        return;
    }

    Item novo;

    printf("\nNome do item: ");
    scanf("%s", novo.nome);

    printf("Tipo do item: ");
    scanf("%s", novo.tipo);

    printf("Quantidade: ");
    scanf("%d", &novo.quantidade);

    // adiciona o item na próxima posição disponível
    mochila[totalItens] = novo;

    totalItens++;

    printf("\nItem inserido com sucesso!\n");
}



/*
===========================================================
FUNÇÃO: listarItens
Exibe todos os itens da mochila
===========================================================
*/
void listarItens() {

    if (totalItens == 0) {
        printf("\nA mochila está vazia.\n");
        return;
    }

    printf("\n===== ITENS DA MOCHILA =====\n");

    for (int i = 0; i < totalItens; i++) {

        printf("\nItem %d\n", i + 1);
        printf("Nome: %s\n", mochila[i].nome);
        printf("Tipo: %s\n", mochila[i].tipo);
        printf("Quantidade: %d\n", mochila[i].quantidade);
    }
}



/*
===========================================================
FUNÇÃO: removerItemVetor
Remove um item pelo nome
===========================================================
*/
void removerItemVetor() {

    char nome[30];
    int encontrado = -1;

    printf("\nDigite o nome do item para remover: ");
    scanf("%s", nome);

    // procura o item
    for (int i = 0; i < totalItens; i++) {

        if (strcmp(mochila[i].nome, nome) == 0) {
            encontrado = i;
            break;
        }
    }

    if (encontrado == -1) {
        printf("\nItem não encontrado.\n");
        return;
    }

    /*
    Remove deslocando todos os itens
    uma posição para trás
    */

    for (int i = encontrado; i < totalItens - 1; i++) {
        mochila[i] = mochila[i + 1];
    }

    totalItens--;

    printf("\nItem removido com sucesso!\n");
}



/*
===========================================================
FUNÇÃO: buscarSequencialVetor
Busca item pelo nome utilizando busca sequencial
===========================================================
*/
void buscarSequencialVetor() {

    char nome[30];

    comparacoesSequencial = 0;

    printf("\nDigite o nome do item para buscar: ");
    scanf("%s", nome);

    for (int i = 0; i < totalItens; i++) {

        comparacoesSequencial++;

        if (strcmp(mochila[i].nome, nome) == 0) {

            printf("\nItem encontrado!\n");
            printf("Nome: %s\n", mochila[i].nome);
            printf("Tipo: %s\n", mochila[i].tipo);
            printf("Quantidade: %d\n", mochila[i].quantidade);

            printf("Comparações realizadas: %d\n", comparacoesSequencial);

            return;
        }
    }

    printf("\nItem não encontrado.\n");
    printf("Comparações realizadas: %d\n", comparacoesSequencial);
}



/*
===========================================================
FUNÇÃO: ordenarVetor
Ordena os itens pelo nome utilizando Bubble Sort
===========================================================
*/
void ordenarVetor() {

    Item temp;

    for (int i = 0; i < totalItens - 1; i++) {

        for (int j = 0; j < totalItens - i - 1; j++) {

            if (strcmp(mochila[j].nome, mochila[j + 1].nome) > 0) {

                temp = mochila[j];
                mochila[j] = mochila[j + 1];
                mochila[j + 1] = temp;
            }
        }
    }

    printf("\nItens ordenados por nome!\n");
}



/*
===========================================================
FUNÇÃO: buscaBinariaVetor
Realiza busca binária no vetor (precisa estar ordenado)
===========================================================
*/
void buscaBinariaVetor() {

    char nome[30];

    int inicio = 0;
    int fim = totalItens - 1;

    comparacoesBinaria = 0;

    printf("\nDigite o nome do item para busca binária: ");
    scanf("%s", nome);

    while (inicio <= fim) {

        int meio = (inicio + fim) / 2;

        comparacoesBinaria++;

        int resultado = strcmp(mochila[meio].nome, nome);

        if (resultado == 0) {

            printf("\nItem encontrado!\n");
            printf("Nome: %s\n", mochila[meio].nome);
            printf("Tipo: %s\n", mochila[meio].tipo);
            printf("Quantidade: %d\n", mochila[meio].quantidade);

            printf("Comparações realizadas: %d\n", comparacoesBinaria);

            return;
        }

        if (resultado < 0)
            inicio = meio + 1;
        else
            fim = meio - 1;
    }

    printf("\nItem não encontrado.\n");
    printf("Comparações realizadas: %d\n", comparacoesBinaria);
}
