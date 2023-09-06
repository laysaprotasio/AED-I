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

void operacao1(fila *f)
{
    enqueue(f, f->elementos[0]);
    dequeue(f);
}

int main()
{
    fila *a, *b;

    a = (fila *)malloc(sizeof(fila));
    b = (fila *)malloc(sizeof(fila));

    inicializar(a);
    inicializar(b);

    int n, i, valor, contador;

    printf("Digite o tamanho dos vetores:\n");
    scanf("%d", &n);

    printf("Digite o valor contidos no vetor a:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &valor);
        enqueue(a, valor);
    }

    printf("Digite o valor contidos no vetor b:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &valor);
        enqueue(b, valor);
    }

    contador = 0;
    print(a);
    print(b);

    while (a->particao != 0)
    {
        while (a->elementos[0] != b->elementos[0])
        {
            operacao1(a);
            contador++;
        }

        if (a->elementos[0] == b->elementos[0])
        {
            dequeue(a);
            dequeue(b);
            contador++;
        }
    }

    printf("tempo total: %d\n", contador);

    return 0;
}
