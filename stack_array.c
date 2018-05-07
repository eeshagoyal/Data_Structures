#include <stdio.h>
#include <stdlib.h>
#define size 10

int stack[size], top = -1;

//---------------------------------------------------------------------
void display();
void push(int);
void pop();
int count = 0;
//---------------------------------------------------------------------

int main() 
{
	int choice, ch=1;

	while(1)
	{
		printf("\n\n----------------Stack using Link List---------------\n");
		printf("Select operation : \n");      
		printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");

		printf("Enter Choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1 :
					{
						int data;
						printf("Enter data : ");
						scanf("%d",&data);
						push(data); 
						break;
					}
			case 2 : pop(); break;
			case 3 : display(); break;
			case 4 : exit(0);
			default : printf("You entered a wrong choice.\n");
		}
	}
	while (ch==1);
	return 0;
}



void push( int value )
{
	if(top == size-1)
		printf("\nStack is Full ! Insertion is not possible.");
	else
	{
		top++;
		stack[top] = value;
		printf("\nInsertion success!!!");
	}
}
void pop()
{
	if(top == -1)
		printf("\nStack is Empty ! Deletion is not possible.");
	else
	{
		printf("\nDeleted : %d", stack[top]);
		top--;
	}
}
void display()
{
	if(top == -1)
		printf("\nStack is Empty!!!");
	else
	{
		printf("\nStack elements are:\n");
		for(int i = top; i>=0; i--)
			printf("%d\n",stack[i]);
	}
}


