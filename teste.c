#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada.h"

int main(int argc, char *argv)
{

    // declaração da lista
    lista l1 = NULL;
    int opcao;
    int valor, posicao, procurado;

    while (opcao != 99)
    {
        printf("Selecione uma das opcoes a seguir:\n"
               "1 - Para inserir no inicio da lista\n"
               "2 - Para inserir ao fim da lista\n"
               "3 - Para inserir em uma posicao da lista\n"
               "4 - Para inserir um valor em ordem na lista\n"
               "5 - Para exibir a lista\n"
               "6 - Para exibir a lista reversa\n"
               "7 - Para remover do inicio da lista\n"
               "8 - Para remover do fim da lista\n"
               "9 - Para remover o valor de uma posicao da lista\n"
               "10 - Para remover um valor da lista\n"
               "11 - Para procurar um valor na lista\n"
               "12 - Para saber a soma de todos os elementos da lista\n"
               "13 - Para saber o tamanho da lista (quantidade de elementos)\n"
               "14 - Para elevar ao quadrado todos os elementos de lista\n"
               "15 - Para saber a quantidade de primos que ha na lista\n"
               "99 - Para sair do programa\n");

        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite o valor para ser inserido no inicio da lista:\n");
            scanf("%d", &valor);
            l1 = inserir_inicio(l1, valor);
            break;

        case 2:
            printf("Digite o valor para ser inserido no final da lista:\n");
            scanf("%d", &valor);
            l1 = inserir_fim(l1, valor);
            break;

        case 3:
            printf("Digite o valor para ser inserido na determinada posicao:\n");
            scanf("%d", &valor);
            printf("Digite a posicao que deseja inserir:\n");
            scanf("%d", &posicao);
            
            l1 = inserir_posicao(l1, valor, posicao);
            break;

        case 4:
            printf("Digite o valor para ser inserido na ordem da lista:\n");
            scanf("%d", &valor);
            l1 = inserir_ordem(l1, valor);
            break;

        case 5:
            exibir_lista(l1);
            break;

        case 6:
            exibir_lista_r(l1);
            break;

        case 7:
            l1 = remover_inicio(l1);
        
            break;

        case 8:
            l1 = remover_fim(l1);

            break;

        case 9:
            printf("Digite a posicao para ser removida de lista:\n");
            scanf("%d", &posicao);
            l1 = remover_pos(l1, posicao);
            break;

        case 10:
            printf("Digite o valor para ser removido da lista:\n");
            scanf("%d", &valor);
            l1 = remover_valor(l1, valor);
            break;

        case 11:
            printf("Digite o valor para ser encontrado na lista:\n");
            scanf("%d", &valor);
            procurar(l1, valor);
            break;
        
        case 12:
            somatorio(l1);
            break;

        case 13:
            tamanho(l1);
            break;

        case 14:
            l1 = quadrado(l1);
            break;
        
        case 15:
            primos(l1);
            break;
        case 99:
            printf("Saindo...");
            break;

        default:
            printf("valor indeterminado\n");
            break;
        }
    }
    exit(0);
}
