/*
Natnael Kebede
7/27/16
Homework-05b
reads a file from stdin, constructs
and deconstruct a queue based on the task given
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node* addf(struct node* head,char token[]);
struct node* removef(struct node* head);
struct node* flush(struct node* head);
void printResults(struct node* head);
void freeNodes(struct node* head);

struct node
{
    char name[50];
    struct node *next;
};


int main(void)
{

	char *token,*token2,*del = ",";
	struct node* head = NULL;
	char buffer[50];

	while(fgets (buffer, sizeof(buffer) , stdin) != NULL )
	{
		
		if ( strcmp(buffer,"flush\n") == 0 )
		{

			/*head = flush(head); */
		}

		else if( strcmp(buffer,"remove\n") == 0)
		{

			head = removef(head); 

		}

		else
		{
			token = strtok(buffer,del);
                	token2 = strtok(NULL,del);
			head = addf(head,token2);

		}

	}



}

struct node* addf(struct node* head,char token[])
{

	struct node* current = head;
	struct node* temp = malloc( sizeof(struct node));
	strcpy(temp->name,token);
	temp->next = NULL;
	if(head == NULL)
	{

	     head = temp;

	}

	else
	{

		while(current->next !=NULL)
		{

			current = current->next;

		}

		current->next = temp;

	}


		return head;

}

struct node* removef(struct node* head)
{
    struct node* temp = head->next;
    free(head);

    return temp;
}

void printResults(struct node* head)
{
    	while(head != NULL)
    	{

		printf("%s", head->name);
        	head = head->next;

    	}


}

void freeNodes(struct node* head)
{

	struct node* temp;
    	while(head != NULL)
    	{

        	temp = head->next;
       		free(head);
        	head = temp;
	}



}

