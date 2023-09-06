#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void inicializar(struct lista *l)
{
    l->particao = 0;
}

int inserir_fim(struct lista *l, int valor)
{
    if (l->particao < MAX)
    {
        l->elementos[l->particao] = valor;
        l->particao++;
        return 1;
    }
    else
    {
        return 0;
    }
}

int inserir_inicio(struct lista *l, int valor)
{
    // movimentação de todos os valores para a direita
    // repetição do fim para o início
    int i;
    if (l->particao < MAX)
    {
        for (i = l->particao; i > 0; i--)
        {
            l->elementos[i] = l->elementos[i - 1];
        }

        l->elementos[0] = valor;
        l->particao++;

        return 1;
    }
    else
    {
        return 0;
    }
}

void exibir_lista(struct lista *l)
{
    int i;
    for (i = 0; i < l->particao; i++)
    {
        printf("[%d]", l->elementos[i]);
    }
    printf("\n");
}

int concatenar(struct lista *l1, struct lista *l2)
{
    int i;
    if (l1->particao + l2->particao < MAX)
    {
        for (i = 0; i < l2->particao; i++)
        {
            inserir_fim(l1, l2->elementos[i]);
        }
        return 1;
    }
    else
    {
        return 0;
    }
}

int inserir_posicao(struct lista *l, int valor, int posicao)
{
    int i;
    if (l->particao < MAX && posicao >= 0 && posicao <= l->particao)
    {
        for (i = l->particao; i > posicao; i--)
        {
            l->elementos[i] = l->elementos[i - 1];
        }

        l->elementos[posicao] = valor;
        l->particao++;

        return 1;
    }
    else
    {
        return 0;
    }
}

int inserir_ordem(struct lista *l, int valor)
{
    int i, posicao;
    posicao = 0;

    for (i = 0; i < l->particao; i++)
    {
        if (valor > l->elementos[i])
        {
            posicao = i + 1;
        }
    }

    if (l->particao < MAX)
    {
        for (i = l->particao; i > posicao; i--)
        {
            l->elementos[i] = l->elementos[i - 1];
        }

        l->elementos[posicao] = valor;
        l->particao++;

        return 1;
    }
    else
    {
        return 0;
    }
}

void reverso_lista(struct lista *l)
{
    int i;
    for (i = l->particao - 1; i >= 0; i--)
    {
        printf("[%d]", l->elementos[i]);
    }
    printf("\n");
}

int remover_inicio(struct lista *l)
{
    // movimentação de todos os valores para a esquerda

    int i;
    if (l->particao > 0)
    {
        for (i = 0; i < l->particao - 1; i++)
        {
            l->elementos[i] = l->elementos[i + 1];
        }

        l->particao--;

        return 1;
    }
    else
    {
        return 0;
    }
}

int remover_fim(struct lista *l)
{
    if (l->particao > 0)
    {
        l->particao--;
        return 1;
    }
    else
    {
        return 0;
    }
}

int remover_posicao(struct lista *l, int posicao)
{
    int i;
    if (l->particao > 0 && posicao >= 0 && posicao <= l->particao)
    {
        for (i = posicao; i < l->particao - 1; i++)
        {
            l->elementos[i] = l->elementos[i + 1];
        }

        l->particao--;

        return 1;
    }
    else
    {
        return 0;
    }
}

int remover_valor(struct lista *l, int valor)
{
    int i, posicao;

    posicao = -1;

    for (i = 0; i < l->particao; i++)
    {
        if (valor == l->elementos[i])
        {
            posicao = i;
        }
    }
    if (l->particao > 0 && posicao != -1)
    {
        for (i = posicao; i < l->particao - 1; i++)
        {
            l->elementos[i] = l->elementos[i + 1];
        }

        l->particao--;

        return 1;
    }
    else
    {
        return 0;
    }
}

int procurar(struct lista *l, int valor)
{

    int i, posicao;

    for (i = 0; i < l->particao; i++)
    {
        if (valor == l->elementos[i])
        {
            posicao = i;

            return posicao;
        }
    }

    for (i = 0; i < l->particao; i++)
    {
        if (valor != l->elementos[i])
        {
            posicao = -1;

            return posicao;
        }
    }
}

int somatorio(struct lista *l)
{

    int somatorio, i;

    somatorio = 0;

    for (i = 0; i < l->particao; i++)
    {

        somatorio = somatorio + l->elementos[i];
    }

    return somatorio;
}

int tamanho(struct lista *l)
{

    return l->particao;
}

void quadrado(struct lista *l)
{

    int i;

    for (i = 0; i < l->particao; i++)
    {
        l->elementos[i] = (l->elementos[i] * l->elementos[i]);
    }
}

int quantidade_primos(struct lista *l)
{
    int i, j, contador, primo;

    contador = 0;

    for (i = 0; i < l->particao; i++)
    {
        if (l->elementos[i] > 1)
        {
            primo = 1;
            for (j = 2; j < l->elementos[i]; j++)
            {
                if (l->elementos[i] % j == 0)
                {

                    primo = 0;
                }
            }
            if (primo == 1)
            {
                contador = contador + 1;
            }
        }
    }

    return contador;
}

int limpar_lista(struct lista *l){
    l->particao = 0;
}