#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

struct Node {
    int number;
    struct Node *next;
};

struct Node *head = NULL;

struct Stack {
    struct Node *top;
    /* Determina a quantidade máxima de itens que a pilha pode comportar */
    int max_items;

    /* Indica a quantidade de elementos presentes na pilha */
    int qty;
};
struct Stack *stack;


void push(Stack *stack, int number) {
    if (stack->qty == stack->max_items) {
        printf("Pilha cheia!");
        return;
    }

    Node *node = (Node *) malloc(sizeof(Node));
    node->number = number;
    node->next = stack->top;
    stack->top = node;
    stack->qty++;
}

// Remove o elemento do topo da pilha
int pop(Stack *stack) {
    if (is_empty(stack)) {
        printf("Pilha vazia!");
        return -1;
    }

    Node *node = stack->top;
    int number = node->number;
    stack->top = node->next;
    stack->qty--;
    free(node);
    return number;
}


// Está vazia?
int is_empty(Stack *stack) {
    return stack->qty == 0;
}

// Está cheia?
int is_full(Stack *stack) {
    return stack->qty == stack->max_items;
}

// Quantidade de elementos na pilha
int size(Stack *stack) {
    return stack->qty;
}

// Verifica se existe um elemento especifico na pilha
void contains(Stack *stack, int number) {
    Node *node = stack->top;
    while (node != NULL) {
        if (node->number == number) {
            return 1;
        }
        node = node->next;
    }
}

// Exibe todos os elementos da pilha
void listaTudo(Stack *stack) {
    Node *node = stack->top;
    while (node != NULL) {
        printf("%d ", node->number);
        node = node->next;
    }
    printf("quantidade de elementos: %d", stack->qty);
}


int main(void){
    // chama as funcoes de acordo com o que escolher
    int escolha = 0;

    while (escolha != 8) {
        printf("1 - Inserir elemento na pilha");
        printf("2 - Remover elemento da pilha");
        printf("3 - Verificar se a pilha está vazia");
        printf("4 - Verificar se a pilha está cheia");
        printf("5 - Ver quantidade de elementos na pilha");
        printf("6 - Verificar se existe um elemento na pilha");
        printf("7 - Exibir todos os elementos da pilha");
        printf("8 - Sair");
        scanf("%d", &escolha);

        if(escolha == 1){
            int number;
            printf("Digite o numero que deseja inserir na pilha: ");
            scanf("%d", &number);
            push(&stack, number);
        } else if(escolha == 2){
            int number = pop(&stack);
            printf("Elemento removido: %d", number);
        } else if(escolha == 3){
            int empty = is_empty(&stack);
            if(empty == 1){
                printf("A pilha está vazia!");
            } else {
                printf("A pilha não está vazia!");
            }
        } else if(escolha == 4){
            int full = is_full(&stack);
            if(full == 1){
                printf("A pilha está cheia!");
            } else {
                printf("A pilha não está cheia!");
            }
        } else if(escolha == 5){
            int size = size(&stack);
            printf("A pilha possui %d elementos", size);
        } else if(escolha == 6){
            int number;
            printf("Digite o numero que deseja verificar se existe na pilha: ");
            scanf("%d", &number);
            int contains = contains(&stack, number);
            if(contains == 1){
                printf("O elemento %d existe na pilha!", number);
            } else {
                printf("O elemento %d não existe na pilha!", number);
            }
        } else if(escolha == 7){
            listaTudo(&stack);
        } else if(escolha == 8){
            printf("Saindo...");
        } else {
            printf("Opção inválida!");
        }
    }

    return 0;
}
