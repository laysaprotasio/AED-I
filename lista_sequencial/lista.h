#ifndef LISTA_SEQUENCIAL_H
#define LISTA_SEQUENCIAL_H

#define MAX 25

struct lista{
        int elementos[MAX];
        int particao;
};

void inicializar(struct lista *l);

int inserir_fim(struct lista *l, int valor);
int inserir_inicio(struct lista *l, int valor);
void exibir_lista(struct lista *l);
int concatenar(struct lista *l1, struct lista *l2);
int inserir_posicao(struct lista *l, int valor, int posicao);
int inserir_ordem(struct lista *l, int valor);
void reverso_lista(struct lista *l);
int remover_inicio(struct lista *l);
int remover_fim(struct lista *l);
int remover_posicao(struct lista *l, int posicao);
int remover_valor(struct lista *l, int valor);
int procurar(struct lista *l, int valor);
int somatorio (struct lista *l);
int tamanho(struct lista *l);
void quadrado(struct lista *l);
int quantidade_primos(struct lista *l);
int limpar_lista(struct lista *l);

#endif