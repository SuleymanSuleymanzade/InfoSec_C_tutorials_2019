#include<stdio.h>
#include<string.h>

int main(){

    char word[128];

    fgets(word, strlen(word),stdin);
    
    int diff = 'a' - 'A';

    for(long i = 0; i < strlen(word); i++){
        if(word[i] >= 'a' && word[i] <= 'z')
            word[i] -= diff;
    }
    printf("%s\n", word);

return 0;
}
