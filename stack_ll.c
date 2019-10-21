#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* init_stack(int data){
    struct node* stack = (struct node*) malloc(sizeof(struct node));
    stack->next = NULL;
    stack->data = data;
    return stack;
}

void push(struct node** stack, int data){
   struct node* nn = init_stack(data);
   if(*stack == NULL){
        *stack = nn;
        return;
   }
   nn->next = *stack;
   *stack = nn;   
}

int top(struct node** stack){
    return (*stack)->data;    
}

void pop(struct node** stack){
    if(*stack == NULL)
        return;
    struct node* temp = *stack;
    *stack = (*stack)->next;
    free(temp);
}

int main(){
    
    struct node *stack = NULL;
    push(&stack, 11);
    push(&stack, 12);
    push(&stack, 543);
    push(&stack, 453);
    
    while(stack != NULL){
        printf("%d ", stack->data);
        pop(&stack);
    }

return 0;
}
