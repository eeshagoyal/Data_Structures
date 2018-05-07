#include <stdio.h>

int main()
{
  int a[3][3] ,flag=0, no;

    printf("\n Enter the elements of 3x3 matrix");

    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            scanf("%d",&a[i][j]);

    printf("\n Original matrix \n");
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
            printf("%d\t",a[i][j]);
        printf("\n");
    }

    printf("\n Enter the element you want to search : ");
    scanf("%d",&no);

    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
        	if( a[i][j] == no)
        	{
        		flag = 1;
				printf("Element %d found at row %d column %d\n\n", no, i+1, j+1 ); 
        	}

    if(flag ==0)
		printf("Element not found. \n");

}

