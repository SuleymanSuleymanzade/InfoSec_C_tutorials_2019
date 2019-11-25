#include<stdio.h>
#include<string.h>


struct partition{
    int col[128];
    int row[128];
    int r, c;
};

struct partition* init_part(int r, int c, int size_r, int size_c){
    struct partition *p = (struct partition*) malloc(sizeof(struct partition));
    p->c = -1;
    p->r = -1;
    int size_r_int = size_r / r;
    int size_c_int = size_c / c;
    
    int last_r_int = 0;
    int last_c_int = 0
    for(int  i = 0; i <= r; i++){
        p->r = p->r + 1;
        p->row[p->r] = last_r_int;
        last_r_int += size_r_int;
    }

}


void name_generator(char* new_name, int r, int c){
    strcpy(new_name, f);
    strcat(f, itoa(r));
    strcat(f, itoa(c));
    strcat(f, ".txt");
}






