#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(int argc, char *argv)
{

    // declaração da lista
    struct lista *l;
    l = (struct lista *)malloc(sizeof(struct lista));

    inicializar(l);

    int opcao;

    opcao = 0;

    while (opcao != 99)
    {
        printf("Digite uma opcao:\n"
               "1 - Para inserir no inicio da lista\n"
               "2 - Para iserir no fim da lista\n"
               "3 - Para inserir em uma posicao da lista\n"
               "4 - Para inserir na ordem\n"
               "5 - Para exibir a lista\n"
               "6 - Para exibir a lista reversa\n"
               "7 - Para remover do inicio da lista\n"
               "8 - Para remover do fim da lista\n"
               "9 - Paraa remover de uma posicao da lista\n"
               "10 - Para remover um valor da lista\n"
               "11 - Para procurar um valor na lista\n"
               "12 - Para saber a soma dos elementos da lista\n"
               "13 - Para saber o tamanho da lista\n"
               "14 - Para saber o quadrado de todos os elementos da lista\n"
               "15 - Para saber a quantidade de numeros primos\n"
               "16 - Para limpar a lista\n"
               "99 - Para fechar o programa\n");

        scanf("%d", &opcao);

        if (opcao == 16)
        {
            limpar_lista(l);
            printf("A lista esta vazia");
        }

        if (opcao == 1)
        {

            int valor, retorno;

            printf("Digite um valor para iserir no inicio da lista:\n");
            scanf("%d", &valor);
            retorno = inserir_inicio(l, valor);

            if (retorno == 0)
            {
                printf("%d - O numero nao foi inserido\n", retorno);
            }
            else
            {
                printf("%d - O numero foi inserido com sucesso\n", retorno);
            }
        }

        if (opcao == 2)
        {
            int valor, retorno;

            printf("Digite um valor para iserir no fim da lista:\n");
            scanf("%d", &valor);
            retorno = inserir_fim(l, valor);

            if (retorno == 0)
            {
                printf("%d - O numero nao foi inserido\n", retorno);
            }
            else
            {
                printf("%d - O numero foi inserido com sucesso\n", retorno);
            }
        }

        if (opcao == 3)
        {
            int valor, posicao, retorno;

            printf("Digite um valor para iserir na lista:\n");
            scanf("%d", &valor);
            printf("Digite uma posicao para iserir o valor na lista:\n");
            scanf("%d", &posicao);

            retorno = inserir_posicao(l, valor, posicao);

            if (retorno == 0)
            {
                printf("%d - O numero nao foi inserido\n", retorno);
            }
            else
            {
                printf("%d - O numero foi inserido com sucesso\n", retorno);
            }
        }
        if (opcao == 4)
        {
            int valor, retorno;

            printf("Utilize a opcao 16 para limpar a lista e utilize a opcao 2 para inserir numeros em ordem crescente\n");
            printf("Apos ter feito isso, digite um valor para ser inserido na lista ordenada:\n");
            scanf("%d", &valor);

            retorno = inserir_ordem(l, valor);

            if (retorno == 0)
            {
                printf("%d - O numero nao foi inserido\n", retorno);
            }
            else
            {
                printf("%d - O numero foi inserido com sucesso\n", retorno);
            }
        }

        if (opcao == 5)
        {
            printf("Lista:\n");
            exibir_lista(l);
        }

        if (opcao == 6)
        {
            printf("Lista:\n");
            reverso_lista(l);
        }
        if (opcao == 7)
        {
            int retorno;

            retorno = remover_inicio(l);

            if (retorno == 0)
            {
                printf("%d - O numero nao foi removido\n", retorno);
            }
            else
            {
                printf("%d - O numero foi removido com sucesso\n", retorno);
            }
        }
        if (opcao == 8)
        {
            int retorno;

            retorno = remover_fim(l);

            if (retorno == 0)
            {
                printf("%d - O numero nao foi removido\n", retorno);
            }
            else
            {
                printf("%d - O numero foi removido com sucesso\n", retorno);
            }
        }
        if (opcao == 9)
        {
            int retorno, posicao;

            printf("Digite uma posicao para ser removida da lista:\n");
            scanf("%d", &posicao);

            retorno = remover_posicao(l, posicao);

            if (retorno == 0)
            {
                printf("%d - O numero nao foi removido\n", retorno);
            }
            else
            {
                printf("%d - O numero foi removido com sucesso\n", retorno);
            }
        }

         if (opcao == 10)
        {
            int retorno, valor;
            
            printf("Digite um valor para ser removido da lista:\n");
            scanf("%d", &valor);

            retorno = remover_valor(l, valor);

            if (retorno == 0)
            {
                printf("%d - O valor nao foi encontrado\n", retorno);
            }
            else
            {
                printf("%d - O valor foi removido com sucesso\n", retorno);
            }
        }
        if (opcao == 11)
        {
            int retorno, valor;
            
            printf("Digite um valor para saber em qual posicao da lista ele esta:\n");
            scanf("%d", &valor);

            retorno = procurar(l, valor);

            if (retorno != -1)
            {
                printf("O valor foi encontrado na posicao: %d\n", retorno);
            }
            else
            {
                printf("%d - O valor nao foi encontrado na lista\n", retorno);
            }
        }
        if (opcao == 12)
        {
            int soma;

            soma = somatorio(l);

            printf("A soma de todos os elementos da lista:%d\n", soma);

        }
        if (opcao == 13)
        {
            int tam;

            tam = tamanho(l);

            printf("A tamanho da lista:%d\n", tam);

        }
        if (opcao == 14)
        {
            printf("A lista ao quadrado e:\n");
            quadrado(l);
            exibir_lista(l);
        }

         if (opcao == 15)
        {
            int quantidade;

            quantidade = quantidade_primos(l);

            printf("A quantidade de primos e: %d\n", quantidade);
        }

    }

    exit(0);
}