#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>

#define ROW 128
#define COL 64

struct notebook{
    char buff[ROW][COL];
    int last;
};

struct notebook* init(){
    struct notebook* nn = (struct notebook*) malloc(sizeof(struct notebook));
    nn->last = -1;
    return nn;
}

void add(struct notebook* nn, char* name, char* sname, char* phone){
    assert(strlen(name) < 15);
    assert(strlen(sname) < 15);
    assert(strlen(phone) < 15);

    nn->last = nn->last + 1;
    if (nn->last < ROW){
        int an = 0;
        for(int i = 0; i < strlen(name); i++){
            nn->buff[nn->last][an++] = name[i];
        }
        an = 15;
        for(int i = 0; i < strlen(sname); i++){
            nn->buff[nn->last][an++] = sname[i];
        }
        an = 30;
        for(int i = 0; i < strlen(phone); i++){
            nn->buff[nn->last][an++] = phone[i];
        }
    }
}



int main(){
    char *cmd, *name, *sname, *phone;
    struct notebook *nn = init();
    while(1){
        scanf("%s", cmd);
        if(strcmp(cmd, "add")==0){
            scanf("%s", name);
            scanf("%s", sname);
            scanf("%s", phone);

            add(nn, name, sname, phone);
        }
        for(int i = 0; i <= nn->last; i++){
             
        
        }
        
    }

return 0;
}
