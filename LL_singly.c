#include <stdio.h>
#include <stdlib.h>


struct Node {
	int data;
	struct Node * next;
};

typedef struct Node node; 
node *head;

int size = 0;

//--------------------------------------------------------------
void create();
void traversal();
void search();
void insertion();
void deletion();
void counting();
void reverse();
//--------------------------------------------------------------


int main()
{
	int choice, ch=1;

	do{
		printf("\n\n-----------------Singly Link List---------------\n");
		printf("Select operation : \n");
		printf("1. Create list.\n");
		printf("2. Traverse list.\n");
		printf("3. Search an element in the link list.\n");
		printf("4. Insert an element.\n");
		printf("5. Delete an element.\n");
		printf("6. Count the number of elements in the link list.\n");
		printf("7. Reverse the link list.\n");
		printf("8. Exit. \n");

		printf("Enter Choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1 : create(); break;
			case 2 : traversal(); break;
			case 3 : search(); break;
			case 4 : insertion(); break;
			case 5 : deletion(); break;
			case 6 : counting(); break;
			case 7 : reverse(); break;
			case 8 : ch=0; break;
			default : printf("You entered a wrong choice.\n");
		}
	
		//printf("\nDo you want to continue? (1:yes  0:no) \n");
		//scanf("%d",&ch);

	}
	while (ch==1);

	return 0;
}


void create ()
{
	node *temp,*ptr;
	int i;

	printf("\n\nEnter number of elements in link list : ");
	scanf("%d",&size);

	head = (node *) malloc (sizeof(node));

	printf ("\nEnter data : ");
	scanf("%d", &head->data);

	head->next = NULL;

	ptr = head;

	for ( i=0;i<(size-1);i++)
	{
		temp = (node *) malloc(sizeof(node));
		printf("Enter data : ");
		scanf ("%d", &temp->data);

		temp->next = NULL;
		ptr->next = temp;
		ptr = temp;
	}
}

void traversal ()
{
	node *ptr;
	printf("\n\nLINK LIST\n");

	ptr = head;
	while (ptr != NULL)
	{
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
}

void search()
{
	node *ptr;
	int no,i,flag=0;
	printf("Enter the element you want to search : ");
	scanf("%d",&no);

	ptr = head;
	for( i = 1; ptr != NULL; i++)
	{
		if(no == ptr->data)
		{
			printf("Search Successful. Element %d found at position %d", ptr->data,i); 
			flag = 1;
			break; 
		}
		else
			ptr = ptr->next;
	}
	if(flag ==0)
		printf("Element not found. \n");
}

void insertion  ()
{
	node *temp,*ptr;

	int i,position;
	printf ("\n\nEnter position of insertion : ");
	scanf("%d",&position);

	temp = (node *) malloc (sizeof(node));
	printf( "\nEnter data : ");
	scanf("%d", &temp->data);

	if(position==1)
	{
		temp->next = head;
		head = temp;
		size++;
	}

	else if (position>= (size+2))
	{
		printf("\nElement cant be inserted !");
	}

	else
	{
		ptr = head;
		for ( i=1;i< (position-1);i++) 
			ptr = ptr->next;

		temp->next = ptr->next;
		ptr->next = temp;
		size++;
	}
}

void deletion ()
{
	node *temp,*ptr;
	int i,position;
	printf ("\n\nEnter position of deletion : ");
	scanf("%d",&position);

	if(position <= size)
	{
		if(position == 1)
		{
			temp = head;
			head = head->next;
			free(temp);
		}
		else
		{
			ptr = head;
			for( i=2 ; i < position; i++)
				ptr = ptr->next;
			temp = ptr->next;
			ptr->next = temp->next;
			free(temp);
		}
		size--;
	}
	else
		printf("Deletion not possible, no element exists at this position.\n");
}

void counting()
{
	node *ptr;
	int count=0;

	ptr = head;
	while (ptr != NULL)
	{
		count++;
		ptr = ptr->next;
	}
	printf("Number of elements in the link list is %d. \n",count );
	printf("Number of elements in the link list is %d. \n",size );
}

void reverse()
{
	node *prev, *current, *after_current;

	prev = NULL;
	current = head;

	while(current != NULL)
	{
		after_current = current->next;
		current->next = prev;

		prev = current;
		current = after_current;	
	}

	head = prev;
	
	printf("Reversed list is : \n");
	traversal();
}
