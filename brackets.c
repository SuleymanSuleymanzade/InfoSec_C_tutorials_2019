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

int check(char a, char b){
    if( (a == '(' && b == ')') ||
        (a == '[' && b ==']') ||
        (a == '{' && b == '}')||
        (a == '<' && b == '>')
      )
        return 1;
    return 0;
}

int main(){

    char exp[128] = "{[]()[(<{}>)]}";
    
    struct node* s = NULL;
    int Flag = 1;

    for(long i =0; i < strlen(exp); i++){
        if(exp[i] == ')' || exp[i] == ']' || exp[i] =='}' || exp[i] =='>')
            if( check( top(&s), exp[i]) )
                pop(&s);
            else
                Flag = 0;
        if(exp[i] == '(' || exp[i] =='[' || exp[i] == '{' || exp[i] == '<')
            push(&s, exp[i]);
    }
    if (s == NULL && Flag == 1)
        printf("right order\n");
    else
        printf("wrong order\n");
}
