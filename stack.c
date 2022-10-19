#include<stdio.h>
#include<stdbool.h>
#define MAX  5

typedef struct pilha
{
     elementos[MAX];
     int topo; // posição do topo da pilha

}Pilha;

void criarP(Pilha *p)
{
    p->topo = -1;
}

void destuirP(Pilha *p)
{
    p->topo = -1;
}

bool empilhar(Pilha *p, char x)
{
    bool deuCerto;
    if(cheia(*p) == true)
    {
        deuCerto == false;
        return deuCerto;
    }
    else
    {
        p->topo = p->topo + 1;
        p->elementos[p->topo] = x;
        deuCerto == true;
        return deuCerto;
    }
}

int main ()
{

}
