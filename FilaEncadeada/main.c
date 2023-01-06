#include "listaEncadeada.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    Lista *l1;
    l1 = criarL();
    int i = 0;
    char x;
    while(i <= 5){
        scanf(" %c", &x);
        inserirInicio(l1, x);
        i++;
    }
    destruirL(l1);
}