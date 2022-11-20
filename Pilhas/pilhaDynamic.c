#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX  5

typedef struct pilha{ // define o tipo de dado Pilha de tamanho MAX
    int elem[MAX];
    int top;
}Pilha;

void criaP(Pilha *p){ // aloca dinamicamente a Pilha na mémoria
    p = malloc(sizeof(Pilha));
    p->top = 0;
}

void destroiP(Pilha *p){ // libera a Pilha da mémoria
    free(p);
}

 bool full(Pilha *p){ // verifica se a posição no topo e igual ao MAX
    bool deuCerto;
    if (p->top == MAX){
        deuCerto = true;
        return deuCerto;
    }else{
        deuCerto = false;
        return deuCerto;
    }
}

bool empty(Pilha *p){ // veridica se a posição no topo e igual a 0
    bool deuCerto;
    if(p->top == 0){
        deuCerto = true;
        return deuCerto;
    }else{
        deuCerto = false;
        return deuCerto;
    }
}


bool push(Pilha *p, int x){ /* verifica se a Pilha está cheia, caso não incrementa o topo e insere um elemento
                                na mesma posição*/
    bool deucerto;
    if(full(&p) == true){
        deucerto = false;
        return deucerto;
    }else{
        p->elem[p->top] = x;
        p->top = p->top + 1;
        deucerto = true;
        return deucerto;
    }
}

bool pop(Pilha *p, int *x){ /*verifica se a Pilha está vazia, caso não o ponteiro pra inteiro recebe o elemento
                            do topo e decrementa o topo da Pilha*/
    bool deuCerto;
    if(empty(&p) == true){
        deuCerto = false;
        return deuCerto;
    }else{
        *x = p->elem[p->top];
        p->top = p->top - 1;
        deuCerto = true;
        return deuCerto;
    }
}

int main(){
    Pilha p1;
    int num;
    criaP(&p1);
    while(full(&p1) == false){
        scanf("%d", &num);
        push(&p1, num);
    }
    while (empty(&p1) == false){
        pop(&p1, &num);
        printf("%i", num);
    }
    destroiP(&p1);
}