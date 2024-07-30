#include <stdio.h>
#include <stdlib.h>
#include "itensLista.h"

int menuDeOpcoes() {

    printf("\n===============================================\n");
    printf("1 ----> Inserir novo item no conjunto\n");
    printf("2 ----> Excluir item\n");
    printf("3 ----> Buscar item\n");
    printf("4 ----> Imprimir todos os itens\n");
    printf("5 ----> Criar um novo conjunto\n");
    printf("6 ----> Sair do programa\n");

    int opc;
    scanf("%d", &opc);

    return opc;
}

int menuExclusao() {
    printf("\n===============================================\n");
    printf("1 ----> Excluir item procurando pelo id do jogo\n");
    printf("2 ----> Excluir item procurando pelo nome do jogo\n");
    printf("3 ----> Excluir ultimo item adicionado\n");
    printf("Digite algum outro numero para voltar ao menu inicial: \n");
    int opc;
    scanf("%d", &opc);

    return opc;

}

int menuBuscaJogo() {
    printf("\n===============================================\n");
    printf("1 ----> Procurar item pelo id do jogo\n");
    printf("2 ----> Procurar pelo nome do jogo\n");
    printf("Digite algum outro numero para voltar ao menu inicial: \n");

    int opc;
    scanf("%d", &opc);

    return opc;
    
}

int cadastraItems(ListaDeJogos *lst) {

    int idJogo;
    char nome[40];
    char estilo[30];
    int idadeRecomendada;
    char linkAcesso[50];
    int opc;

    printf("\nInforme o id do jogo (somente numeros inteiros): ");
    scanf("%d", &idJogo);

    setbuf(stdin, NULL);
    printf("\nInforme o nome do jogo: ");
    gets(nome);

    setbuf(stdin, NULL);
    printf("\nInforme o estilo do jogo: ");
    gets(estilo);

    printf("\nInforme a idade recomendada do jogo: ");
    scanf("%d", &idadeRecomendada);

    setbuf(stdin, NULL);
    printf("\nInforme o link para acesso ao jogo: ");
    gets(linkAcesso);

    opc = adicionaItemNaLista(lst, idJogo, nome, estilo, idadeRecomendada, linkAcesso);

    return opc;
}

int main() {

    ListaDeJogos *lst;

    lst = criaListaDeJogosVazia();

    printf("\nCriando lista vazia\n");

    int opc;

    do
    {
        opc = menuDeOpcoes();

        switch (opc) {
        case 1: // 1 ----> Inserir novo item no conjunto\n
            opc = cadastraItems(lst);

            if(opc == 1) {
                printf("\nO ID do jogo ja existe na lista");
            }
            else {
                printf("\nJogo adicionado com sucesso");
            }
            break;

        case 2: // 2 ----> Excluir item
            removeItem(lst, menuExclusao());
            break;

        case 3: // 3 ----> Buscar item
            opc = menuBuscaJogo();
            int pos;
            switch (opc) {
            case 1:
                // printf("1 ----> Procurar item pelo id do jogo\n");
                pos = buscaJogoPorID(lst);
                if (pos == -1) {
                    printf("\nO jogo nao esta na Lista");
                    break;
                }
                else {
                    printf("\nO jogo buscado esta na posicao %d", pos);
                    imprimeUmJogo(lst, pos);
                } 
                break;
            case 2:
                // printf("2 ----> Procurar pelo nome do jogo\n");
                pos = buscaJogoPorNome(lst);
                if (pos == -1) {
                    printf("\nO jogo nao esta na Lista");
                    break;
                }
                else {
                    printf("\nO jogo buscado esta na posicao %d", pos);
                    imprimeUmJogo(lst, pos);
                } 
                break;
            default:
                break;
            }

            break;
        case 4: // 4 ----> Imprimir todos os itens
            imprimeListaDeJogos(lst);
            break;

        case 5: // 5 ----> Criar um novo conjunto
            ListaDeJogos *lstNova;
            int idadeMinima;
            printf("\nInforme a idade minima para a proxima lista de jogos: ");
            scanf("%d", &idadeMinima);

            lstNova = criaNovaListaDeJogos(lst, lstNova, idadeMinima);
            imprimeListaDeJogos(lstNova);
            break;

        case 6: // 6 ----> Sair do programa
            printf("\nObrigado por testar :) !");
            liberaListaDeJogos(lst);
            break;
        default:
            printf("\nNumero informado esta incorreto!");
            break;
        }

    } while (opc != 6);

    return 0;
}

