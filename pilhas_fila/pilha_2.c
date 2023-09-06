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

int main()
{
    pilha p1 = NULL;
    int opcao, valor, topo, vazio;

    while (opcao != 99)
    {
        printf("Selecione uma das opcoes a seguir:\n"
               "1 - Inserir um elemento no topo da pilha\n"
               "2 - Retirar um elemento do topo da pilha\n"
               "3 - Consultar o valor no topo da pilha\n"
               "4 - Consultar se a pilha esta vazia ou com elementos\n"
               "5 - Exibir todos os elementos da pilha\n"
               "99 - Para sair do programa\n");

        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite um valor para empilhar\n");
            scanf("%d", &valor);
            p1 = push(p1, valor);
            break;

        case 2:
            p1 = pop(p1);
            break;

        case 3: 
            topo = top(p1);
            printf("O elemento do topo de pilha e [%d]\n", topo);
            break;
        
        case 4:
            vazio = isEmpty(p1);
            if(vazio == 1){
                printf("A pilha esta vazia\n");
            } else if (vazio == 0){
                printf("A pilha nao esta vazia\n");
            }
            break;

        case 5:
            print(p1);
            break;

        case 99:
            printf("Saindo...\n");
            break;

        default:
            printf("valor indeterminado\n");
            break;
        }
    }

    return 0;
}
