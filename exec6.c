#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30

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
  strcpy(p->nome, "Gato");
  strcpy(p->pais, "Chile");
  p->especial = 0;
  strcpy(p->tipo, "Suave");
  p->safra = 0;
}

int vazia(Pilha *p) { return p->topo == -1; }

int cheia(Pilha *p) { return p->topo == MAX - 1; }

int empilha(Pilha *p, char nome[MAX], char pais[MAX], char tipo[MAX], int safra,
            int especial, int x) {
  if (cheia(p)) {
    printf("Pilha cheia!");
    return 0;
  }
  p->topo = x;
  // p->nome[++p->topo] = nome;
  strcpy(p->nome[++p->topo], nome);
  p->pais[++p->topo] = pais;
  p->tipo[++p->topo] = tipo;
  // p->safra[++p->safra] = safra;
  // p->especial[++p->topo] = especial;

  return 1;
}

int desempilha(Pilha *p, int *x) {
  if (vazia(p)) {
    printf("Pilha vazia!");
    return 0;
  }
  p[p->topo--];
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
  printf("O vinho selecionado para essa ocasiao especial eh: %c \n",
         p->nome[quantidadeTotal]);
  // desempilha(p, p[quantidadeTotal]);
}

void buscarVinho(Pilha *p, int safra) {
  int i;
  for (i = p->topo; i >= 0; i--) {
    if (p[i].safra == safra) {
      printf("Um dos vinho selecionado para essa ocasiao especial eh: %d \n",
             p->nome[i]);
      // desempilha(p, p[i].topo);
    }
  }
}

void imprimir5PrimeirasAdicionadas(Pilha *p) {
  int i;
  int quantidadeTotal = count(p);
  for (i = quantidadeTotal; i >= quantidadeTotal - 5; i--) {
    printf("Esse eh um dos vinhos mais antigos: %d \n", p->nome[i]);
  }
}

void imprimir5UltimasAdicionadas(Pilha *p) {
  int i;
  int quantidadeTotal = count(p);
  for (i = 0; i <= 5; i++) {
    printf("Esse eh um dos vinhos mais recentes: %d \n", p->nome[i]);
  }
}

int main() {
  Pilha vinhos;
  int x;
  int resposta;
  inicializa(&vinhos);

  // receber dados do cliente
  while (1) {
    printf("Menu de opcoes: \n");
    printf("1 - Incluir vinhos \n");
    printf("2 - Abrir vinho sem ocasiao especial \n");
    printf("3 - Abrir vinho em ocasiao£o especial \n");
    printf("4 - Relacionar as cinco aquisicoes mais antigas \n");
    printf("5 - Relacionar as cinco aquisicoes mais recentes \n");
    printf("Digite a opcao desejada: ");
    scanf("%d", &resposta);

    if (resposta == 1) {
      printf("Digite o nome do vinho: \n");
      scanf("%s", &vinhos.nome);
      // strcpy(&vinhos.nome);
      // fgets(&vinhos.nome, MAX, stdin);

      printf("Digite o pais de origem: \n");
      scanf("%s", &vinhos.pais);
      printf("Digite o tipo de uva: \n");
      scanf("%s", &vinhos.tipo);
      printf("Digite a safra: \n");
      scanf("%d", &vinhos.safra);
      printf(
          "Especial? (1 - sim, 0 - nao): \n"); // Permite criar estruturas para
                                               // o armazenamento de vinhos para
                                               // ocasiÃµes especiais;
      scanf("%d", &vinhos.especial);
      printf("Digite 1 para continuar ou 0 para sair: \n");
      scanf("%d", &x);
    }

    if (resposta == 2) {
      vinhoMaisAntigo(&vinhos);
    }

    if (resposta == 3) {
      // abrir vinho em ocasiÃ£o especial
      printf("Digite a safra do vinho: ");
      scanf("%d", &vinhos.safra);
      buscarVinho(&vinhos, vinhos.safra);
    }

    if (resposta == 4) {
      // relacionar as cinco aquisiÃ§Ãµes mais antigas
      imprimir5PrimeirasAdicionadas(&vinhos);
    }

    if (resposta == 5) {
      // relacionar as cinco aquisiÃ§Ãµes mais recentes
      imprimir5UltimasAdicionadas(&vinhos);
    }

    if (x == 0) {
      break;
    }
  }

  return 0;
}
