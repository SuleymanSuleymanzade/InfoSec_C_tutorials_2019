#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int atoi2(char *num){
    int r = 0;
    for(int i = 0; num[i] >= '0' && num[i] <= '9'; i++){        
        r = r * 10 + (num[i] - '0');
    }
    return r;
}

int main(int argc, char *argv[]){
    
    if(argc != 4)
        exit(1);
    
    char op[80], n1[80], n2[80];

    strcpy(op, argv[1]);
    strcpy(n1, argv[2]);
    strcpy(n2, argv[3]);

    int res;
    if(strcmp(op, "sum") == 0){
        res = atoi2(n1) + atoi2(n2);
    }
    if(strcmp(op, "sub") == 0){
        res = atoi2(n1) - atoi2(n2);
    }
    printf("%d\n", res);

}
