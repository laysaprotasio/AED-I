#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct lista{
    int elementos[MAX];
    int particao;
} lista;

void inicializar(lista *l){
    l->particao = 0;
}

void print(lista *l){
    int i;
    for(i = 0; i < l->particao; i++){
        printf("[%d]", l->elementos[i]);
    }
    printf("\n");
}

int inserir_fim(lista *l, int valor){
    if(l->particao < MAX){
        l->elementos[l->particao] = valor;
        l->particao++;

        return 1;
    } else{
        return 0;
    }
}

void reverter(lista *l){
    int i, j, aux, tamanho;
    tamanho = l->particao;

    for(i = 0; i < (tamanho/2); i++){
        j = tamanho - i - 1;

        aux = l->elementos[i];
        l->elementos[i] = l->elementos[j];
        l->elementos[j] = aux;
    }
}

int main(){

    int i, tamanho, valor;
    lista *l1;

    l1 = (lista *)malloc(sizeof(lista));

    inicializar(l1);

    printf("Quantos elementos deseja inserir na lista?\n");
    scanf("%d", &tamanho);

    printf("Digite os elementos da lista\n");

    for(i = 0; i < tamanho; i++){
        scanf("%d", &valor);
        inserir_fim(l1, valor);
    }

    print(l1);
    reverter(l1);
    print(l1);

}