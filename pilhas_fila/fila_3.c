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


void print(fila *f)
{
    int i;
    for (i = 0; i < f->particao; i++)
    {
        printf("[%d]", f->elementos[i]);
    }
    printf("\n");
}

fila * intercala(fila *f1, fila *f2){
    
    int i;

    fila *f3;
    f3 = (fila *)malloc(sizeof(fila));
    inicializar(f3);

    for(i = 0; i < (f1->particao + f2->particao); i++){
        if(i < f1->particao){
            enqueue(f3, f1->elementos[i]);   
        }
        if(i < f2->particao){
            enqueue(f3, f2->elementos[i]);   
        }
    }
   return f3;

}

int main(){
    int i;

    fila *f1, *f2, *f3;

    f1 = (fila *)malloc(sizeof(fila));
    f2 = (fila *)malloc(sizeof(fila));
    f2 = (fila *)malloc(sizeof(fila));

    
    inicializar(f1);
    inicializar(f2);

    enqueue(f1, 10);
    enqueue(f1, 20);
    enqueue(f1, 30);

    enqueue(f2, 15);
    enqueue(f2, 25);
    enqueue(f2, 35);


    f3 = intercala(f1, f2);

    print(f3);

    
    }