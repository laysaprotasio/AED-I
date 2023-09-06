#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int valor;
    struct no *proximo;
} no;

typedef no *pilha;

pilha push(pilha p, int valor)
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
        printf("[%d]", aux->valor);
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

int top(pilha p)
{
    pilha aux = p;
    if (aux == NULL)
    {
        return 0;
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

    int i, n, a, b, freq;
    pilha p1 = NULL;

    a = 0;
    b = 1;

    printf("Digite um numero maior que 1\n");
    scanf("%d", &n);

    p1 = push(p1, 0);
    p1 = push(p1, 1);

    for(i = 0; i <= n -3; i++){
        freq = a + b;
        a = b;
        b = freq;
        p1 = push(p1, freq);
    }

    print(p1);


    return 0; 
}