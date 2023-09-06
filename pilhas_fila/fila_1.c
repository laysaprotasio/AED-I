#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct
{
    int elementos[MAX];
    int particao;
} fila;

void inicializar(fila *f)
{
    f->particao = 0;
}

int enqueue(fila *f, int valor)
{
    if (f->particao < MAX)
    {
        f->elementos[f->particao] = valor;
        f->particao++;
        return 1;
    }
    else
    {
        return 0;
    }
}

int dequeue(fila *f)
{
    int i;
    if (f->particao > 0)
    {
        for (i = 0; i < f->particao; i++)
        {
            f->elementos[i] = f->elementos[i + 1];
        }
        f->particao--;
        return 1;
    }
    else
    {
        return 0;
    }
}

int peek(fila *f)
{
    if (f->particao > 0)
    {
        return f->elementos[0];
    }
    else
    {
        return 0;
    }
}

int isEmpty(fila *f)
{
    if (f->particao == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void print(fila *f)
{
    int i;
    for (i = 0; i < f->particao; i++)
    {
        printf("[%d]", f->elementos[i]);
    }
    printf("\n");
}

int main()
{
    int opcao, valor, retorno, primeiro;
    fila *f1;
    f1 = (fila *)malloc(sizeof(fila));

    inicializar(f1);

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
            retorno = enqueue(f1, valor);

            if (retorno == 1)
            {
                printf("valor inserido com sucesso\n");
            }
            else if (retorno == 0)
            {
                printf("valor nao foi inserido\n");
            }
            break;

        case 2:
            retorno = dequeue(f1);
            if (retorno == 1)
            {
                printf("removido com sucesso\n");
            }
            else if (retorno == 0)
            {
                printf("nao foi possivel remover\n");
            }
            break;

        case 3:
            primeiro = peek(f1);
            printf("o primeiro elemento da fila e: [%d]\n", primeiro);
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
    
}