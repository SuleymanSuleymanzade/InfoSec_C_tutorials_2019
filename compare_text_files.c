#include <stdio.h>
#include <stdlib.h>

void compare(char firstFile[], char secondFile[]);

void main()
{
	char firstFile[15];
	char secondFile[15];

    printf("\nEnter the first file name: ");
    scanf("%s", firstFile);
    printf("\n\rEnter the second file name: ");
    scanf("%s", secondFile);
    compare(firstFile, secondFile);
}


void compare(char firstFile[], char secondFile[])
{
	FILE *f1;
	FILE *f2;
	char c1,c2;
	int flag = 1;

    f1 = fopen (firstFile, "rt");
    f2 = fopen (secondFile, "rt");

    if ((f1 == NULL) || (f2 == NULL))
       exit(1);
    else
    {
       printf("The files %s and %s have been opened \n", firstFile, secondFile);

       for( (fscanf(f1, "%c", &c1)) , (fscanf (f2, "%c", &c2));
            (!feof(f1)) && (!feof (f2)) && flag;
            (fscanf(f1, "%c", &c1)) , (fscanf (f2, "%c", &c2)) 
		  )
          {
             if (c1 != c2)
             {
                printf("\nThe two files are not the same\n");
                flag = 0;                
             }
			 else
				fprintf(stdout,"%c", c1);
          }

          if(flag && feof(f1) && feof(f2))
             printf("\nThe two files are the same\n");
		  else
			  printf("\nThe two files are not the same\n");

          if ((fclose(f1)) || (fclose(f2)))
             exit(1); //the closing wasn't sucssesful
          else
             printf("\nThe files %s and %s have been closed\n", firstFile, secondFile);
    }
}
