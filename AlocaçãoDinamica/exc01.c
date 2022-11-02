#include<stdio.h>
#include<stdlib.h>

int main (){
    int *v;
    int i = 0, aux;
    v = malloc(5 * sizeof(int));
    while(i < 5){
        printf("Entre com um numero: ");
        scanf("%d", &aux);
        v[i] = aux;
        i++;
    }
    for ( i = 0; i < 5; i++)
    {
        printf("v[%d]: %d \n", i, v[i]);
    }
    free (v);
    return 0;
}
