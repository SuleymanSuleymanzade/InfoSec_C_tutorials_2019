#include<stdio.h>
#include<stdlib.h>

struct stack{
    int top;
    int *buff;
    int size;
};

struct stack* init_stack(int n_el){
    struct stack* ss = (struct stack*) malloc(sizeof(struct stack));
    ss->top = -1;
    ss->buff = (int*) malloc(sizeof(int) * n_el);
    ss->size = n_el;
    return ss;
}

void push(struct stack* s, int item){
    if(s->top < s->size - 1){
       s->top = s->top + 1;
       s->buff[s->top] = item;         
    }
}

int top(struct stack *s){
    return s->buff[s->top];
}

void pop(struct stack *s){
    if( s->top >= 0){
        s->top = s->top - 1;
    }
}

int is_empty(struct stack *s){
    return s->top == -1;
}

int main(){
    struct stack *s = init_stack(128);
    push(s, 12);
    push(s, 11);
    push(s, 100);

    while(! is_empty(s)){
        printf("%d\n", top(s));
        pop(s);
    }


return 0;
}
