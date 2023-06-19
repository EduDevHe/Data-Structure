#include <stdio.h>

// Constatntes
#define MAX_SIZE_STACK 100 // Constate que define o tamanho da pilha

/**
 * Estrutura de dados que representa uma pilha
 **/
typedef struct {
  int stack[MAX_SIZE_STACK]; // Array de dados
  int top_stack;             // Variável que controla o índice da pilha
} Stack;

/**
 * Metodo reposponsável por iniciar a pilha
 * inicializando a variável top_stack com o valor -1
 * pois os dados armazenados nesta estrutura são armazenados
 * a partir do índice zero.
 **/
void initialize_stack(Stack *stack_r) { stack_r->top_stack = -1; }

void push(Stack *stack_r, int data) {
  /**
   * Verifica se o controlador de índice da pilha e ingual
   * ao tamanho maximo da pilha menos -1 onde caso verdadeiro
   * retorna uma menssagem de erro.
   * **/
  if (stack_r->top_stack == MAX_SIZE_STACK - 1) {
    printf("Pilha cheia");
    return;
  }

  // Incrmenta o contraldor de índice.
  stack_r->top_stack++;
  // Insere o dado com base em seu índice.
  stack_r->stack[stack_r->top_stack] = data;
}

/**
 * Metodo reposponsável por remover o ultimo elemento inserido
 * na pilha.
 * */
int pop(Stack *stack_r) {
  /**
   * Verifica se o contraldor de índice da pilha é igual a -1
   * simbolizando que a mesma está vazia.
   * */
  if (stack_r->top_stack == -1) {
    printf("A pilha esta vazia");
    return -1;
  }

  // Atribui o valor que está contido no topo da pilha a variável data.
  int data = stack_r->stack[stack_r->top_stack];
  // Decrementa o contraldor de índice.
  stack_r->top_stack--;
  // Retorna o dado.
  return data;
}

/**
 * Metodo reposponsável por retorna o elemento do
 * topo da pilha.
 **/
int peek(Stack *stack_r) {
  /**
   * Verifica se o contraldor de índice da pilha é igual a -1
   * simbolizando que a mesma está vazia.
   * */
  if (stack_r->top_stack == -1) {
    printf("A pilha esta vazia");
    return -1;
  }
  // Retrona o dado que esta no topo da pilha.
  return stack_r->stack[stack_r->top_stack];
}

/** Metodo reposponsável por exibir todos os elementos
 *  da pilha.
 * */
void display_stack(Stack *stack_r) {
  /**
   * Verifica se o contraldor de índice da pilha é igual a -1
   * simbolizando que a mesma está vazia.
   * */
  if (stack_r->top_stack == -1) {
    printf("A pilha esta vazia");
    return;
  }

  printf("\n");
  // Percorre a a pilha e exibe os elementos.
  printf("[");
  for (int i = 0; i <= stack_r->top_stack; i++) {
    printf(",%d", stack_r->stack[i]);
  }
  printf("]");
}

int main() {

  Stack stack;

  initialize_stack(&stack);
  // Preech a pilha.
  for (int i = 1; i <= 10; i++) {
    push(&stack, i);
  }

  printf("\n");
  printf("Elementos da pilha: ");
  display_stack(&stack);
  printf("\n");
  printf("Elemento do top %d\n", peek(&stack));

  return 0;
}
