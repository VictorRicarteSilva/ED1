#ifndef listaOrdenada_h_included
#define listaOrdenada_h_included

typedef struct node
{
    int info;
    struct node *next;
}Node;

typedef struct listaOrdenada
{
    Node *head;
}Lista;

Node *newnode();
void deleteNode(Node *n);
Lista *criaL();
void cheia(Lista *L);
void vazia(Lista *L);

#endif // listaOrdenada_h_included