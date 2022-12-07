#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

typedef struct {
    int topo;
    char nome[MAX];
    char pais[MAX];
    int especial;
    char tipo[MAX];
    int safra;
} Pilha;

void inicializa(Pilha *p) {
    p->topo = -1;
    p->nome = "";
    p->pais = "";
    p->especial = 0;
    p->tipo = "";
    p->safra = 0;
}

int vazia(Pilha *p) {
    return p->topo == -1;
}

int cheia(Pilha *p) {
    return p->topo == MAX - 1;
}

int empilha(Pilha *p, char nome[MAX], char pais[MAX], char tipo[MAX], int safra, int especial, int x) {
    if (cheia(p)) {
        printf("Pilha cheia!");
        return 0;
    }
    p->dados[++p->topo] = x;
    p->dados[++p->nome] = nome;
    p->dados[++p->pais] = pais;
    p->dados[++p->tipo] = tipo;
    p->dados[++p->safra] = safra;
    p->dados[++p->especial] = especial;

    
    return 1;
}

int desempilha(Pilha *p, int *x) {
    if (vazia(p)) {
        printf("Pilha vazia!");
        return 0;
    }
    *x = p[p->topo--];
    return 1;
}

void imprime(Pilha *p) {
    int i;
    for (i = p->topo; i >= 0; i--) {
        printf("%d ", p->nome[i]);
    }
    printf("elementos na pilha");
}

int count(Pilha *p) {
    int i;
    int count = 0;
    for (i = p->topo; i >= 0; i--) {
        count++;
    }
    return count;
}

void vinhoMaisAntigo(Pilha *p) {
    int quantidadeTotal = count(p);
    // imprimir o ultimo vinho adicionado
    printf("O vinho selecionado para essa ocasiao especial eh: %d", p->nome[quantidadeTotal]);
    desempilha(p, p[quantidadeTotal]);
}

void buscarVinho(Pilha *p, int safra) {
    int i;
    for (i = p->topo; i >= 0; i--) {
        if (p->safra[i] == safra) {
            printf("O vinho selecionado para essa ocasiao especial eh: %d", p->nome[i]);
            desempilha(p, p[i]);
        }
    }
}

void imprimir5PrimeirasAdicionadas(Pilha *p) {
    int i;
    int quantidadeTotal = count(p);
    for (i = quantidadeTotal; i >= quantidadeTotal - 5; i--) {
        printf("Esse eh um dos vinhos mais antigos: %d", p->nome[i]);
    }
}

void imprimir5UltimasAdicionadas(Pilha *p) {
    int i;
    int quantidadeTotal = count(p);
    for (i = 0; i <= 5; i++) {
        printf("Esse eh um dos vinhos mais recentes: %d", p->nome[i]);
    }
}

int main() {
    Pilha vinhos;
    int x;
    int resposta;
    inicializa(&vinhos);

    // receber dados do cliente
    while (1) {
        printf("Menu de opcoes: ");
        printf("1 - Incluir vinhos");
        printf("2 - Abrir vinho sem ocasião especial");
        printf("3 - Abrir vinho em ocasião especial");
        printf("4 - Relacionar as cinco aquisições mais antigas");
        printf("5 - Relacionar as cinco aquisições mais recentes");
        printf("Digite a opcao desejada: ");
        scanf("%d", &resposta);

        if(resposta == 1){
            printf("Digite o nome do vinho: ");
            scanf("%s", &vinhos.nome);
            printf("Digite o pais de origem: ");
            scanf("%s", &vinhos.pais);
            printf("Digite o tipo de uva: ");
            scanf("%s", &vinhos.tipo);
            printf("Digite a safra: ");
            scanf("%d", &vinhos.safra);
            printf("Especial? (1 - sim, 0 - nao): "); // Permite criar estruturas para o armazenamento de vinhos para ocasiões especiais;
            scanf("%d", &vinhos.especial);
            printf("Digite 1 para continuar ou 0 para sair: ");
            scanf("%d", &x);
        }

        if(resposta == 2){ 
            vinhoMaisAntigo(&vinhos);
        }

        if(resposta == 3){
            // abrir vinho em ocasião especial
            printf("Digite a safra do vinho: ");
            scanf("%d", &vinhos.safra);
            buscarVinho(&vinhos, vinhos.safra);
        }

        if(resposta == 4){
            // relacionar as cinco aquisições mais antigas
            imprimir5PrimeirasAdicionadas(&vinhos);
        }

        if(resposta == 5){
            // relacionar as cinco aquisições mais recentes
            imprimir5UltimasAdicionadas(&vinhos);
        }



        if (x == 0) {
            break;
        }
    }


    return 0;
}