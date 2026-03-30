/*
Este exercício simula um sistema simples de gerenciamento de inventário, 
inspirado em mecânicas comuns de jogos de sobrevivência. Em termos abstratos, 
o problema consiste em organizar, armazenar e manipular informações relacionadas a 
objetos dentro de uma estrutura de dados limitada, representando a mochila inicial do jogador.

O objetivo é modelar itens do jogo como entidades estruturadas, 
armazená-los em uma coleção sequencial e permitir operações básicas de manipulação de dados, 
como inserção, remoção, listagem e busca. Esse tipo de problema é equivalente, em sistemas reais, a pequenos módulos de gestão de registros, 
como controle de produtos, cadastro de usuários ou gerenciamento de tarefas.

Com o intuito de tornar o sistema mais robusto e amigável, foram implementadas além do que foi pedido, funcionalidades adicionais essenciais:
- Aceitação de entradas de texto com espaços, utilizando fgets para ler strings, 
garantindo que nomes de itens e tipos possam conter múltiplas palavras.
- Comparação de strings sem diferenciar maiúsculas de minúsculas, usando strcasecmp, para facilitar a busca e remoção de itens.
- Centralização da lógica de busca em uma função auxiliar, seguindo o princípio DRY (Don't Repeat Yourself), 
para evitar repetição de código e facilitar a manutenção futura.
*/  

// Bibliotecas necessárias para o programa. Adicionei strings.h para usar strcasecmp, 
// que é uma função útil para comparação de strings sem diferenciar maiúsculas de minúsculas
// tornando a busca mais flexível e amigável ao usuário.
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>

// constante para definir o tamanho máximo da mochila
#define MAX_ITENS 10

// struct
struct Item {
    char nome[30];
    char tipo[20];
    int quantidade;
};

// variáveis globais
struct Item mochila[MAX_ITENS];
int totalItens = 0;

// protótipos
void inserirItem();
void removerItem();
void listarItens();
void buscarItem();
int buscarIndiceItem(char nome[]);

int main() {

    int opcao;

    // menu do sistema
    while(1) {
        printf("\n=-=-= INVENTARIO =-=-=\n");
        printf("1 - Inserir item\n");
        printf("2 - Remover item\n");
        printf("3 - Listar itens\n");
        printf("4 - Buscar item\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                inserirItem();
                break;

            case 2:
                removerItem();
                break;

            case 3:
                listarItens();
                break;

            case 4:
                buscarItem();
                break;

            case 0:
                return 0;

            default:
                printf("Opcao invalida.\n");
        }
    }
}

void inserirItem() {

    if (totalItens >= MAX_ITENS) {
        printf("\nA mochila esta cheia. Nao e possivel adicionar mais itens.\n");
        return;
    }

    printf("\n=== Inserir novo item ===\n");

    printf("Nome do item: ");
    getchar();  
    fgets(mochila[totalItens].nome, 30, stdin);
    mochila[totalItens].nome[strcspn(mochila[totalItens].nome, "\n")] = 0;

    printf("Tipo do item (arma, municao, cura, etc): ");
    getchar();
    fgets(mochila[totalItens].tipo, 20, stdin);
    mochila[totalItens].tipo[strcspn(mochila[totalItens].tipo, "\n")] = 0;

    printf("Quantidade: ");
    scanf("%d", &mochila[totalItens].quantidade);

    totalItens++;

    printf("\nItem adicionado com sucesso!\n");

    listarItens();
}

void removerItem() {

    char nomeBusca[30];
    int j;

    printf("\n=== Remover item ===\n");

    printf("Digite o nome do item a remover: ");
    getchar();
    fgets(nomeBusca, 30, stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = 0;

    int indice = buscarIndiceItem(nomeBusca);

    if (indice == -1) {

        printf("\nItem nao encontrado.\n");
        return;
    }

    for (j = indice; j < totalItens - 1; j++) {

        mochila[j] = mochila[j + 1];
    }

    totalItens--;

    printf("\nItem removido com sucesso!\n");

    listarItens();
}

void listarItens() {

    int i;

    printf("\n=== Itens na mochila ===\n");

    if (totalItens == 0) {
        printf("A mochila esta vazia.\n");
        return;
    }

    for (i = 0; i < totalItens; i++) {

        printf("\nItem %d\n", i + 1);
        printf("Nome: %s\n", mochila[i].nome);
        printf("Tipo: %s\n", mochila[i].tipo);
        printf("Quantidade: %d\n", mochila[i].quantidade);
    }
}

void buscarItem() {

    char nomeBusca[30];

    printf("\n=== Buscar item ===\n");

    printf("Digite o nome do item: ");
    getchar();  
    fgets(nomeBusca, 30, stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = 0;

    int indice = buscarIndiceItem(nomeBusca);

    if (indice != -1) {

        printf("\nItem encontrado:\n");
        printf("Nome: %s\n", mochila[indice].nome);
        printf("Tipo: %s\n", mochila[indice].tipo);
        printf("Quantidade: %d\n", mochila[indice].quantidade);

    } else {

        printf("\nItem nao encontrado na mochila.\n");
    }
}

// Função auxiliar para buscar o índice de um item pelo nome
// Essa é uma decisão elegante que evita repetição de código em várias funções (remoção, busca, etc)
// Princípio DRY (Don't Repeat Yourself) - ao centralizar a lógica de busca em uma função, o código fica mais limpo, fácil de manter
// e facilita a reutilização para casos de eventuais futuras funcionalidades

int buscarIndiceItem(char nome[]) {

    int i;

    for (i = 0; i < totalItens; i++) {

        if (strcasecmp(mochila[i].nome, nome) == 0) {
            return i;
        }
    }

    return -1;
}
