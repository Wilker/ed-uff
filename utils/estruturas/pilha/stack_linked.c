#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

typedef struct node {
	int value;
	struct node *next;
} Node;

typedef struct stack {
	Node *head;
} Stack;

Stack *new_stack (void) {
	Stack *stack = (Stack*) malloc(sizeof(Stack));
	stack->head = NULL;
	return stack;
}

void push (Stack *st, int value) {
	if(!st) exit(1);
	Node *node = (Node*) malloc(sizeof(Node));
	node->value = value;
	node->next = st->head;
	st->head = node;
}

int pop (Stack *st) {
	if(!st || !st->head) exit(1);
	Node *temp = st->head;
	st->head = st->head->next;
	int value = temp->value;
	free(temp);
	return value;
}

int is_empty (Stack *st) {
	if(!st) exit(1);
	return st->head == NULL;
}

int size(Stack *st) {
	if(!st) exit(1);
	int count = 0;
	Node *node = st->head;
	while(node) {
		count++;
		node = node->next;
	}
	return count;
}

void free_stack (Stack *st) {
	if(!st) exit(1);
	free(st->head);
	free(st);
}

void print_stack(Stack *st) {
	if(!st) exit(1);
	Node *node = st->head;
	while(node) {
		printf("%d\n", node->value);
		node = node->next;
	}
}