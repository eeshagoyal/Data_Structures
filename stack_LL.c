#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
	int data;
	struct Node * next;
} node;

node *top;

//---------------------------------------------------------------------
void traversal();
void push(int);
void pop();
int count = 0;
//---------------------------------------------------------------------

int main() 
{
	int choice, ch=1;

	do{
		printf("\n\n----------------Stack using Link List---------------\n");
		printf("Select operation : \n");
		printf("1. Traverse list.\n");
		printf("2. Insert an element.\n");
		printf("3. Delete an element.\n");
		printf("4. Count the number of elements in the stack.\n");
		printf("5. Exit. \n");

		printf("Enter Choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1 : traversal(); break;
			case 2 : 
					{
						int data;
						printf("Enter data : ");
						scanf("%d",&data);
						push(data); 
						break;
					}
			case 3 : pop(); break;
			case 4 :
						printf("Number of elements in the stack is : %d\n",count); 
						break;
			case 5 : ch=0; break;
			default : printf("You entered a wrong choice.\n");
		}

	}
	while (ch==1);

	return 0;
}

void traversal()
{
	node *ptr;
	printf("\n\nStack\n");

	ptr = top;
	while (ptr != NULL)
	{
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
}

void push( int data )
{
	node *temp;
	temp = (node *) malloc (sizeof(node));
	temp->data = data;
	temp->next = top;
	
	top = temp;
	count++;
}


void pop()
{
	node *temp;

	if(top==NULL)
		printf("underflow\n");
	else
	{
		temp = top;
		top = top->next;
		free(temp);
		count--;
	}

		
}


