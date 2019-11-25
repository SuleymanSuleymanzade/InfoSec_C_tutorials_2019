#include <stdio.h>
#include <stdlib.h>

void copyTextFile(char fromFile[], char toFile[]);

void main()
{
	char fromFile[15];
	char toFile[15];

    printf ("\nEnter file name to copy: ");
    scanf ("%s", fromFile);
    printf ("\nEnter a new file name: ");
    scanf ("%s", toFile);
    copyTextFile(fromFile, toFile);
}

void copyTextFile(char fromFile[], char toFile[])
{
	FILE *fromF;
	FILE *toF;
	char c;

    fromF = fopen (fromFile, "rt");
    toF = fopen (toFile, "wt");

    if ((fromF == NULL) || (toF == NULL))
       exit(1);
    else
    {
       printf("The files %s and %s has been opened \n", fromFile, toFile);
       
       for (fscanf(fromF, "%c", &c); !feof (fromF); fscanf (fromF, "%c", &c))
          fprintf (toF, "%c", c);
       
       if ((fclose(toF)) || (fclose (fromF)))
          exit (1); //the closing wasn't sucssesful
       else
          printf ("\nThe files %s and %s have been closed\n", fromFile, toFile);
    }
}
