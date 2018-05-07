#include <stdio.h>

//--------------------------------------------------------------
#define MAX_SIZE 20
int array[MAX_SIZE];
int size = 0;

//--------------------------------------------------------------
void create();
void traversal();
void search();
int  linear_search(int no);
int  binary_search(int no);
void insertion();
void deletion();
void counting();
//--------------------------------------------------------------

int main()
{
    int choice, ch=1;

    do{
        printf("\n\n--------------Array Operations---------------\n");
        printf("Select operation : \n");
        printf("1. Create an array.\n");
        printf("2. Traverse array.\n");
        printf("3. Search for an element in the array.\n");
        printf("4. Insert an element in the array.\n");
        printf("5. Delete an element from the array.\n");
        printf("6. Count the number of elements in the array.\n");
        printf("7. Exit. \n");

        printf("Enter Choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1 : create(); break;
            case 2 : traversal(); break;
            case 3 :                     
                    search();
                    break;
            case 4 : insertion(); break;
            case 5 : deletion(); break;
            case 6 : counting(); break;
            case 7 : ch=0; break;
            default : printf("You entered a wrong choice.\n");
        }

    } while (ch==1);

    return 0;
}


void create()
{
    printf("\nEnter the number of elements : ");
    scanf("%d",&size);

    if(size <= MAX_SIZE)
    {
        for (int i = 0; i < size; ++i)
        {
            printf("Enter element %d : ",i+1);
            scanf("%d",&array[i]);
        }    
    }
    else
        printf("Overflow ! \n");
}


void traversal()
{
    printf("ARRAY : \n");
    for (int i=0; i < size; i++)
        printf("%d  ", array[i]);
    printf("\n");
}

void search()
{
    int c = 1, no ,position;
    printf("\n\n Search for element using :\n");
    printf("\t 1. Linear Search\n");
    printf("\t 2. Binary Search (only works for sorted array) \n");
    scanf("%d",&c);

    printf("Enter element you want to search : \n");
    scanf("%d",&no);

    switch(c)
    {
        case 1 : position = linear_search(no); break;
        case 2 : position = binary_search(no); break;
        default : printf("You entered a wrong choice.\n");
    }
    if(position != -1)
        printf("Element found at position %d. \n", position);
    else
        printf("Element not found.\n");

}

int linear_search(int no)
{
    int flag=0;
    for (int i = 0; i < size; ++i)
        if(array[i] == no)
            return i+1;
        return -1;    
}

int binary_search(int no)
{
    int mid =0, lower = 0, upper = size, flag =0;

    while(lower <= upper)
    {
        mid = lower+upper/2 ;

        if(no == array[mid])
            return mid+1;

        else if(no > array[mid])
            lower = mid+1;
        
        else if(no < array[mid])
            upper = mid-1;
    }
    return -1;
}

void insertion()
{
    int no , position;
    printf("Enter number to be inserted : \n");
    scanf("%d",&no);

    printf("Enter position of insertion : \n");
    scanf("%d",&position);

    if(position <= MAX_SIZE)
    {
        for(int i = (size-1); i >= position-1 ; i--)
            array[i+1] = array[i];

        array[position-1] = no;
        size ++;
    }
    else
        printf("Overflow !\n");
}

void deletion()
{
    int no , position;
    printf("Enter number to be deleted : \n");
    scanf("%d",&no);

    position = linear_search(no);

    if(position <= size && position != -1)
    {
        for(int i = position-1; i <= size-1 ; i++)
            array[i] = array[i+1];

        size --;
    }
    else
        printf("No element exists at this position.\n");
}

void counting()
{
    int count = 0;
    for (int i=0; i < size; i++)
       count++;

    printf("Number of elements in the array is %d. \n",count );
    printf("Number of elements in the array is %d. \n",size );
}
