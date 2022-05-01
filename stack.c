#include <stdlib.h>

#include "stack.h"

cds_stack *cds_stack_new() {
  cds_stack *stack = malloc(sizeof(cds_stack));
  if (stack == NULL)
    return NULL;

  stack->base = calloc(CDS_STACK_SIZE_DEFAULT, sizeof(void*));
  if (stack->base == NULL) {
    free(stack);
    return NULL;
  }

  stack->head = 0;
  stack->size = CDS_STACK_SIZE_DEFAULT;

  return stack;
}

void cds_stack_free(cds_stack *stack) {
  free(stack->base);
  free(stack);
}

void *cds_stack_push(cds_stack *stack, void *data) {
  if (stack->head >= stack->size) {
    stack->size *= 2;
    if ((stack->base = reallocarray(stack->base, stack->size, sizeof(void*))) == NULL)
      return NULL;
  }

  *(stack->base + stack->head) = data;

  return *(stack->base + stack->head++);
}

void *cds_stack_pop(cds_stack *stack) {
  if (stack->head == 0)
    return NULL;

  return *(stack->base + --stack->head);
}
