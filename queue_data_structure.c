#include<stdio.h>
#include<stdlib.h>

struct queue{
    int *buff;
    int buff_size;
    int first, last;
    int count;

};

struct queue* init_queue(int buff_size){

    struct queue* q = (struct queue*) malloc(sizeof(struct queue));
    q->buff = (int *) malloc(sizeof(int) * buff_size);
    q->last = q->first = 0;
    q->buff_size = buff_size;
    q->count = 0;
    return q;
}

void enqueue(struct queue* q, int item){
    if(q->count < (q->buff_size - 1)){
        q->buff[q->last] = item;
        q->last = (q->last + 1) % q->buff_size;
        q->count = (q->count) + 1;
    }    
}

int dequeue(struct queue* q){
    int res = -1e9;

    if(q->count > 0){

        res = q->buff[q->first];
        q->first = (q->first + 1) % q->buff_size;
        q->count = (q->count) - 1;

    }
    return res;
}



int main(){


    struct queue *q = init_queue(5);
    enqueue(q, 23);
    enqueue(q, 55);
    enqueue(q, 77);
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    enqueue(q, 77);
    enqueue(q, 88);

    do{
        printf("%d\n", dequeue(q));
    }while(q->last != q->first);




return 0;

}
