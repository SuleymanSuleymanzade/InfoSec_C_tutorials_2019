#include<stdio.h>
#include<sys/types.h>
#include<dirent.h>
#include<string.h>
#include<unistd.h> // for getcwd

#define FILENAMESIZE 128

void list_dirs(char* path, int rec){

    DIR* dir = opendir(path);
    struct dirent* dir_walk;
    char new_path[FILENAMESIZE];

    if (!dir)
        return;

    while((dir_walk = readdir(dir)) != NULL){
        if(rec){ 
            if(strcmp(dir_walk->d_name, ".") != 0 && strcmp(dir_walk->d_name, "..") !=0 ){
            
                printf("%s\n", dir_walk->d_name);
                strcpy(new_path, path);
                strcat(new_path, "/");
                strcat(new_path, dir_walk->d_name);
                list_dirs(new_path, 1);
            }
        }
        else{
            printf("%s\n", dir_walk->d_name);
        }
    }
    closedir(dir);
}

int main(int argc, char *argv[]){
    
    char cwd[FILENAMESIZE];

    if(argc < 2 && getcwd(cwd, sizeof(cwd)) != NULL)
        // call without any options and path
        list_dirs(cwd, 0);
    
    else if(argc == 2){
        //call whithout options, but with path
        list_dirs(argv[1], 0);
    }

    if(argc == 3){
        // call with options and path
        if(strcmp(argv[1], "-R") == 0)
            //recursive call
            list_dirs(argv[2], 1);
    }

return 0;
}
