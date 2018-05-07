#include<stdio.h>
#define M 3

void create( int array[M][M] );
void traversal( int array[M][M] );
void addition ( int arr1[M][M], int arr2[M][M], int result[M][M]);
void subtract ( int arr1[M][M], int arr2[M][M], int result[M][M] );
void multiply ( int arr1[M][M], int arr2[M][M], int result[M][M]  );


int main()
{
	int arr1[M][M],  arr2[M][M],  result[M][M] ;
	int choice, ch=1;


	create(arr1);
	create(arr2);

	do{
		printf("\n\n--------------Arithmetic operations on 2D array ---------------\n");
		printf("1. Addition.\n");
		printf("2. Subtraction.\n");
		printf("3. Multiplication.\n");
		printf("4. Exit. \n");
	
		printf("Enter Choice : ");
		scanf("%d",&choice);

		switch (choice)
		{
			case 1: addition( arr1, arr2, result ); break;
			case 2: subtract( arr1, arr2, result ); break;
			case 3: multiply( arr1, arr2, result ); break;
			case 4: ch=0; break;
			default : printf("You entered a wrong choice.\n");
		}
		printf("Resultant array is : \n");
		traversal(result);

		}
	while (ch==1);

	return 0; 
}


void create(int array[M][M])
{
	printf("\n Enter the elements of matrix : \n"); 

	for(int i=0; i < M; i++)
		for(int j=0; j < M; j++) 
			scanf("%d",&array[i][j]); 

	traversal(array);
}

void traversal( int array[M][M] )
{   
	printf("\n--------------Matrix--------------\n");
	for(int i=0; i<M; i++)
	{
		for(int j=0; j<M; j++) 
			printf("%d\t",array[i][j]);
		printf("\n"); 
	}
}

void addition( int arr1[M][M], int arr2[M][M], int result[M][M])
{
	for(int i=0; i < M; i++)
		for(int j=0; j<M; j++)
			result[i][j] = arr1[i][j] + arr2[i][j];
}

void subtract( int arr1[M][M], int arr2[M][M], int result[M][M])
{
	for(int i=0; i < M; i++)
		for(int j=0; j<M; j++)
			result[i][j] = arr1[i][j] - arr2[i][j];

}

void multiply( int arr1[M][M], int arr2[M][M], int result[M][M] )
{
	int sum=0;

	for(int i=0; i < M; i++)
		for(int j=0; j < M; j++)
		{
			for(int k=0; k < M; k++)
				sum = sum + ( arr1[i][k] * arr2[k][j]); 
			result[i][j]=sum;
			sum=0;

		}
}


