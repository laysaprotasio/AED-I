#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H


typedef struct no{
        int valor;
        struct no* proximo;
} no;

typedef no* lista;

lista inserir_fim(lista l, int valor);
lista inserir_inicio(lista l, int valor);
void exibir_lista( lista l);
void exibir_lista_r( lista l);
lista inserir_posicao(lista l, int valor, int posicao);
int tamanho(lista l);
lista inserir_ordem(lista l, int valor);
lista remover_inicio(lista l);
lista remover_fim(lista l);
lista remover_pos(lista l, int posicao);
lista remover_valor(lista l, int valor);
lista procurar (lista l, int valor);
int somatorio(lista l);
lista quadrado(lista l);
int primos(lista l);


#endif