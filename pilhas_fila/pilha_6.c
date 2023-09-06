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

int main(){
    pilha p1 = NULL;
    int i, N; // N = numero de minutos

    printf("Digite o numero de minutos:\n");
    scanf("%d", &N);

    int C[N];
    printf("Digite a quantidade de chocolates de cada caixa\n");
    for(i = 0; i < N; i++){
        scanf("%d", &C[i]);
    }

    for(i = 0; i < N; i++){
        printf("[%d]", C[i]);
    }
    printf("\n", C[i]);    

    for(i = 0; i < N; i++){
        if(C[i]>0){
            p1 = push(p1, C[i]);
        } else if(C[i] == 0){
            printf("vendido: [%d]\n", top(p1));
            p1 = pop(p1);
        }
    }


    return 0;
}