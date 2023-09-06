#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int valor;
    struct no *proximo;
} no;

typedef no *fila;

fila enqueue(fila f, int valor)
{
    fila aux = f;

    fila novo = (fila)malloc(sizeof(no));
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

void print(fila f)
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

int peek(fila f){
    if(f == NULL){
        return 0;
    } else{
        return f->valor;
    }
}

int isEmpty(fila f){
    if(f == NULL){
        return 1; 
    } else{
        return 0;
    }
}

int main()
{
    int opcao, valor, inicio, retorno;
    fila f1;
    f1 = NULL;
    while (opcao != 99)
    {
        printf("Escolha uma opcao a seguir:\n"
               "1 - Adicionar um elemento no final da fila\n"
               "2 - Para retirar um elemento do inicio da fila\n"
               "3 - Para consultar o primeiro elemento da fila\n"
               "4 - Para consultar se a fila esta vazia ou nao\n"
               "5 - Para printar todos os elementos da fila\n"
               "99 - Para sair\n");

        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite o numero para ser adicionado ao final da fila\n");
            scanf("%d", &valor);
            f1 = enqueue(f1, valor);
            break; 

        case 2:
            f1 = dequeue(f1);
            break;

        case 3:
            inicio = peek(f1);
            printf("o primeiro elemento da fila e: [%d]\n", inicio);
            break;

        case 4:
            retorno = isEmpty(f1);
            if (retorno == 1)
            {
                printf("A lista esta vazia\n");
            }
            else if (retorno == 0)
            {
                printf("A lista nao esta vazia\n");
            }
            break;

        case 5:
            print(f1);
            break;

        case 99:
            printf("Saindo...\n");
            break;

        default:
            printf("opcao invalida\n");
            break;
        }
    }
    return 0;
}