#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 25

typedef struct pilha{
        char elementos[MAX];
        int particao;
}pilha;



void inicializar(pilha *p)
{
    p->particao = 0;
}

int push(pilha *p, char valor)
{
    if (p->particao < MAX)
    {
        p->elementos[p->particao] = valor;
        p->particao++;
        return 1;
    }
    else
    {
        return 0;
    }
}

void print(pilha *p)
{
    int i;
    for (i = 0; i < p->particao; i++)
    {
        printf("%c", p->elementos[i]);
    }
    printf("\n");
}

int pop(pilha *p)
{
    if (p->particao > 0)
    {
        p->particao--;
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(pilha *p){
    if(p->particao == 0){
        return 1;
    } else if(p->particao != 0){
        return 0;
    }
}

char top (pilha *p){

    return p->elementos[p->particao -1];

}

int main (){

    pilha *p1;

    inicializar(p1);

    #define MAX 25

    char str[MAX];
    int i, igual, t1, t2;

    printf("Digite uma string:\n");
    scanf("%s", str);

    for(i = strlen(str)-1; i >= 0; i--){
        push(p1, str[i]);
    }

    t1 = strlen(str);
    t2 = p1->particao;

    igual = 1; // considerando que sao iguais
    
    if(t1 != t2){
        igual = 0;
    } else{
        for(i = 0; i < p1->particao; i++){
            if(str[i] != p1->elementos[i]){
                igual = 0;
            }
        }
    }

    if(igual == 1){
        printf("sao palindromos");
    } else{
        printf("nao sao palindromos");
    }

    return 0;
}