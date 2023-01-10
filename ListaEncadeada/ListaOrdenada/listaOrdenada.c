//
// Created by victor on 06/01/2023.
//
#include "listaOrdenada.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

Node *newNode(){
    Node *n;
    // Retorna NULL, caso não consiga alocar
    n = malloc(sizeof(Node));
    return n;
}

void deleteNode(Node *n){
    // Verificação para evitar dupla liberação da memória
    if(n != NULL){
        free(n);
    }
}

Lista *criaL(){
    Lista *L;
    // Retorna NULL, caso não consiga alocar
    L = malloc(sizeof(Lista));
    if(L != NULL){
        // Lista vazia
        L->head = NULL;
    }
    return L;
}

bool estaNaLista(Lista *l, int numero){
    Node *P = newNode();
    Node *Pant = newNode();
    P = l->head;
    Pant = NULL;
    while(P != NULL && P->info < numero){
        Pant = P;
        P = P->next;
    }
    if(P != NULL && P->info == numero){
        return true;
    }
    return false;
}

bool cheia(Lista l){
    return false; // para esta implementação a lista nunca estará cheia
}

bool vazia(Lista l){
    if(l.head->next == NULL){
        return true;
    }
    return false;
}
bool insereOrdenado(Lista *l, int numero){
    Node *P = newNode();
    Node *Pant = newNode();
    P = l->head;
    Pant = NULL;
    if(P == NULL){
        P->info = numero;
        P->next = NULL;
        l->head = P;
        return true;
    }

}