#include<stdio.h>
#include<stdlib.h>

struct vector{
    int *buff;
    int arr_size;
    int pos;
    int start;
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
    v->start = 0;
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

int pop_left(struct vector *v){
    if(v->start <= v->pos){
        int res = v->buff[v->start];
        v->start = v->start + 1;
        return res;
    }
    return -1e9;
    
}

void resize_vector(struct vector *v, int new_size){
   
    if( (v->pos) - (v->start) < new_size ){
            int *temp = (int*) malloc(sizeof(int) * new_size);
            int c = 0;
            for(int i = v->start; i <= v->pos; i++){
                temp[c] = v->buff[i];
                c++;
            }
            free(v->buff);
            v->buff = temp;
            v->start = 0;
            v->pos = c;
            v->arr_size = new_size;
    }
}

void check_status(struct vector* v, int print_elements){
    printf("\n------------ Check Status ------------------\n");
    printf("size: %d\n", v->arr_size);
    printf("last pos: %d\n ", v->pos);
    printf("first pos: %d\n", v->start);
    printf("elem num: %d\n", v->pos - v->start);

    if (print_elements){
        for(int i = v->start; i < v->pos; i++){
            printf("%d ", v->buff[i]);
        }
        printf("\n");
    }
    

}

int main(){

    struct vector *v = init(32); // allocated memory for 32 elements

    push(v, 23); 
    push(v, 11);
    push(v, 66);
    int rr = pop_left(v);
    push(v, 99);
    push(v, 101);
    int rr2 = pop(v);
    /*
    while( v->pos >= 0)
        printf("%d\n", pop(v));
    */
    resize_vector(v, 64);

    for(int i = v->start; i < v->pos; i++)
        printf("%d ", v->buff[i]);
   check_status(v, 1); 
    printf("\n");
    
return 0;
}
