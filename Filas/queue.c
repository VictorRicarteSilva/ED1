#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 5

typedef struct fila{
    char elem[MAX];
    int final;
    int inicio;
    int qtd;
}Fila;

Fila *criaF(){
    Fila *f;
    f = (Fila *)malloc(sizeof (Fila));
    if(f != NULL){
    f->inicio = 0;
    f->final = 0;
    f->qtd = 0;
    }
    return f;
}

void destroiF(Fila *f){
    if(f != NULL){
    free(f);
    }
}

bool empty(Fila *f){
    bool deuCerto;
    if(f->qtd == 0){
        deuCerto = true;
        return deuCerto;
    }else{
        deuCerto = false;
        return deuCerto;
    }
}

bool full(Fila *f){
    bool deuCerto;
    if(f->qtd == MAX){
        deuCerto = true;
        return deuCerto;
    }else{
        deuCerto = false;
        return deuCerto;
    }
}

bool enqueue(Fila *f, char x){
    bool deuCerto;
    if(full(f) == true){
        deuCerto = false;
        return deuCerto;
    }else{
        f->qtd++;
        f->elem[f->final] = x;
        if(f->final == (MAX - 1)){
            f->final = 0;
        }else{
            f->final++;
        }
        deuCerto = true;
        return deuCerto;
    }
}

bool dequeue(Fila *f, char *x){
    bool deuCerto;
    if(empty(f) == true){
        deuCerto = false;
        return deuCerto;
    }else{
        f->qtd--;
        *x = f->elem[f->inicio];
        if(f->inicio == (MAX - 1)){
            f->inicio = 0;
        }else{
            f->inicio++;
        }
        deuCerto = true;
        return deuCerto;
    }
}

int main(){
    Fila *fi;
    char elem;
     fi = criaF();
    while (full(fi) == false){
        scanf(" %c", &elem);
        enqueue(fi,elem);
    }
    while (empty(fi) == false){
        dequeue(fi,&elem);
        printf("o elemento retirado foi: %c\n", elem);
    }
    return 0;
}

