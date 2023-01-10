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


#endif //LISTAORDENADA_LISTAORDENADA_H
