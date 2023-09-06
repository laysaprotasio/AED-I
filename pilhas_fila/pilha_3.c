#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no
{
    char valor;
    struct no *proximo;
} no;

typedef no *pilha;

pilha push(pilha p, char valor)
{
    pilha aux = p;
    if (p == NULL)
    {
        pilha novo = (pilha)malloc(sizeof(no));
        novo->valor = valor;
        novo->proximo = p;
        return novo;
    }

    while (aux->proximo != NULL)
    {
        aux = aux->proximo;
    }

    pilha novo = (pilha)malloc(sizeof(no));
    novo->valor = valor;
    novo->proximo = NULL;
    aux->proximo = novo;

    return p;
}

void print(pilha p)
{
    pilha aux = p;
    while (aux != NULL)
    {
        printf("[%c]", aux->valor);
        aux = aux->proximo;
    }
    printf("\n");
}

pilha pop(pilha p)
{
    pilha aux = p;
    if (p == NULL)
    {
        return NULL;
    }
    if (p->proximo == NULL)
    {
        pilha aux = p->proximo;
        free(p);
        return aux;
    }
    else
    {
        while (aux->proximo->proximo != NULL)
        {
            aux = aux->proximo;
        }
        free(aux->proximo);
        aux->proximo = NULL;
        return p;
    }
}

char top(pilha p)
{
    pilha aux = p;
    if (aux == NULL)
    {
        return '0';
    }
    else
    {
        while (aux->proximo != NULL)
        {
            aux = aux->proximo;
        }
        return aux->valor;
    }
}

int isEmpty(pilha p)
{
    if (p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main (){

    #define MAX 50
    int i, vazio;
    char expressao[MAX];
    pilha p1;

    p1 = NULL;

    printf("digite um expressao matematica\n");
    scanf("%s", expressao);

    for(i = 0; i < strlen(expressao); i++){
        if(expressao[i] == '{' || expressao[i] == '[' || expressao[i] == '(' ){
            p1 = push(p1, expressao[i]);
        }
        if(expressao[i] == '}' && top(p1) == '{' ){
            p1 = pop(p1);
        }
        if(expressao[i] == ']' && top(p1) == '[' ){
            p1 = pop(p1);
        }
        if(expressao[i] == ')' && top(p1) == '(' ){
            p1 = pop(p1);
        }
    }

    vazio = isEmpty(p1);
    if(vazio == 1){
        printf("A expressao esta balanceada");
    } else if(vazio == 0){
        printf("A expressao nao esta balanceada");
    }

    return 0;

}