#include <stdio.h>
#include <stdlib.h>


typedef struct node {
	int data;
	struct node * next;
	struct node * prev;
} node;

node *head;

int size = 0;

//--------------------------------------------------------------
void create();
void traversal();
void search();
void insertion(); 
void deletion();  
void counting();
//--------------------------------------------------------------


int main()
{
	int choice, ch=1;

	do{
		printf("\n\n-----------------Doubly Circular Link List---------------\n");
		printf("Select operation : \n");
		printf("1. Create list.\n");
		printf("2. Traverse list.\n");
		printf("3. Search an element in the link list.\n");
		printf("4. Insert an element.\n");
		printf("5. Delete an element.\n");
		printf("6. Count the number of elements in the link list.\n");
		printf("7. Exit. \n");

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
			case 7 : ch=0; break;
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

	head->next = head;
	head->prev = head;

	ptr = head;

	for ( i=0;i<(size-1);i++)
	{
		temp = (node *) malloc(sizeof(node));
		printf("Enter data : ");
		scanf ("%d", &temp->data);

		temp->next = head;
		temp->prev = ptr;

		ptr->next = temp;
		ptr = temp;
	}
}

void traversal()
{
	node *ptr;
	printf("\n\nLINK LIST\n");

	ptr = head;
	do
	{
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
	while (ptr != head);
}

void search()
{
	node *ptr;
	int no,i=1,flag=0;

	printf("Enter the element you want to search : ");
	scanf("%d",&no);

	ptr = head;
	do{
		if(no == ptr->data)
		{
			printf("Search Successful. Element %d found at position %d", ptr->data,i); 
			flag = 1;
			break; 
		}
		else
			ptr = ptr->next;
		i++;
	}
	while (ptr != head);

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

	if(position < size+2)
	{
		if(position==1)
		{
			ptr=head;
			while(ptr->next != head)
				ptr = ptr->next;
			temp->next = head;
			temp->prev = ptr;
			head->prev = temp;
			ptr->next= temp;

			head = temp;
		}

		else if (position == size+1)
		{
			ptr = head;
			while (ptr->next != head)
				ptr = ptr->next;

			ptr->next = temp;
			temp->prev = ptr;
			head->prev = temp;
			temp->next = head;
		}

		else
		{
			ptr = head;
			for ( i=1;i< (position-1);i++) 
				ptr = ptr->next;

			temp->next = ptr->next;
			temp->prev = ptr;
			ptr->next->prev = temp;
			ptr->next = temp;
		}
		size++;
	}
	else
		printf("\nElement cant be inserted !");	
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
			ptr=head;
			while(ptr->next != head)
				ptr = ptr->next;
			temp = head;
			head = head->next;
			head->prev = ptr;
			ptr->next = head;
			free(temp);
		}
		else if (position == size)
		{
			ptr = head;
			while(ptr->next->next != head)
				ptr = ptr->next;
			temp = ptr->next;
			ptr->next = head;
			head->prev = ptr;
			free(temp);
		}
		else
		{
			ptr = head;
			for( i=2 ; i < position; i++)
				ptr = ptr->next;
			temp = ptr->next;
			ptr->next = temp->next;
			temp->next->prev = ptr;
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

	do{
		count++;
		ptr = ptr->next;
	}
	while (ptr != head);

	
	printf("Number of elements in the link list is %d. \n",count );
	printf("Number of elements in the link list is %d. \n",size );
}
