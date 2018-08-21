/*
Natnael Kebede
6/15/16
Homework-01
*/
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int i;
    int j;
    int counter;
    double avg;
    double sum;
    int row = 10;
    int col = 4;
    double value;
    for(i=0;i<row;i++)
    {
        avg = 0.0;
        sum = 0;
        counter = 0;
        for(j =0;j<col;j++)
        {
            value = (rand()%10000)/100.0;
            if(value>=67.0)
            {
                sum+=value;
                counter++;
                printf("%5.2f", value);
                printf("  ");
            }
            else
            {
                 printf("       ");
            }
        }
       
       if (sum == 0.0)
       {
          printf("|\n");
       }
        else 
       {
           avg = sum/counter;
           printf("|%7.2f\n",avg);
       }
       
    }
        
}

