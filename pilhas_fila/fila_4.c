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
        printf("%d", aux->valor);
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
void print_r(fila f)
{
    if (f != NULL)
    {
        print_r(f->proximo);
        printf("%d", f->valor);
    }
}

fila binario (int valor){
    fila f;
    f = NULL;

    while(valor != 0){
    f = enqueue(f, (valor%2));
    valor = (valor/2);
    }

    return f;
}

int main (){
    int i, valor;

    fila f;
    f = NULL;

    printf("Digite um valor:\n");
    scanf("%d", &valor);


    for(i = 1; i <= valor; i++){
        f = binario(i);
        print_r(f);
        printf("\t");
        while(f != NULL){
            f = dequeue(f);
        }
    }

}