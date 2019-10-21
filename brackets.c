#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    char data;
    struct node* next;
};

struct node* init_stack(char data){
    struct node* stack = (struct node*) malloc(sizeof(struct node));
    stack->next = NULL;
    stack->data = data;
    return stack;
}

void push(struct node** stack, char data){
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
/*  
    char[128] expression = "{[]()[({})]}";
    
    if (check_expression(expression))
        printf("right order brackets\n");
    else
        printf("wrong order\n");

*/

    char w[128];
    scanf("%s", w);

    printf("%s\n", w);
    printf("%ld\n", strlen(w));

return 0;
}
