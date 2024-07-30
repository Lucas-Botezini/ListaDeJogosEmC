#include <stdio.h>
#include <stdlib.h>
#include "itensLista.h"

struct jogo {
    int idJogo;
    char nome[30];
    char estilo[15];
    int idadeRecomendada;
    char linkAcesso[50];
};

struct listaDeJogos {
    Jogo jogo[MAXTAM];
    int ultimo;
};

ListaDeJogos * criaListaDeJogosVazia() {
    ListaDeJogos *lst = malloc(sizeof(ListaDeJogos));
    lst->ultimo = -1;
    return lst;
}

// retorna 1 se a ListaDeJogos está cheio e 0 se não está
int verificaListaDeJogosCheia(ListaDeJogos *lst) {
    return (lst->ultimo == MAXTAM - 1);
}

// //retorna 1 se a ListaDeJogos esta vazia ou 0 se não estiver vazia
int verificaListaDeJogosVazia(ListaDeJogos *lst) {
    return (lst->ultimo == -1);
}

int adicionaItemNaLista(ListaDeJogos *lst, int idJogo, char nome[], char estilo[], int idadeRecomendada, char linkAcesso[]) {
    if (verificaListaDeJogosCheia(lst)) {
        printf("\nErro a Lista esta cheia");
        return;
    }

    for (int i=0; i <= lst->ultimo; i++) {
        if (idJogo == lst->jogo[i].idJogo) {
            return 1;
        }
    }

    Jogo novoJogo;
    novoJogo.idJogo = idJogo;
    strcpy(novoJogo.nome, nome);
    strcpy(novoJogo.estilo, estilo);
    strcpy(novoJogo.linkAcesso, linkAcesso);
    novoJogo.idadeRecomendada = idadeRecomendada;

    lst->ultimo++;
    lst->jogo[lst->ultimo] = novoJogo;
    // strcpy(lst->jogo->estilo, estilo);
    // lst->jogo->estilo = estilo;
    return 3;
}

void imprimeListaDeJogos(ListaDeJogos *lst) {
    for (int i = 0; i <= lst->ultimo; i++) {
        printf("\n=====================================================\n");
        printf("ID do jogo: %d\n", lst->jogo[i].idJogo);
        printf("Nome do Jogo: %s\n", lst->jogo[i].nome);
        printf("Estilo do Jogo: %s\n", lst->jogo[i].estilo);
        printf("Idade recomendada do Jogo: %d\n", lst->jogo[i].idadeRecomendada);
        printf("Link de acesso ao Jogo: %s\n", lst->jogo[i].linkAcesso);
    }
}

// remove um item qualquer da ListaDeJogos
void removeItem(ListaDeJogos *lst, int opc) {

    int pos;

    switch (opc) {
    case 1:
    // "1 ----> Excluir item procurando pelo id do jogo"
        pos = buscaJogoPorID(lst);
        break;
    case 2:
    // "2 ----> Excluir item procurando pelo nome do jogo"
        pos = buscaJogoPorNome(lst);
        break;
    case 3:
    // "3 ----> Excluir ultimo item adicionado"
        pos = lst->ultimo;
        break;
    default:
        pos = -1;
        break;
    }
    if (pos == -1) {
        printf("\nO jogo nao esta na Lista");
        return;
    }

    for (int i = pos; i <= lst->ultimo; i++) {
        lst->jogo[i] = lst->jogo[i+1];
    }
    lst->ultimo--;
    printf("\nExlcuido com Sucesso!");
}

int buscaJogoPorNome(ListaDeJogos *lst) {
    char nome[30];

    setbuf(stdin, NULL);
    printf("Informe o nome do jogo para procurar: ");
    gets(nome);

    for (int i = 0; i <= lst->ultimo; i++) {
        if (strcmp(nome, lst->jogo[i].nome) == 0) {
            return i;

        }
    }
    return -1;
}

int buscaJogoPorID(ListaDeJogos *lst) {
    int id;
    setbuf(stdin, NULL);
    printf("Informe o id do jogo para procurar: ");
    scanf("%d", &id);

    for (int i = 0; i <= lst->ultimo; i++) {
        if (id == lst->jogo[i].idJogo) {
            return i;
        }
    }    
    return -1;
}

//libera ListaDeJogos da memoria

void liberaListaDeJogos(ListaDeJogos *lst) {
    free(lst);
}

void imprimeUmJogo(ListaDeJogos *lst, int pos) {
    printf("\n=====================================================\n");
    printf("ID do jogo: %d\n", lst->jogo[pos].idJogo);
    printf("Nome do Jogo: %s\n", lst->jogo[pos].nome);
    printf("Estilo do Jogo: %s\n", lst->jogo[pos].estilo);
    printf("Idade recomendada do Jogo: %d\n", lst->jogo[pos].idadeRecomendada);
    printf("Link de acesso ao Jogo: %s\n", lst->jogo[pos].linkAcesso);
    return;
}

ListaDeJogos * criaNovaListaDeJogos(ListaDeJogos *lst, ListaDeJogos *lstNova, int idadeMinima) {

    lstNova = criaListaDeJogosVazia();

    for (int i = 0; i <= lst->ultimo; i++) {
        if (lst->jogo[i].idadeRecomendada >= idadeMinima) {
            lstNova->ultimo++; 
            lstNova->jogo[lstNova->ultimo] = lst->jogo[i];
        }
    }
    return lstNova;

}