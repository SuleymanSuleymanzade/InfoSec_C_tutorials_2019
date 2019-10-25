#include<stdio.h>
#include<stdlib.h>

int main(){

    FILE *file = fopen("dummy.txt", "r");
    
    if( file == NULL){
        printf("Error in reading \n");
        exit(1);
    }

    // char by char
    /*

    char c;
    while((c = fgetc(file)) != EOF){
        putchar(c);
    }  
    */

    char buff[128];
 
    while(fgets(buff, 128, file)){

            fputs(buff, stdout);
    }

    fclose(file);


return 0;
}
