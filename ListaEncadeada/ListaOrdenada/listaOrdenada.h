//
// Created by victor on 06/01/2023.
//
#include <stdbool.h>
#include <stdlib.h>
#ifndef LISTAORDENADA_LISTAORDENADA_H
#define LISTAORDENADA_LISTAORDENADA_H

/// Define o tipo de dado Node
typedef struct node{
    int info;
    struct node *next;
}Node;

/// Define o tipo de dado Lista
typedef struct lista{
    Node *head;
}Lista;
/// Cria um novo nó
Node *newNode();
/// Delete um nó, liberando-o da memória
void deleteNode(Node *n);
/// Cria uma nova Lista
Lista *criaL();
/// verifica se um numero esta na lista
bool estaNaLista(Lista *l, int numero);
/// verifica se a lista esta cheia
bool cheia(Lista l);
/// verifica se a lista esta vazia
bool vazia(Lista l);
/// insere um elemento de forma crescente na lista
bool insereOrdenado(Lista *l, int numero);
/// remove um elemento da lista
bool remove(Lista *l, int *numero);
/// deleta uma lista
bool destroiL(Lista *l);
#endif //LISTAORDENADA_LISTAORDENADA_H
