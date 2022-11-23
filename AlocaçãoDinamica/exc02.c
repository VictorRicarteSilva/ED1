#include<stdio.h>
#include<stdlib.h>

int par(int *vet, int tam){
    int par = 0;
    for(int i = 0;i < tam;i++){
        if(vet[i] % 2 == 0){
            par++;
        }
    }
    return par;
}

int impar(int *vet, int tam){
    int impar = 0;
    for(int i = 0;i < tam;i++){
        if(vet[i] % 2 != 0){
            impar++;
        }
    }
    return impar;
}


int main(){
    int *vet;
    int qtdVet;
    printf("Quantos inteiros serao lidos: ");
    scanf("%d", &qtdVet);
    vet = malloc(qtdVet * sizeof(int));
    for(int i = 0;i < qtdVet;i++){
        printf("%do. inteiro: ", (i+1));
        scanf("%d", &vet[i]);
    }
    printf("Sao pares: %d dos %d inteiros lidos.\n", par(vet, qtdVet), qtdVet);
    printf("Sao impares: %d dos %d inteiros lidos.\n", impar(vet, qtdVet), qtdVet);
    return 0;
}