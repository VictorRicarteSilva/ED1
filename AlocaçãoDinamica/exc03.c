#include<stdio.h>
#include<stdlib.h>

typedef struct pontos
{
    int x;
    int y;
}Pontos;

int main(){
    Pontos *p;
    int qtd;
    printf("Quantos pontos deseja digitar: ");
    scanf("%d", &qtd);
    p = (Pontos *) malloc(qtd * sizeof(Pontos));
    for(int i = 0;i < qtd;i++){
        printf("Entre com a coordenada x do ponto %d: ", (i+1));
        scanf("%d", &p[i].x); 
        printf("Entre com a coordenada y do ponto %d: ", (i+1));
        scanf("%d", &p[i].y);
    }
    for(int i = 0;i < qtd;i++){
        printf("Pontos digitados: (%d,%d)\n", p[i].x, p[i].y);
    }
    free(p);
    return 0;
}
