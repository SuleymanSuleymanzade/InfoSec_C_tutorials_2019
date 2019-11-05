#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BUFFSIZE 128

/*============================================================================
 * this program works in two modes add and process
 * [OPTION] 
 *     -add (a) adds argument to the file  {prog_file}_data.txt
 *     -get (g) gets the datas from the file (by default no arguments)
 *     -clear (c) clears the content of the file
 *     -delete (d) removes the buffer file
 * [No OPTION]
 *    add all the data from the {prog_file}_data.txt to the
 *    linked list data structure and then the program process the data (prints)
=============================================================================*/

struct node{
    struct node *next;
    char data[BUFFSIZE];
};

void process_data(char* data){
    // can be other logic for processing the data
    printf("%s", data);
}

void append(struct node** head, char* data){
    struct node* nn = (struct node*) malloc(sizeof(struct node));
    strcpy(nn->data, data);
    nn->next = NULL;
    
    if(*head == NULL){
        *head = nn;
        return;
    }
    struct node* walk = *head;
    while(walk->next != NULL){
        walk = walk->next;
    }
    walk->next = nn;
}

void traverse(struct node** head){
    struct node *walk = *head;
    while(walk != NULL){
        process_data(walk->data);
        walk = walk->next;
    }
}

void filename_util(char *file_name){
    int c = 0;
    const int cut_from = 2;
    long str_length = strlen(file_name);
    
    if(str_length < cut_from)
        return;
    
    for(int i = cut_from; i < str_length; i++)
        file_name[c++] = file_name[i];

    file_name[c] = '\0'; 
    strcat(file_name, "_data.txt\0");
}

void destroy_list(struct node** head){
    struct node* curr = *head;
    struct node* next;
    while(curr != NULL){
        next = curr->next;
        free(curr);
        curr = next;
    }
    *head = NULL;
}

int main(int argc, char* argv[]){

    FILE *file;
    char filename[BUFFSIZE];

    strcpy(filename, argv[0]);
    filename_util(filename);

    if(argc > 1 && ((strcmp(argv[1], "-add") == 0) || strcmp(argv[1], "a") == 0)){
        
        // add parameters to the text file (-add mode)

        file = fopen(filename, "a");
        for(int i = 2; i < argc; i++){
            fputs(argv[i], file);
            fputs("\n", file);
        }

        fclose(file);
    }
    else if(argc > 1 && ((strcmp(argv[1], "-clear") == 0) || strcmp(argv[1], "c") == 0)){
        //delete the content of the file
        fclose(fopen(filename, "w"));
    }   
    else if(argc > 1 && ((strcmp(argv[1], "-delete") == 0) || strcmp(argv[1], "d") == 0)){
        //remove the file itsef
        int res = remove(filename);
        if(!res)
            printf("The buffer has been deleted successfully\n");
        else
            printf("ERROR: Unable to delete the file\n");
    }
    else if( (argc > 1 && ((strcmp(argv[1], "-get") == 0) || strcmp(argv[1], "g") == 0)) || (argc == 1)){
        // read mode (no option)
        struct node* datas = NULL;
        file = fopen(filename, "r");
        char buff[BUFFSIZE];

        if(!file){
            printf("ERROR: the file %s has not been created\n", filename);
            printf("use the -add [a] parameter to add the data\n");
            exit(1);
        }
        
        while(fgets(buff, BUFFSIZE, file) != NULL){ 
            append(&datas, buff);
        }
        traverse(&datas);
        destroy_list(&datas);
        fclose(file);

    }else{
        printf("Unknown command\n");
    }
    
return 0;
}
