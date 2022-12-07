#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

struct Node {
    int number;
    Node next;
};

struct Queue {
    Node head; //Nó inicial da fila
    Node tail; //Nó final da fila
    
    /* Determina a quantidade máxima de itens que a fila pode comportar */
    int max_items;

    /* Indica a quantidade de elementos presentes na fila */
    int qty;
};

// qtd on queue
int tamanhoFila(Queue *queue) {
    return queue->qty;
}

// queue is full?
int taCheio(Queue *queue) {
    return queue->qty == queue->max_items;
}

// queue is empty?
int taVazio(Queue *queue) {
    return queue->qty == 0;
}

// verify if one element is present
int contains(Queue *queue, int number) {
    Node *node = queue->head;
    while (node != NULL) {
        if (node->number == number) {
            return 1;
        }
        node = node->next;
    }
    return 0;
}

// return all elements 
int *elements(Queue *queue) {
    int *elements = (int *) malloc(sizeof(int) * queue->qty);
    Node *node = queue->head;
    int i = 0;
    while (node != NULL) {
        elements[i++] = node->number;
        node = node->next;
    }
    return elements;
}

// insert element in queue
void inserir(Queue *queue, int number) {
    if (is_full(queue)) {
        printf("Fila cheia!");
        return;
    }

    Node *node = (Node *) malloc(sizeof(Node));
    node->number = number;
    node->next = NULL;

    if (is_empty(queue)) {
        queue->head = node;
    } else {
        queue->tail->next = node;
    }
    queue->tail = node;
    queue->qty++;
}

// remove element in queue
int remover(Queue *queue) {
    if (is_empty(queue)) {
        printf("Fila vazia!");
        return -1;
    }

    Node *node = queue->head;
    int number = node->number;
    queue->head = node->next;
    queue->qty--;
    free(node);
    return number;
}