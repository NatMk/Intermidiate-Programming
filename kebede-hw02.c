/*
Natnael Kebede
6/22/16
Homework-02
produce sum,arithmetic mean,variance and counts of the digit characters
for the given data.
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
double mean = 0.0;
double var = 0.0;
double row_Sum(char* str);
void MeanVariance(char*str,double*mean, double*var);
void digitCount(char*str);
int main(void)
{
    char*str1 = "12, 34, 56, 78";
    char*str2 = "82.16, 41.296";
    char*str3 = "2, -3, 5, -7, 11, -13, 17, -19";
    char*str4 = "9.00009, 90.0009, 900.009, 9000.09, 90000.9";
    double mean,var,sum,sum2,sum3,sum4;
    mean= 0.0;
    var=0.0;

    sum = row_Sum(str1);
    printf("For 12, 34, 56, 78\n");
    printf("  sum = %0.6f\n",sum);
    MeanVariance(str1,&mean,&var);
    printf("  mean = %0.6f\n",mean);
    printf("  variance = %0.6f\n",var);
    digitCount(str1);

    sum2 = row_Sum(str2);
    printf("For 82.16, 41.296\n");
    printf("  sum = %0.6f\n",sum2);
    MeanVariance(str2,&mean,&var);
    printf("  mean = %0.6f\n",mean);
    printf("  variance = %0.6f\n",var);
    digitCount(str2);

    sum3 = row_Sum(str3);
    printf("For 2, -3, 5, -7, 11, -13, 17, -19\n");
    printf("  sum = %0.6f\n",sum3);
    MeanVariance(str3,&mean,&var);
    printf("  mean = %0.6f\n",mean);
    printf("  variance = %0.6f\n",var);
    digitCount(str3);

    sum4 = row_Sum(str4);
    printf("For 9.00009, 90.0009, 900.009, 9000.09, 90000.9\n");
    printf("  sum = %0.6f\n",sum4);
    MeanVariance(str4,&mean, &var);
    printf("  mean = %0.6f\n",mean);
    printf("  variance = %0.6f\n",var);
    digitCount(str4);
}

 double row_Sum(char*str)
{

    double sum,value;
    char string[100];
    char *token, *del = ", ";
    sum = 0.0;
    value = 0.0;
    strcpy(string, str);
    token = strtok(string, del);
    while( token != NULL )
   {
       value=atof(token);
       sum = sum + value;
       token = strtok(NULL, del);
   }

    return sum;

}

void MeanVariance(char*str , double*mean, double*var)
{
    int counter;
    char string[100];
    char string2[100];
    double sumTotal,value;
    char *token, *del = ", ";
    counter = 0;
    sumTotal = 0.0;
    value = 0.0;
    strcpy(string, str);
    strcpy(string2, str);
    *mean = 0;
    token = strtok(string, del);
    while( token != NULL )
    {
        value=atof(token);
        *mean = *mean + value;
        counter++;
        token = strtok(NULL, del);
    }

    *mean = *mean/counter;
    token = strtok(string2, del);
    while( token!= NULL)
    {
      value = atof(token);
      sumTotal = sumTotal + (value-(*mean))*(value-(*mean));
      token = strtok(NULL, del);
    }
     *var = sumTotal / (counter-1);
}

void digitCount(char*str)
{

    int j,value,counter;
    char string[100];
    int digits[10] = {0,0,0,0,0,0,0,0,0,0};
    counter = 0;
    strcpy(string,str);
    for(j = 0; j < strlen(str); j++)
    {
        value = string[j] - '0';

        if(value >= 0  && value <= 9)
        {
            digits[value]++;
        }
    }

      printf("  digit counts = ");
      for( j = 0; j<10; j++ )
      {
         if( j == 9)
         {
            printf("%d",digits[j]);
         }
         else
         {
             printf("%d, ",digits[j]);
         }
      }
      printf("\n\n");
}