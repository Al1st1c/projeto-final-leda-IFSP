#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

typedef struct {
    int topo;
    int dados[MAX];
} Pilha;

void inicializa(Pilha *p) {
    p->topo = -1;
}

int vazia(Pilha *p) {
    return p->topo == -1;
}

int cheia(Pilha *p) {
    return p->topo == MAX - 1;
}

int empilha(Pilha *p, int x) {
    if (cheia(p)) {
        printf("Pilha cheia!");
        return 0;
    }
    p->dados[++p->topo] = x;
    return 1;
}

int desempilha(Pilha *p, int *x) {
    if (vazia(p)) {
        printf("Pilha vazia!");
        return 0;
    }
    *x = p->dados[p->topo--];
    return 1;
}

void imprime(Pilha *p) {
    int i;
    for (i = p->topo; i >= 0; i--) {
        printf("%d ", p->dados[i]);
    }
    printf("elementos na pilha");
}

int main() {
    Pilha p1, p2, p3;
    int x;
    inicializa(&p1);
    inicializa(&p2);
    inicializa(&p3);
    empilha(&p1, 1);
    empilha(&p1, 2);
    empilha(&p1, 3);
    empilha(&p1, 4);
    empilha(&p1, 5);

    empilha(&p2, 6);
    empilha(&p2, 7);
    empilha(&p2, 8);
    empilha(&p2, 9);
    empilha(&p2, 10);
    while (!vazia(&p1)) {
        desempilha(&p1, &x);
        empilha(&p3, x);
    }
    while (!vazia(&p2)) {
        desempilha(&p2, &x);
        empilha(&p3, x);
    }
    imprime(&p3);
    return 0;
}