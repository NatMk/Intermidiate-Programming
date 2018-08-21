/*
Natnael Kebede
7/13/16
Homework-04b
that reads a file of dates and counts the number of dates
per month per year.
*/
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

void readMonths(char *filename1,char *filename2);


int main(void)

{

	char* filename1 = "months.txt";

	char* filename2 = "dates.csv";

	readMonths(filename1,filename2);


}

void readMonths(char *filename1,char *filename2)

{

	int i = 0;

	char *months[12];

	FILE *filePointer1;

	char buffer[50];

	#define SIZE2 50

    int day,year;

    int a,b,c,d,length;

    FILE *filePointer2;

    char monthName[50];

    int rows = 12, cols = 10, counter = 0;

    int  **counterArray;

    counterArray = malloc(rows * sizeof(int *));

    int yearArray[10] = {2007,2008,2009,2010,2011,2012,2013,2014,2015,2016};


	if( (filePointer1 = fopen(filename1, "r")) == NULL )
        {

                 printf("unable to open %s\n", filename1);

	     }



	while((fgets(buffer, 50, filePointer1) != NULL))
    {

		length = strlen(buffer);

		months[i] = malloc(length);

		strcpy(months[i],buffer);

		i++;

    }




        if( (filePointer2 = fopen(filename2, "r")) == NULL )
        {


	        printf("unable to open %s\n", filename2);

        }




       while( fscanf(filePointer2, "%s %d, %d",monthName,&day,&year) != EOF )

       {


			 for(a = 0; a < rows; a++)

            {

				counterArray[a] = malloc(cols * sizeof(int) );

				if(strcmp(monthName,months[a]) == 0)
				{

					for(b = 0; b < cols; b++)
                   					 {

                        					if(year == yearArray[b])

						{

							counterArray[a][b] = counter++;

						}

					 }



                 }



           }

	  }




					fclose(filePointer1);

					fclose(filePointer2);



					 for(a = 0; a < cols; a++)

                    {

						printf("%10d",yearArray[a]);

					}


					  printf("\n\n");


                for(c = 0; c < rows; c++)

                {
                    printf("%s",months[c]);

                    for(d = 0 ; d < cols; d++)

                    printf("%10d",counterArray[c][d]);

                    printf("\n");




                }



}







