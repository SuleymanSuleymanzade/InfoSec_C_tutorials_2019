#include<stdio.h>
#include<stdlib.h>
// hello
struct vector{
    int *buff;
    int arr_size;
    int pos;
};

/*
    this function creates the vector object
    creates the space for data (buff)
    sets the positioner to -1 (initially)
    and returns the pointer to an object
*/
struct vector* init(int size){
    struct vector *v = (struct vector *) malloc(sizeof(struct vector));
    v->buff = (int*) malloc(sizeof(int) * size); // create the array 
    v->arr_size = size;
    v->pos = -1; 
    return v;
}

void push(struct vector *v, int data){
    if(v->pos >= v->arr_size)
        return;
    v->pos = (v->pos)+1; // change the positioner to the next free space
    v->buff[v->pos] = data; //set the data in space shown by the positioner
}

int pop(struct vector *v){
    if(v->pos <= -1)
        return -1e9;

    int res = v->buff[v->pos--];
    return res;    
}

int main(){

    struct vector *v = init(32); // allocated memory for 32 elements

    push(v, 23); 
    push(v, 11);
    push(v, 66);
    
    while( v->pos >= 0)
        printf("%d\n", pop(v));

return 0;
}
