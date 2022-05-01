#ifndef STACK_H_
#define STACH_H_

#define CDS_STACK_SIZE_DEFAULT 128

typedef struct {
  void **base;
  unsigned int head;
  unsigned int size;
} cds_stack;

cds_stack *cds_stack_new();
void cds_stack_free(cds_stack *stack);
void *cds_stack_push(cds_stack *stack, void *data);
void *cds_stack_pop(cds_stack *stack);

#endif
