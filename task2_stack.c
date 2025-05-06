#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct stack_elem {
    double value;
    struct stack_elem *prev_elem;
} st_elem;

void push(st_elem **stack, double value) {
    st_elem *tmp = NULL;
    tmp = (st_elem *)malloc(sizeof(st_elem));
    if (tmp) {
        tmp->value = value;
        tmp->prev_elem = *stack;
        *stack = tmp;
    }
    else {
        printf("push(): not enough memory\n");
    }
}

double pop(st_elem **stack) {
    double res = 0.0;
    st_elem *tmp = NULL;
    if (*stack) {
        res = (*stack)->value;
        tmp = *stack;
        *stack = tmp->prev_elem;
        free(tmp);
    }
    else {
        printf("pop(): stack is empty\n");
    }
    return res;
}

void clear_stack(st_elem **stack) {
    st_elem *tmp = NULL;
    int k = 0;
    tmp = *stack;
    while (tmp) {
        *stack = tmp->prev_elem;
        free(tmp);
        tmp = *stack;
        k++;
    }
    printf("clear_stack(): %d elements freed\n", k);
    printf("clear_stack(): stack is empty\n");
}
