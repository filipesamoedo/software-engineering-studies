/*
===============================================================================
Inventory System using Linked List
Description
-----------
This program simulates an inventory/backpack system similar to those
found in games. The goal of this implementation is to analyze the behavior
of a dynamic data structure based on linked lists and compare it with the
array-based implementation.

The system supports the following operations:

- Insert new item
- Remove item by name
- List all items
- Sequential search

Data Structure: Linked List
---------------------------
In this implementation, items are stored in a singly linked list.
Each node contains the item data and a pointer to the next node
in the structure.

Advantages
----------
- Dynamic memory allocation.
- Flexible structure that grows as new items are added.
- No need to define maximum capacity beforehand.
- Memory is allocated only when needed.

Memory Allocation Characteristics
---------------------------------
Linked lists allocate memory dynamically using pointers.

Advantages:
- Memory is used only when new items are inserted.
- No predefined limit for the number of elements (limited only by system memory).

Disadvantages:
- Slower access to elements because traversal must start from the beginning.
- No direct index-based access like arrays.

Search Characteristics
----------------------
In linked lists, only sequential search is possible.

Binary search cannot be applied because:
- Linked lists do not allow direct access by index.
- Elements must be traversed one by one using pointers.

This means the search complexity remains:

Sequential Search → O(n)

As the list grows, the search time increases linearly.

Conclusion
----------
Linked lists provide greater flexibility and dynamic memory management,
making them suitable for applications where the number of elements is
unpredictable or constantly changing.

However, they sacrifice fast indexed access and do not support
efficient algorithms like binary search, which are possible
in array-based structures.

This implementation highlights the trade-offs between flexibility
(dynamic allocation) and performance (fast indexed access).

===============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
STRUCT NO
Representa um nó da lista encadeada
Cada nó possui:
- os dados do item
- um ponteiro para o próximo nó
===========================================================
*/
typedef struct No {
    Item dados;
    struct No *proximo;
} No;


/*
===========================================================
VARIÁVEIS GLOBAIS
===========================================================
*/

// ponteiro para o primeiro elemento da lista
No *inicio = NULL;

// contador de comparações da busca
int comparacoesSequencial = 0;


/*
===========================================================
PROTÓTIPOS DAS FUNÇÕES
===========================================================
*/
void inserirItemLista();
void listarItensLista();
void removerItemLista();
void buscarSequencialLista();


/*
===========================================================
MENU PRINCIPAL
===========================================================
*/
int main() {

    int opcao;

    do {

        printf("\n====== SISTEMA DE MOCHILA (LISTA ENCADEADA) ======\n");
        printf("1 - Inserir item\n");
        printf("2 - Remover item\n");
        printf("3 - Listar itens\n");
        printf("4 - Buscar item (Sequencial)\n");
        printf("0 - Sair\n");

        printf("\nEscolha uma opção: ");

        if (scanf("%d", &opcao) != 1) {

            printf("\nEntrada inválida! Digite apenas números.\n");

            while (getchar() != '\n');

            opcao = -1;
        }

        switch (opcao) {

            case 1:
                inserirItemLista();
                break;

            case 2:
                removerItemLista();
                break;

            case 3:
                listarItensLista();
                break;

            case 4:
                buscarSequencialLista();
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
FUNÇÃO: inserirItemLista
Insere um novo item no início da lista
===========================================================
*/
void inserirItemLista() {

    // aloca memória para um novo nó
    No *novo = (No *) malloc(sizeof(No));

    if (novo == NULL) {
        printf("\nErro de memória!\n");
        return;
    }

    printf("\nNome do item: ");
    scanf("%s", novo->dados.nome);

    printf("Tipo do item: ");
    scanf("%s", novo->dados.tipo);

    printf("Quantidade: ");
    scanf("%d", &novo->dados.quantidade);

    /*
    Ligação do novo nó na lista

    novo -> aponta para o antigo início
    início passa a ser o novo
    */

    novo->proximo = inicio;
    inicio = novo;

    printf("\nItem inserido com sucesso!\n");
}


/*
===========================================================
FUNÇÃO: listarItensLista
Percorre toda a lista exibindo os itens
===========================================================
*/
void listarItensLista() {

    if (inicio == NULL) {
        printf("\nA mochila está vazia.\n");
        return;
    }

    No *atual = inicio;
    int contador = 1;

    printf("\n===== ITENS DA MOCHILA =====\n");

    /*
    Percorre a lista até chegar em NULL
    */
    while (atual != NULL) {

        printf("\nItem %d\n", contador);
        printf("Nome: %s\n", atual->dados.nome);
        printf("Tipo: %s\n", atual->dados.tipo);
        printf("Quantidade: %d\n", atual->dados.quantidade);

        atual = atual->proximo;
        contador++;
    }
}


/*
===========================================================
FUNÇÃO: removerItemLista
Remove um item pelo nome
===========================================================
*/
void removerItemLista() {

    char nome[30];

    printf("\nDigite o nome do item para remover: ");
    scanf("%s", nome);

    No *atual = inicio;
    No *anterior = NULL;

    while (atual != NULL) {

        if (strcmp(atual->dados.nome, nome) == 0) {

            /*
            Caso 1: remover o primeiro elemento
            */
            if (anterior == NULL) {
                inicio = atual->proximo;
            }

            /*
            Caso 2: remover elemento do meio ou final
            */
            else {
                anterior->proximo = atual->proximo;
            }

            free(atual);

            printf("\nItem removido com sucesso!\n");
            return;
        }

        anterior = atual;
        atual = atual->proximo;
    }

    printf("\nItem não encontrado.\n");
}


/*
===========================================================
FUNÇÃO: buscarSequencialLista
Busca item percorrendo a lista
===========================================================
*/
void buscarSequencialLista() {

    char nome[30];

    comparacoesSequencial = 0;

    printf("\nDigite o nome do item para buscar: ");
    scanf("%s", nome);

    No *atual = inicio;

    while (atual != NULL) {

        comparacoesSequencial++;

        if (strcmp(atual->dados.nome, nome) == 0) {

            printf("\nItem encontrado!\n");
            printf("Nome: %s\n", atual->dados.nome);
            printf("Tipo: %s\n", atual->dados.tipo);
            printf("Quantidade: %d\n", atual->dados.quantidade);

            printf("Comparações realizadas: %d\n", comparacoesSequencial);

            return;
        }

        atual = atual->proximo;
    }

    printf("\nItem não encontrado.\n");
    printf("Comparações realizadas: %d\n", comparacoesSequencial);
}
