/*
Natnael Kebede
7/27/16
Homework-05a
reads a file from stdin and prints the NAME and ITEM columns.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char** builder(int nameN, int itemN, int *lines);
void  printResults(char ** list,int lines);
void freeMemory(char **list, int lines);


int main(void)
{

	int lc = 0,lines = 0;
	char *aN, aI , *name , *item, *del = ",";
	int itemN = 0,nameN= 0;
	char** list;
	char buffer[150], buffCopy[150];
	fgets(buffer,150,stdin);
    	name = strtok(buffer, del);

	while(strcmp(name, "NAME")!= 0)
	{
		nameN++;
		name = strtok(NULL, del);
	}

	itemN = nameN+1;
	item = strtok(NULL, del);

	while(strcmp(item, "ITEM") != 0 )
	{
		itemN++;
		item = strtok(NULL, del);
	}

	list =  builder(nameN, itemN , &lines);
	printResults(list,lines);
	freeMemory(list,lines);
	
}

char** builder(int nameN, int itemN,int *lines)
{
	char buffer[150], buffCopy[150];
	char** list;
	char** temp;
	char *del = ",", *aN, *aI;
	int indN = 0, indI = 0;
	int key = 5, lc= 0;
	int nameS, itemS , lineS;
	list = malloc(key * sizeof(char*) );

	while(fgets(buffer, 150, stdin) != NULL)
	{
		strcpy(buffCopy, buffer);
		if(nameN == 0)
		{
			aN = strtok(buffer, del);
		}
		else
		{
			aN = strtok(buffer, del);
			while(indN != nameN)
			{
				aN = strtok(NULL, del);
				indN++;
			}
		}

		if(itemN == 1)
		{
			aI = strtok(buffCopy, del);

		}
		else
		{
			aI = strtok(buffCopy, del);
			while(indI != itemN)
			{
				aI = strtok(NULL, del);
				indI++;
			}
		}


		indN= 0, indI = 0;
		nameS = strlen(aN);
		itemS = strlen(aI);
		lineS = nameS + itemS + 3;

		if(lc == key)
		{
			key = 2*key;
			temp = realloc(list, key*sizeof(char*));
			if(temp != NULL)
			{
				list = temp;
				printf("reallocating to %d\n", key);
			}
			else
			{
				printf("realloc failed");
				exit(1);
			}
		}


		list[lc] = malloc(lineS*sizeof(char));
		strcpy(list[lc], aN);
		strcat(list[lc], ", ");
		strcat(list[lc], aI);
		lc++;


	}

		*lines = lc;
		return list;
}

void  printResults(char **list,int lines)
{


	int i;
	printf("\n\n");
	for(i = lines-1; i >= 0 ; i--)
	{
		printf("%s\n" ,list[i]);

	}

}


void freeMemory(char **list, int lines)
{
	
	 int i;	 
	
	 for(i = lines-1; i >= 0 ; i--)
        {
                free( list[i] );
		

        }

		
	free(list);

}
