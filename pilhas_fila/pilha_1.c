#include <stdio.h>
#include <stdlib.h>

#define MAX 25

typedef struct pilha{
        int elementos[MAX];
        int particao;
}pilha;


void inicializar(pilha *p)
{
    p->particao = 0;
}

int push(pilha *p, int valor)
{
    if (p->particao < MAX)
    {
        p->elementos[p->particao] = valor;
        p->particao++;
        return 1;
    }
    else
    {
        return 0;
    }
}

void print(pilha *p)
{
    int i;
    for (i = 0; i < p->particao; i++)
    {
        printf("[%d]", p->elementos[i]);
    }
    printf("\n");
}

int pop(pilha *p)
{
    if (p->particao > 0)
    {
        p->particao--;
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(pilha *p){
    if(p->particao == 0){
        return 1;
    } else if(p->particao != 0){
        return 0;
    }
}

int top (pilha *p){

    return p->elementos[p->particao -1];

}



int main (){
    
    int opcao, valor, topo, vazio, retorno;
    
    pilha *p1;
    p1 = (pilha *)malloc(sizeof(pilha));

    inicializar(p1);

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
            retorno = push(p1, valor);

            if(retorno == 1){
                printf("valor empilhado com sucesso\n");
            } else if(retorno == 0){
                printf("nao foi possivel empilhar o valor\n");
            }
            break;

        case 2:
            retorno = pop(p1);

            if(retorno == 1){
                printf("valor desempilhado com sucesso\n");
            } else if(retorno == 0){
                printf("nao foi possivel desempilhar o valor\n");
            }
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


