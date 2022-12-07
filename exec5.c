// Escreva um programa que cadastre em uma pilha vários números. A entrada deles será finalizada com a digitação de um número menor ou igual a 0 (zero). Posteriormente, o programa deve gerar duas filas, a primeira com números pares e a segunda com os números ímpares. A saída do programa deve apresentar a pilha digitada e as filas geradas. Caso alguma das filas seja vazia, deve-se mostrar uma mensagem.

// Path: exec6.c

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


// FILA

typedef struct {
    int inicio;
    int fim;
    int dados[MAX];
} Fila;

void inicializaFila(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
}

int insereFila(Fila *f, int x) {
    if (cheia(f)) {
        printf("Fila cheia!");
        return 0;
    }
    f->dados[f->fim++] = x;
    return 1;
}

void imprimeFila(Fila *f) {
    int i;
    for (i = f->inicio; i < f->fim; i++) {
        printf("%d ", f->dados[i]);
    }
    printf("elementos na fila");
}



int main() {
    Pilha pilha;
    Fila f1Par, f2Impar;
    int x;
    inicializa(&pilha);
    inicializaFila(&f1Par);
    inicializaFila(&f2Impar);

    empilha(&pilha, 1);
    empilha(&pilha, 2);
    empilha(&pilha, 3);
    empilha(&pilha, 4);
    empilha(&pilha, 5);

    while (x > 0) {
        printf("Digite um número: ");
        scanf("%d", &x);
        if (x > 0) {
            empilha(&pilha, x);
        }
    }

    while (!vazia(&pilha)) {
        desempilha(&pilha, &x);
        if (x % 2 == 0) {
            insereFila(&f1Par, x);
        } else {
            insereFila(&f2Impar, x);
        }
    }

    printf("Pilha 1: ");
    imprime(&p1);
    printf("Fila Par: ");
    imprimeFila(&f1Par);
    printf("Fila Impar: ");
    imprimeFila(&f2Impar);

    return 0;
}
    