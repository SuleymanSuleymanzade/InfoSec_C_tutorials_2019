#include<stdio.h>
#include<stdlib.h>

struct queue{
    int *buff;
    int buff_size;
    int first, last;

};

struct queue* init_queue(int buff_size){

    struct queue* q = (struct queue*) malloc(sizeof(struct queue));
    q->buff = (int *) malloc(sizeof(int) * buff_size);
    q->last = q->first = 0;
    q->buff_size = buff_size;
    return q;
}

void enqueue(struct queue* q, int item){
    if(q->last < q->buff_size){
        q->buff[q->last] = item;
        q->last = (q->last) + 1;
    }    
}

int dequeue(struct queue* q){
    int res = -1e9;

    if(q->last != q->first){

        res = q->buff[q->first];
        q->first = (q->first) + 1;

    }
    return res;
}



int main(){


    struct queue *q = init_queue(16);
    enqueue(q, 23);
    enqueue(q, 55);
    enqueue(q, 77);
    enqueue(q, 88);

    while(q->last != q->first){
        printf("%d\n", dequeue(q));
    }


return 0;

}
