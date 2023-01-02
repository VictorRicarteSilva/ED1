#ifndef LISTAENCADEADA_H_INCLUDED
#define LISTAENCADEADA_H_INCLUDED

typedef struct node // definição do nó da minha lista
{
    char info;
    struct node *next;
    
}Node;

// definição da lista em si
typedef struct lista
{
    Node *head;
}Lista;

Node *newNode(); // cria um novo nó
void deleteNode(Node *n); // libera o nó da memória
Lista *criarL(); // cria uma lista
bool cheia(Lista *L); // verifica se a lista está cheia
bool vazia(Lista *L); // verifica se a lista está vazia
int tam(Lista *L); // verifica o tamanho da lista
bool inserirInicio(Lista *L, char x); // insere um elemento no inicio da lista, retorna true se deu certo, false caso contrario
bool inserirMeio(Lista *L, char x); // insere um elemento no meio da lista, retorna true se deu certo, false caso contrario
bool inserirFim(Lista *L, char x); // insere um elemento no final da lista, retorna true se deu certo, false caso contrario
bool removeInicio(Lista *L, char *x); // remove um elemento no inicio da lista, retorna true se deu certo, false cado contrario
bool removeMeio(Lista *L, char *x); // remove um elemento no meio da lista, retorna true se deu certo, false cado contrario
bool removeFim(Lista *L, char *x); // remove um elemento no final da lista, retorna true se deu certo, false cado contrario
void destruirL(Lista *L); // libera a lista da memória


#endif // LISTAENCADEADA_H_INCLUDED