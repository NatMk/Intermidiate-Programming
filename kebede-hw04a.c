/*
Natnael Kebede
7/13/16
Homework-04a
reads a comma-delimited file of UTA courses and determines the 
number of sections and the combined enrollment for each unique CSE course.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void readfile(char* filename);


struct cList
{
        int courseNumber;

        int section;

        int enrollment;
};

int main(int argc,char* argv[])
{       	
	
	char* fileName = argv[1];	

	struct cList myCourses[100];

	readfile(fileName);
}

void  readfile(char *filename)
{

	int a, temp,temp2,temp3,sorted;

	struct cList course[100];

  	int i,j,k;

	int sectionCounter = 0;

	int courseNOCounter = 0;
	
	int enrollmentCounter = 0;

	int found;

	int courseNo;

	int myEnroll;

                  	int lineCount = 0;

                 	int findInd = 0;

                  	char *tokenUseless, *tokenUTAc, *tokenID, *tokenEnrollment,*del = ",";

              	FILE *filePointer;

            	char eachline[349];

           	char str[] = "CSE";

        if( (filePointer = fopen(filename, "r")) == NULL )
        {
                 printf("unable to open %s\n", filename);

                 exit(1);
        }

        fgets(eachline,349,filePointer);

        for(i = 0; i < 100; i++)
        {	
	
                course[i].enrollment = 0;

                course[i].courseNumber = 0;

                course[i].section = 0;
        }
	

        while( fgets(eachline,349,filePointer) != NULL)
        {
                tokenUseless = strtok(eachline,del);
                
                tokenUseless = strtok(NULL,del);
                
                tokenUseless = strtok(NULL,del);
                
                tokenUTAc = strtok(NULL,del);
                
                tokenID = strtok(NULL,del);

                courseNo = atoi(tokenID);
                
                tokenUseless = strtok(NULL,del);
                
                tokenUseless = strtok(NULL,del);
                
                tokenUseless = strtok(NULL,del);
                
                tokenEnrollment = strtok(NULL,del);

                myEnroll = atoi(tokenEnrollment);

                if(strcmp(tokenUTAc,str) == 0)
                {
                     for(j = 0; j < 100; j++)
                     {
                           if(courseNo == course[j].courseNumber)
                           {

                                  found = 1;

                                  findInd = j;
				
                                   break;
                            }

                            else
                            {

                                found = 0;
                            }

                       }
                                if (found == 1)
                            	{

                                	course[findInd].enrollment += myEnroll;

                                	course[findInd].section++;
					
                                    sectionCounter++;
				
                                    enrollmentCounter+=myEnroll;

                                }   
				
                                else
                                {
					                                
                                    	course[lineCount].enrollment = myEnroll;  

                                	course[lineCount].courseNumber = courseNo;  

                                   	 course[lineCount].section++;    

                                	 lineCount++;
					
                                   	 sectionCounter++;
				
                                   	 courseNOCounter++;
					
                                    	 enrollmentCounter+=myEnroll;
                                }  
					
								     
                   }
        }

			
			 do
   			 {
      				sorted = 1;

      				for(a = 0; a < lineCount-1; a++)
      				{
           				      if(course[a].courseNumber > course[a+1].courseNumber)
          			                        {

              					temp = course[a].courseNumber;
						
                               				 temp2 = course[a].section;

                               				 temp3 = course[a].enrollment;				
						
              					course[a].courseNumber = course[a+1].courseNumber;

                                                                                                course[a].section = course[a+1].section;
						
                              			                  course[a].enrollment = course[a+1].enrollment;

              					course[a+1].courseNumber = temp;

                                				course[a+1].section = temp2;

                                				course[a+1].enrollment = temp3;

                                				sorted = 0;
                      			  }

			       }		
		
   			}

   			while( !sorted );
				


			fclose(filePointer);
		

		 	for(k = 0 ; k <= lineCount-1 ; k++)
			{
			          if(course[k].section == 1)
			         {				
					                	
                        printf("CSE %d has %2d section  with a combined enrollment of %3d\n",course[k].courseNumber,course[k].section,course[k].enrollment);
			         }
					
			        else
			        {
						
                         printf("CSE %d has %2d sections with a combined enrollment of %3d\n",course[k].courseNumber,course[k].section,course[k].enrollment); 
				        
		                            }

                                                             }

	   printf("\nTotals:  %d courses, %d sections, %d combined enrollment\n",courseNOCounter,sectionCounter,enrollmentCounter);

                
}



