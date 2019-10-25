#include<stdio.h>
#include<stdlib.h>

int main(){

    FILE *file = fopen("dummy.txt", "a");
    int n;

    printf("enter the number of lines: ");
    scanf("%d", &n);
    
    printf("write something to the file:\n");
    char buff[128];
    
    while(n--){
        fgets(buff, 128, stdin);
        fputs(buff, file);
    }
    fclose(file);

}
