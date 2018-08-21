/*
Natnael Kebede
7/06/16
Homework-03
reading a set of files and producing the average cost of the items purchased in each
file.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void itemsAvg(char* fileNames);

int main(int argc, char* argv[])

{
         int i,j,begin,stop;

         char name_of_file[13];

         char *fileNames;

         begin = atoi(argv[1]);

         stop = atoi(argv[2]);

         for(i = begin ; i <= stop ; i++)

         {

              if((i >= 1) && (i <= 9))
              {

                   sprintf(name_of_file,"data-00%d.txt",i);

                   fileNames = name_of_file;

                   itemsAvg(fileNames);

              }

              else if((i >= 10) && (i <= 99))
              {

                    sprintf(name_of_file,"data-0%d.txt",i);

                    fileNames = name_of_file;

                    itemsAvg(fileNames);

              }

             else

              {

                    sprintf(name_of_file, "data-%d.txt", i);

                    fileNames = name_of_file;

                    itemsAvg(fileNames);
              }

         }
}
void itemsAvg(char* fileNames)
{
        double booksum = 0;

        double clothingsum = 0;

        double flowersum =  0;

        double phonesum = 0;

        int bookCounter = 0;

        int clothingCounter = 0;

        int  phoneCounter = 0;

        int  flowerCounter = 0;

        double bookAvg, clothingAvg, flowerAvg = 0;

        double phoneAvg = 0;

        char *token, *del = " ." , *del3 = "$";

        char *token2, *del2 = " .";

        char item1[] = "book";

        char item2[] = "clothing";

        char item3[] = "flowers";

        char item4[] = "phone";

        double  cost;

        char *valchar;

        char total[50];

        char proOne[50];

        char proTwo[50];

        char eachtok[50];

        char myval[50];

        FILE *filePointer;

        if( (filePointer = fopen(fileNames, "r")) == NULL )
        {

                 printf("unable to open %s\n", fileNames);

                 exit(1);
        }

        else
        {
                while(fgets(total, 50 , filePointer)!= NULL)
                {

                        strcpy(proOne, total);

                        strcpy(proTwo, total);

                        token2 =  strtok(proOne,del2);

                        while(token2 != NULL)
                        {

                                strcpy(eachtok,token2);

                                if (eachtok[0] == '$')

                                {
                                        valchar = strtok(eachtok,del3);

                                        strcpy(myval,valchar);

                                        cost = atof(myval);

                                }

                                  token2 = strtok(NULL, del2);
                        }

                       token = strtok(proTwo, del);

                       while( token != NULL )
                       {

                          if(strcmp(token,item1) == 0)
                          {

                               bookCounter++;
                               booksum+=cost;

                          }


                          else if(strcmp(token,item2) == 0)
                          {
                                clothingCounter++;
                                clothingsum+=cost;

                          }

                          else if(strcmp(token,item3) == 0)
                          {

                                flowerCounter++;
                                flowersum+=cost;

                          }

                          else if(strcmp(token,item4) == 0)
                          {

                                 phoneCounter++;
                                 phonesum+=cost;

                          }

                        token = strtok(NULL, del);

                     }

                }
        }

                bookAvg = booksum/bookCounter;

                clothingAvg = clothingsum/clothingCounter;

                flowerAvg = flowersum/flowerCounter;

                phoneAvg = phonesum/phoneCounter;

                fclose(filePointer);

                 if(booksum == 0)
                {
                    printf("%s: book =  none, clothing = %5.2f, flowers = %5.2f, phone = %5.2f\n",fileNames,clothingAvg,flowerAvg,phoneAvg);

                }
                else if(clothingsum == 0)
                {
                   printf("%s: book = %5.2f, clothing =  none, flowers = %5.2f, phone = %5.2f\n",fileNames,bookAvg,flowerAvg,phoneAvg);
                }
                else if(flowersum == 0)
                {
                    printf("%s: book = %5.2f, clothing = %5.2f, flowers =  none, phone = %5.2f\n",fileNames,bookAvg,clothingAvg,phoneAvg);
                }
                else if(phonesum == 0)
                {
                    printf("%s: book = %5.2f, clothing = %5.2f, flowers = %5.2f, phone =  none\n",fileNames,bookAvg,clothingAvg,flowerAvg);
                }
                else if((booksum == 0) && (clothingsum == 0))
                {
                    printf("%s: book =  none, clothing =  none, flowers = %5.2f, phone = %5.2f\n",fileNames,flowerAvg,phoneAvg);
                }
                else if((booksum == 0) && (flowersum == 0))
                {
                    printf("%s: book =  none, clothing = %5.2f, flowers =  none, phone = %5.2f\n",fileNames,clothingAvg,phoneAvg);
                }
                else if((booksum == 0) && (phonesum == 0))
                {
                    printf("%s: book =  none, clothing = %5.2f, flowers = %5.2f, phone =  none\n",fileNames,clothingAvg,flowerAvg);
                }
                else if((clothingsum == 0) && (flowersum == 0))
                {
                    printf("%s: book = %5.2f, clothing =  none, flowers =  none, phone = %5.2f\n",fileNames,bookAvg,phoneAvg);
                }
                else if((clothingsum == 0) && (phonesum == 0))
                {
                    printf("%s: book = %5.2f, clothing = none, flowers = %5.2f, phone = none\n",fileNames,bookAvg,flowerAvg);
                }
                else if((flowersum == 0) && (phonesum == 0))
                {
                    printf("%s: book = %5.2f, clothing = %5.2f, flowers =  none, phone =  none\n",fileNames,bookAvg,clothingAvg);
                }
                else
                {
                      printf("%s: book = %5.2f, clothing = %5.2f, flowers = %5.2f, phone = %5.2f\n",fileNames,bookAvg,clothingAvg,flowerAvg,phoneAvg);
                 }



}