#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[]){
   
   //argc - the num of an arguments
   //argv - the arguments (string)
   //example:   ./linux command p1 p2 p3

    for(int i = 0; i < argc; i++){
        printf("%d: %s\n", i, argv[i]);
    }



return 0;
}
