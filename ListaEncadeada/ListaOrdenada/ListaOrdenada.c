//
// Created by victor on 06/01/2023.
//
#include "ListaOrdenada.h"
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