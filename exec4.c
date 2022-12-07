//Escreva uma função que receba três filas, duas já preenchidas em ordem crescente e preencha a última com os valores das duas primeiras em ordem crescente.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

typedef struct {
    int inicio;
    int fim;
    int dados[MAX];
} Fila;

void inicializa(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
}

int vazia(Fila *f) {
    return f->inicio == f->fim;
}

int cheia(Fila *f) {
    return f->fim == MAX;
}

int insere(Fila *f, int x) {
    if (cheia(f)) {
        printf("Fila cheia!");
        return 0;
    }
    f->dados[f->fim++] = x;
    return 1;
}

int remove(Fila *f, int *x) {
    if (vazia(f)) {
        printf("Fila vazia!");
        return 0;
    }
    *x = f->dados[f->inicio++];
    return 1;
}

void imprime(Fila *f) {
    int i;
    for (i = f->inicio; i < f->fim; i++) {
        printf("%d ", f->dados[i]);
    }
}

int main() {
    Fila f1, f2, f3;
    int x;
    inicializa(&f1);
    inicializa(&f2);
    inicializa(&f3);
    insere(&f1, 1);
    insere(&f1, 2);
    insere(&f1, 3);
    insere(&f1, 4);
    insere(&f1, 5);

    insere(&f2, 6);
    insere(&f2, 7);
    insere(&f2, 8);
    insere(&f2, 9);
    insere(&f2, 10);
imprime(&f1);
    imprime(&f2);
    while (!vazia(&f1) && !vazia(&f2)) {
        if (f1.dados[f1.inicio] < f2.dados[f2.inicio]) {
            insere(&f3, f1.dados[f1.inicio]);
            f1.inicio++;
        } else {
            insere(&f3, f2.dados[f2.inicio]);
            f2.inicio++;
        }
    }


    
    imprime(&f3);
    return 0;
}