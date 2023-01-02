#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<math.h>
#define MAX 50

typedef struct stack{ //define o tipo de dado Stack de tamanho 50
    float elem[MAX]; // 
    int top;
}Stack;

Stack *criaS(){ // Insere dinamicamento a Stack na memoria, e encerra o programa caso não consiga
    Stack *s;
    s = (Stack *)malloc(sizeof(Stack));
    if(s != NULL){
        s->top = 0;
    }else{
        exit(1);
    }
    return s;
}

void destroiS(Stack *s){ // libera a Stack da memoria
    free(s);
}

bool full(Stack *s){ // verifica se a Stack esta cheia
    bool deuCerto;
    if(s->top == MAX){
        deuCerto = true;
        return deuCerto;
    }else{
        deuCerto = false;
        return deuCerto;
    }
}

bool empty(Stack *s){
    bool deuCerto;
    if(s->top == 0){
        deuCerto = true;
        return deuCerto;
    }else{
        deuCerto = false;
        return deuCerto;
    }
}

bool push(Stack *s, float elem){
    bool deuCerto;
    if(full(s) == true){
        deuCerto = false;
        return deuCerto;
    }else{
        s->elem[s->top] = elem;
        s->top++;
        deuCerto = true;
        return deuCerto;
    }
}

bool pop(Stack *s, float *elem){
    bool deuCerto;
    if(empty(s) == true){
        deuCerto = false;
        return deuCerto;
    }else{
        s->top--;
        *elem = s->elem[s->top];
        deuCerto = true;
        return deuCerto;
    }
}

float operation(float a, float b, char x){
    switch (x)
    {
    case '+':
        return a + b;
        break;
    case '-':
        return a - b;
        break;
    case '*':
        return a * b;
        break;
    case '/':
        return a / b;
        break;
    case '^':
        return pow(a,b);
        break;
    default:
        return 0.0;
    }
}

float result(char exp[]){
    char *pc;
    Stack pi;
    float x, y;
    float res, num;

    criaS(&pi);
    pc = strtok(exp, " ");
    while(pc){
        if(pc[0] == '+' || pc[0] == '-' || pc[0] == '*' || pc[0] == '/' || pc[0] == '^'){
            pop(&pi, &y);
            pop(&pi, &x);
            res = operation(x, y, pc[0]);
            push(&pi, num);
        }
        pc = strtok(NULL, " ");
    }
    pop(&pi, &res);
    destroiS(&pi);
    return res;
}

int main(){
    char exp[MAX] = {"5 3 2 + * 4 / 6 -"};
    float resultado;

    printf("Resultado de %s: \t", exp);

    resultado = result(exp);
    printf("%.2f\n", resultado);

    return 0;
}