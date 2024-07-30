#define MAXTAM 5

typedef struct jogo Jogo;
typedef struct listaDeJogos ListaDeJogos;

ListaDeJogos * criaListaDeJogosVazia();

int verificaListaDeJogosCheia(ListaDeJogos *lst);
int verificaListaDeJogosVazia(ListaDeJogos *lst);

int adicionaItemNaLista(ListaDeJogos *lst, int idJogo, char nome[], char estilo[], int idadeRecomendada, char linkAcesso[]);

void imprimeListaDeJogos(ListaDeJogos *lst);

void removeItem(ListaDeJogos *lst, int opc);

int buscaJogoPorNome(ListaDeJogos *lst);

void liberaListaDeJogos(ListaDeJogos *lst);

int buscaJogoPorID(ListaDeJogos *lst);

void imprimeUmJogo(ListaDeJogos *lst, int pos);

ListaDeJogos * criaNovaListaDeJogos(ListaDeJogos *lst, ListaDeJogos *lstNova, int idadeMinima);
