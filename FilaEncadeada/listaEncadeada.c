#include "listaEncadeada.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

Node *newNode(){ //cria um ponteiro para tipo Node, aloca ela dinamicamente via malloc, retorna NULL caso não haja memória, caso contrario retorna o ponteiro
    Node *n;
    // Se não conseguir alocar, retorna NULL
    n = malloc(sizeof(Node));
    return n;
}

void deleteNode(Node *n){ // recebe um ponteiro para nó e libera o mesmo, caso não seja igual a NULL
    if(n != NULL){
        free(n);
    }
}

Lista *criarL(){ // cria um ponteiro para Lista, e o aloca via malloc depois retorna o mesmo, ou    NULL caso não possa alocar
    Lista *L;
    // Caso não possa alocar, retorna NULL
    L = malloc(sizeof(Lista));
    if(L != NULL){
        L->head = NULL; // Lista vazia
    }
    return L;
}
bool cheia(Lista *L){ /* função feita somente para cumprir com os padrões do TAD, pois nesta 
                        *versão a Lista nunca ficará cheia. Porém caso queira ser feito poderia ser *limitada a quantidade de elementos por meio desta função*/
                       
    return false; // enquanto ouver memória a Lista jamais estará cheia
}

bool vazia(Lista *L){ // a lista só estará vazia, se a cabeça apontar para NULL
    if(L->head == NULL){
        return true;
    }
    return false;
}

int tam(Lista *L){ // percorre uma lista, usando um nó aux, e pra cada "passagem" de nó, incrementa o contador, no momento que o aux for igual a NULL (final da lista), retorna o contador
    int contador;
    Node *aux = newNode();
    aux = L;
    while(aux != NULL){
        contador++;
        aux = aux->next;
    }
    return contador;
}

bool inserirInicio(Lista *L, char x){ // insere um nó no inicio da lista
    if (L == NULL || cheia(L) == true){
        return false; // não conseguiu alocar a lista, ou a lista está cheia
    }
    Node *aux = newNode();
    if(aux == NULL){
        return false; // não conseguiu alocar um novo nó
    }
    aux->info = x; // nó recebe o valor de x
    aux->next = L->head; // next agora aponta para a posição da cabeça
    L->head = aux; // cabeça agora aponta para o nó
}

bool inserirMeio(Lista *L, char x){ // insere um nó no meio da fila
    if(L == NULL || cheia(L) == true){
        return false; // não alocou a lista, ou a lista já está cheia
    }
    Node *aux = newNode(); // aloca um novo nó
    if(aux == NULL){
        return false; // nó não alocado
    }
    aux->info = x; // insere o valor de x no campo info
    int meio = (int)(tam(L) / 2); // encontra a quantidade necessaria para percorrer até o meio da lista
    Node *p = newNode(); // declara um nó auxiliar
    p = L->head;
    for(int i = 1; i <= meio; i++){ 
        p = p->next; // percorre a lista até o meio
    }
    aux->next = p->next; // novo elemento aponta para o proximo elemento a partir do meio
    p->next = aux; // antigo meio da lista aponta para o novo meio
    return true;
}

bool inserirFim(Lista *L, char x){
    if(L == NULL || cheia(L) == true){
        return false; // lista não alocada, ou a lista está cheia
    }
    Node *aux = newNode(); // cria um novo nó
    if(aux == NULL){
        return false; // não conseguiu alocar o nó
    }
    aux->info = x;
    Node *P = newNode(); // cria um nó auxiliar
    P = L->head;
    for(int i = 1; i <= tam(L); i++){ 
        P = P->next; // percorre a lista até o final
    }
    aux->next = P->next; // novo nó agora aponta para NULL
    P->next = aux; // antigo nó final agora aponta para o novo nó inserido
    return true;
}

bool removeInicio(Lista *L, char *x){
    if(L == NULL || vazia(L) == true){
        return false; // lista não alocada, ou a lista já está vazia
    }
    Node *Paux = newNode(); // cria um nó auxiliar
    Paux = L->head;
    L->head = L->head->next; // a cabeça agora aponta para o segundo elemento da lista (novo primeiro elemento)
    x = Paux->info; // x recebo o info do ultimo elemento
    deleteNode(Paux); // libera o antigo primeiro elemento da lista
    return true;
}

bool removeMeio(Lista *L, char *x){
    if(L == NULL || vazia(L) == true){
        return false; // lista não alocada, ou vazia
    }
    Node *Paux1 = newNode(); // cria um nó auxiliar
    Node *Paux2 = newNode(); // cria um segundo nó auxiliar
    Paux1 = L->head;
    Paux2 = L->head;
    int meio = (int)(tam(L) / 2);
    for(int i = 1; i <= meio; i++){
        Paux1 = Paux1->next; // percorre até o meio
    }
    for(int i = 1; i <= (meio - 1); i++){
        Paux2 = Paux2->next; // percorre até uma posição antes do meio
    }
    Paux2->next = Paux2->next->next; // faz o elemento anterior ao meio apontar para o elemento posterior ao meio
    x = Paux1->info; // x recebe o valor do ulitmo elemento
    deleteNode(Paux1); // libera o elemento do meio da memória
    return true;
}

bool removeFim(Lista *L, char *x){
    if(L == NULL || vazia(L) == true){
        return false; // lista não alocada, ou já está vazia
        Node *Paux1 = newNode();
        Node *Paux2 = newNode();
        Paux1 = L->head;
        Paux2 = L->head;
        for(int i = 1; i <= tam(L); i++){
            Paux1 = Paux1->next; // percorre até o ultimo elemento da lista
        }
        for(int i = 1; i <= (tam(L) - 1); i++){
            Paux2 = Paux2->next; // percorre até o penultimo elemento da lista
        }
        Paux2->next = NULL; // faz o novo ultimo elemento apontar para o NULL
        x = Paux1->info; // da a x o valor do antigo ultimo elemento
        deleteNode(Paux1); // libera o antigo ultimo elemento da memória
        return true;
    }
}

void destruirL(Lista *L){ // por conveniência, caso não seja vazia, será feita a remoção pelo inicio
    char x; // auxiliar caso a pilha não seja vazia
    while(vazia(L) == false){
        removeInicio(L, &x);
    }
    free(L);
}