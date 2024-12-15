
#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_SIZE 100

typedef struct
{
    int stack[MAX_SIZE];
    int top;
} Stack;

void init_stack(Stack *s);
void print_stack(Stack *s);
int push_to_a(Stack *a, Stack *b);
int push_to_b(Stack *b, Stack *a);
int swap_a(Stack *a);
int swap_b(Stack *b);
int swap_both(Stack *a, Stack *b);
int rotate_a(Stack *a);
int rotate_b(Stack *b);
int rotate_both(Stack *a, Stack *b);
int reverse_rotate_a(Stack *a);
int reverse_rotate_b(Stack *b);
int reverse_rotate_both(Stack *a, Stack *b);
int pop(Stack *s);
int quicksort(Stack *a, Stack *b);
int separate(Stack *a, Stack *b, int pivot);

#endif