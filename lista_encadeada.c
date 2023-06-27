// FUNCOES

#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada.h"

lista inserir_inicio(lista l, int valor)
{
    // Aloca espaço para o novo nó
    lista novo = (lista)malloc(sizeof(no));
    // inicializan o valor do novo a parir do parâmetro passado para função
    novo->valor = valor;
    // O próximo do novo aponta para o inicio da lista, ou seja, o antigo início passa a ser o segundo elemento (proximo do primeiro)
    novo->proximo = l;
    // Atualização da lista, através do retorno do ponteiro do novo início
    printf("Valor inserido com sucesso\n");
    return novo;
}

void exibir_lista(lista l)
{
    lista aux = l;
    while (aux != NULL)
    {
        printf("[%d]", aux->valor);
        aux = aux->proximo;
    }
    printf("\n");
}

void exibir_lista_r(lista l)
{
    // caso base
    if (l == NULL)
    {
        printf("\n");
        return;
    }
    exibir_lista_r(l->proximo);
    printf("[%d]\n", l->valor);
}

lista inserir_fim(lista l, int valor)
{
    lista aux = l;
    if (l == NULL)
    {
        return inserir_inicio(l, valor);
    }

    while (aux->proximo != NULL)
    {
        aux = aux->proximo;
    }
    // aqui aux == último
    lista novo = (lista)malloc(sizeof(no));
    novo->valor = valor;
    novo->proximo = NULL;

    // último aponte para o novo
    aux->proximo = novo;
    printf("valor inserido com sucesso\n");
    return l;
}

lista remover_inicio(lista l)
{
    if (l == NULL)
    {
        printf("A lista esta vazia\n");
        return NULL;
    }
    lista aux = l->proximo;
    free(l);
    printf("O valor foi removido com sucesso\n");
    return aux;
}

lista remover_fim(lista l)
{
    if (l == NULL)
    {
        printf("A lista esta vazia\n");
        return NULL;
    }
    if (l->proximo == NULL)
    {
        return remover_inicio(l);
    } else{
    lista aux = l;
    while (aux->proximo->proximo != NULL)
    {
        aux = aux->proximo;
    }
    free(aux->proximo);
    aux->proximo = NULL;
    printf("O valor foi removido com sucesso\n");
    return l;
    }
}

int tamanho(lista l)
{
    int contador = 0;
    lista aux = l;

    while (aux != NULL)
    {
        aux = aux->proximo;
        contador++;
    }

    printf("O tamanho da lista e de [%d] elementos\n", contador);

    return contador;
}

lista inserir_posicao(lista l, int valor, int posicao)
{
    int contador = 0;
    lista aux = l;

    if (posicao >= 0)
    {
        if (posicao == 0 || l == NULL)
        {
            return inserir_inicio(l, valor);
        }
        if (posicao >= tamanho(l))
        {
            inserir_fim(l, valor);
        }
        else
        {
            while (contador < posicao - 1)
            {
                aux = aux->proximo;
                contador++;
            }
            lista novo = (lista)malloc(sizeof(no));
            novo->valor = valor;
            novo->proximo = aux->proximo;
            aux->proximo = novo;
            printf("O Valor inserido com sucesso\n");
        }
    }
    else
    {
        printf("posicao invalida\n");
    }
    return l;
}

lista inserir_ordem(lista l, int valor)
{
    lista novo, aux;

    novo = (lista)malloc(sizeof(no));
    novo->valor = valor;

    if (l == NULL)
    {
        novo->proximo = NULL;
        l = novo;
        printf("O valor foi inserido com sucesso\n");
    }
    else if (novo->valor <= l->valor)
    {
        novo->proximo = l;
        l = novo;
        printf("O valor foi inserido com sucesso\n");
    }
    else
    {
        aux = l;
        while (aux->proximo != NULL && novo->valor > aux->proximo->valor)
        {
            aux = aux->proximo;
        }

        novo->proximo = aux->proximo;
        aux->proximo = novo;
        printf("O valor foi inserido com sucesso\n");
    }
    return l;
}

lista remover_pos(lista l, int posicao)
{
    int contador = 0;
    if (posicao >= 0)
    {
        if (l == NULL)
        {
            printf("A lista esta vazia\n");
            return NULL;
        }
        if (posicao >= tamanho(l))
        {
            printf("posicao nao encontrada\n");
            return l;
        }
        if (l->proximo == NULL || posicao == 0)
        {
            return remover_inicio(l);
        }
        else if (posicao == tamanho(l) - 1)
        {
            return remover_fim(l);
        }
        else if (posicao < tamanho(l))
        {
            int contador = 0;
            lista aux = l;
            lista aux2;

            while (contador < posicao - 1)
            {
                aux = aux->proximo;
                contador++;
            }

            aux2 = aux->proximo->proximo;
            free(aux->proximo);
            aux->proximo = aux2;
            printf("Valor removido com sucesso\n");
        }
    }
    else
    {
        printf("Posicao invalida\n");
    }
    return l;
}

lista remover_valor(lista l, int valor)
{


    lista aux = l;
    lista aux2;

    if (l == NULL)
    {
        printf("A lista esta vazia\n");
        return NULL;
    }

    if (l->valor == valor)
    {
        return remover_inicio(l);
    }

    while (aux->proximo != NULL && aux->proximo->valor != valor)
    {
        aux = aux->proximo;
    }

    if (aux->proximo == NULL)
    {
        printf("O valor nao foi encontrado\n");
        return l;
    }
    else
    {
        aux2 = aux->proximo->proximo;
        free(aux->proximo);
        aux->proximo = aux2;
        printf("valor removido com sucesso\n");
    }

    return l;
}

lista procurar(lista l, int valor)
{
    lista aux = l;

    while (aux != NULL && aux->valor != valor)
    {
        aux = aux->proximo;
    }
    if (aux == NULL)
    {
        printf("O valor nao foi encontrado\n");
        return NULL;
    }
    else
    {
        printf("O valor foi econtrado\n");
        return aux;
    }
}

int somatorio(lista l)
{
    lista aux = l;
    int soma = 0;

    while (aux != NULL)
    {
        soma += aux->valor;
        aux = aux->proximo;
    }
    printf("A soma de todos os elementos da lista e: [%d]\n", soma);
    return soma;
}

lista quadrado(lista l)
{
    lista aux = l;

    while (aux != NULL)
    {
        aux->valor = (aux->valor * aux->valor);
        aux = aux->proximo;
    }
    printf("Todos os elementos foram elevados ao quadrado\n");
    return l;
}

int primos(lista l)
{
    lista aux = l;
    int i, primo, contador;
    contador = 0;

    while (aux != NULL)
    {
        if (aux->valor > 1)
        {
            primo = 1;

            for (i = 2; i < aux->valor; i++)
            {
                if (aux->valor % i == 0)
                {
                    primo = 0;
                }
            }

            if (primo == 1)
            {
                contador++;
            }
        }

        aux = aux->proximo;
    }

    printf("A quantidade de primos e: [%d]\n", contador);

    return contador;
}