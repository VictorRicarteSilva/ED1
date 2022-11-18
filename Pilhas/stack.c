#include<stdio.h>
#include<stdbool.h>
#define MAX  5

/*Tipo de dado Pilha que possui um vetor de char e um inteiro que define a posição do topo da pilha*/
typedef struct pilha
{
     int elementos[MAX];
     int topo; // posição do topo da pilha

}Pilha;

// define o topo da pilha como -1
void criarP(Pilha *p)
{
    p->topo = -1;
}
// define o topo da pilha como -1 destuindo as antigas posições do topo
void destuirP(Pilha *p)
{
    p->topo = -1;
}
// verifica se uma determinada pilha está cheia comparando a posição do topo com a constante MAX
bool cheia (Pilha p)
{
    bool deuCerto;
    if (p.topo == MAX)
    {
        deuCerto = true;
        return deuCerto;
    }  
    else
    {
        deuCerto = false;
        return deuCerto;
    }
}
// verifica se uma determinada pilha esta vazia comparando a posição do topo com -1
bool vazia(Pilha p)
{
    bool deuCerto;
    if(p.topo == -1)
    {
        deuCerto = true;
        return deuCerto;
    }
    else
    {
        deuCerto = false;
        return deuCerto;
    }
}
/* recebe um ponteiro para pilha e um char, verifica se a pilha esta cheia, caso sim retorna false
caso contrario incrementa o topo da pilha, e insere x na posição topo do vetor elementos e retorna true
*/
bool empilhar(Pilha *p, int x)
{
    bool deuCerto;
    if(cheia(*p) == true)
    {
        deuCerto = false;
        return deuCerto;
    }
    else
    {
        p->topo = p->topo + 1;
        p->elementos[p->topo] = x;
        deuCerto = true;
        return deuCerto;
    }
}
/* recebe um ponteiro para pilha e um ponteiro para char, verifica se a pilha está vazia,
caso sim retorna false, caso contrario a funçao decrementa o topo da pilha e atribui a *X o valor da posicao
topo do vetor elementos e retorna true*/
bool desempilhar(Pilha *p, int *x)
{
    bool deuCerto;
    if(vazia(*p) == true)
    {
        deuCerto = false;
        return deuCerto;
    }
    else
    {
        *x = p->elementos[p->topo];
        p ->topo = p ->topo - 1;
        deuCerto = true;
        return deuCerto;
    }
}

int main ()
{
    Pilha stack;
    int c;
    criarP(&stack);
    for(int i = 0;i < MAX;i++)
    {
        scanf("%i", &c);
        empilhar(&stack, c);
    }
    while (desempilhar(&stack, &c) == true)
    {
        printf("%i ", c);
    }
    return 0;
}
