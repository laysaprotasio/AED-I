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


int main (){

    int i, j,  dia, maior;

    fila *f1;
    f1 = (fila *)malloc(sizeof(fila));

    inicializar(f1);

    

    printf("Digite uma quantidade de dias N:\n");
    scanf("%d", &dia);

    maior = dia;
    int torre[dia];

    printf("Digite o tamanho dos discos:\n");
    for(i = 0; i < dia; i++){
        scanf("%d", &torre[i]);
    }

    for(i = 0; i < dia; i++){
        if(torre[i] == maior){
            printf("%d\t", torre[i]);
            maior = maior - 1;
            for(j = 0; j < f1->particao; j++){
                if(f1->elementos[j] == maior){
                    printf("%d\t", f1->elementos[j]);
                    maior = maior -1;
                    j = 0;
                }
            }
            printf("\n");
        } else{
            printf("\n");
            enqueue(f1, torre[i]);
        }
    }

    return 0;
}