#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no_pilha
{
    char valor;
    struct no_pilha *proximo;
} no_pilha;

typedef no_pilha *pilha;

pilha push(pilha p, char valor)
{
    pilha aux = p;
    if (p == NULL)
    {
        pilha novo = (pilha)malloc(sizeof(no_pilha));
        novo->valor = valor;
        novo->proximo = p;
        return novo;
    }

    while (aux->proximo != NULL)
    {
        aux = aux->proximo;
    }

    pilha novo = (pilha)malloc(sizeof(no_pilha));
    novo->valor = valor;
    novo->proximo = NULL;
    aux->proximo = novo;

    return p;
}

void print_pilha(pilha p)
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

int isEmpty_pilha(pilha p)
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
typedef struct no_fila
{
    char valor;
    struct no_fila *proximo;
} no_fila;

typedef no_fila *fila;

fila enqueue(fila f, char valor)
{
    fila aux = f;

    fila novo = (fila)malloc(sizeof(no_fila));
    novo->proximo = NULL;
    novo->valor = valor;

    if (f == NULL)
    {
        return novo;
    }
    else
    {
        while (aux->proximo != NULL)
        {
            aux = aux->proximo;
        }
        aux->proximo = novo;
        return f;
    }
}

void print_fila(fila f)
{
    fila aux = f;
    while (aux != NULL)
    {
        printf("[%d]", aux->valor);
        aux = aux->proximo;
    }
    printf("\n");
}

fila dequeue(fila f)
{
    if (f == NULL)
    {
        return NULL;
    }
    else
    {
        f = f->proximo;
        return f;
    }
}

char peek(fila f){
    if(f == NULL){
        return 0;
    } else{
        return f->valor;
    }
}

int isEmpty_fila(fila f){
    if(f == NULL){
        return 1; 
    } else{
        return 0;
    }
}

int main()
{   
    #define MAX 100

    pilha p1;
    fila f1;
    
    p1 = NULL;
    f1 = NULL;

    char str[MAX];
    int i;

    printf("Digite uma biblioteca:\n");
    scanf("%s", str);

    for(i = 0; i <  strlen(str); i++){
        if(str[i] != '\\'){
            p1 = push(p1, str[i]);
        } else{
            while(top(p1) != '/'){
                f1 = enqueue(f1, top(p1));
                p1 = pop(p1);
            }
            p1 = pop(p1);
            while(isEmpty_fila(f1) != 1){
                p1 = push(p1, peek(f1));
                f1 = dequeue(f1);
            }
        }
    }

    print_pilha(p1);


    return 0;
}