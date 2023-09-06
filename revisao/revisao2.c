#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
}no;

typedef no *lista;

lista inserir_fim(lista l, int valor){
    lista novo, aux;
    novo = (lista)malloc(sizeof(no));
    novo->proximo = NULL;
    novo->valor = valor;

    if(l == NULL){
        l = novo;
        return l;
    } else{
        aux = l;
        while(aux->proximo != NULL){
            aux = aux->proximo;
        }
        aux->proximo = novo;

        return l;
        
    }
}

void print(lista l){
    lista aux;

    if(l == NULL){
        printf("\n");
    } else{
        aux = l;
        while(aux != NULL){
            printf("[%d]", aux->valor);
            aux = aux->proximo;
        }
        printf("\n");
    }
}

lista somas (lista l){
    lista l1, aux, aux2;
    l1 = NULL;
    aux = l;
    

    while(aux != NULL){
        if(l1 == NULL){
            l1 = inserir_fim(l1, aux->valor);;
            aux = aux->proximo;
            aux2 = l1;
        } else{
            l1 = inserir_fim(l1, (aux2->valor + aux->valor));
            aux = aux->proximo;
            aux2 = aux2->proximo;
        }
    }
    return l1;
}

int main (){
    lista l, l1;
    l = NULL;
    l1 = NULL;
    int i, valor, tamanho;

    printf("Digite o tamanho da lista:\n");
    scanf("%d", &tamanho);

    printf("Digite os elementos da lista:\n");

    for(i = 0; i < tamanho; i++){
        scanf("%d", &valor);
        l = inserir_fim(l, valor);
    }

    print(l);

    l1 = somas(l);

    print(l1);

}