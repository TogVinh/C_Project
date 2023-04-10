#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// remove "\n" form fgets 
#define strcut_newline(str) ((str)[strlen(str) - 1] == '\n')? (str)[strlen(str) - 1] = '\0':0;

void readFile ()
{
	FILE*f_readFile = NULL;
	char filePath[50] = {'0'};

	puts("Enter the path of the file to read : ");
	fgets(filePath, 50, stdin);
    fgets(filePath, 50, stdin);
    strcut_newline(filePath);

	f_readFile = fopen( filePath , "r+" );
	if ( f_readFile == NULL )
	{
		printf("\n Open Error! ");
		return;
	}
	else
	{
		printf(" \nSao chep vao mang");
		printf( "\nsao chep thanh cong " );
        //printf("path file : %s", filePath);
        puts(filePath);
	}
	
	fclose (f_readFile);
}

void writeFile()
{
	FILE *f_writeFile = NULL;
	char filePath[50];

	puts("Enter the path of file to write ");
	fgets(filePath, 50, stdin);
    fgets(filePath, 50, stdin);
    strcut_newline(filePath);

	f_writeFile = fopen( filePath, "w+" );
	if (f_writeFile == NULL)
	{
		printf("\nCan't write to file ");
		return;
	}
	else
	{
		printf("\nghi file thanh cong");
        printf("\npath of file : ");
        //printf("path file : %s", filePath);
        puts(filePath);
	}
	
	fclose(f_writeFile);
}


int main()
{
	
	int choose;
	printf("\n=========== Selection ============\n");
	printf("   Press 1 -- encoding morse code \n");
	printf("   Press 2 -- decoding morse code \n");
	printf("   Press 0 -- exit \n");
	
	do
	{
		printf("\nYour choice -- ");
		scanf("%d", &choose);
		switch(choose)
		{
			case 1:
				//encodingMode();
				printf("Encoding Mode\n");
				readFile();
				break;
			case 2:
				//decodingMode()
				printf("Decoding Mode\n");
				writeFile();
				break;
			case 0:
				break;
			default:
				printf("Wrong! - Input again ");
				break;
		}
	}
	while (choose != 0);
	
	
}