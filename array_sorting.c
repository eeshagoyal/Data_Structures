
//	O(n*n)


#include <stdio.h>

void displayarray(int arr[],int n);
void swap(int *a,int *b);
void selectionsort(int arr[],int n);
void insertionsort(int arr[],int n);
void bubblesort(int arr[],int n);


int main() {

	int arr[] = {64,34, 25, 12, 22, 11,90,100,120};
	int n = sizeof(arr)/sizeof(arr[0]);;
	displayarray(arr,n);
	
	int choice, ch=1;
	do{
		printf("\n\n-------------- Sorting Array ---------------\n");
		printf("1. Selection Sort.\n");
		printf("2. Insertion Sort.\n");
		printf("3. Bubble Sort.\n");
		printf("4. Exit. \n");
	
		printf("Enter Choice : ");
		scanf("%d",&choice);

		switch (choice)
		{
			case 1: selectionsort(arr,n); break;
			case 2: insertionsort(arr,n); break;
			case 3: bubblesort(arr,n); break;
			case 4: ch=0; break;
			default : printf("You entered a wrong choice.\n");
		}
		printf("\n\nSorted array is :\n");
		displayarray(arr,n);

		}
	while (ch==1);

    return 0;
}


void displayarray(int arr[],int n)
{	
	int i;
	printf("\n");
	for(i=0;i<n;i++)
		printf("%d\t",arr[i] );
	printf("\n");
}

void swap(int *a,int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/*	
		TIME complexity O(n^2) because of nested loop ie-slow

		Auxiliary Space: O(1)
		never makes more than O(n) swaps  ie-memory efficient

		// IN-PLACE algo ie- uses const amount of memory
		//	2 sub arrays 
		
		// 	select least element as min(inner loop)
		//	put it in the beginning ~~ swap [0] with min


		m 			if		 m 				m	
		64 12 13 	j<m	  64 12 13 		64 12 13 		swap 12 and 64 
		i   j  			  i   j 		 i	   j	

	*/
void selectionsort(int arr[],int n)
{		
	int i,j;	
	for(i=0; i<n-1; i++) //i is the least element of UNSORTED array
	{
		int min = i; 
		for(j= i+1 ; j<n; j++) //selects least element as min
			if(arr[j]<arr[min])
					min=j;

		swap(&arr[min],&arr[i]); // swap after identifying min in UNSORTED array
	}
}


/*
		Normal bubblesort always runs O(n^2) time even if the array is sorted. 
		It can be optimized by stopping the algorithm if inner loop didn’t cause any swap.

		optimised case : 
		Worst and Average Case Time Complexity: O(n*n). 
		Worst case occurs when array is reverse sorted.

		Best Case Time Complexity: O(n). when array is already sorted.

		Auxiliary Space: O(1)

		Boundary Cases: Bubble sort takes minimum time (Order of n) 
		when elements are already sorted.

		Sorting In Place: Yes

		Stable: Yes

		 popular for its capability to detect a very small error 
		 (like swap of just two elements) in almost-sorted arrays 
		 and fix it with just linear complexity (2n).
	*/	
void bubblesort(int arr[],int n)
{
	int i, j,flag;
	for (i = 0; i < n-1; i++)
	{  
    	flag=0; 
		for (j = 0; j < n-i-1; j++)  
		{
		   	if (arr[j] > arr[j+1])
		    {
		    	swap(&arr[j], &arr[j+1]);
		        flag=1;
		    }
		}

		if (flag==0)
		  	break;	
	}
}

/*
		Best case : sorted array : O(n)
		Worst case:	reverse sorted array : O(n*n)
	*/

void insertionsort(int arr[],int n)
{
	int i,value,hole;

	for(i=1; i<n-1; i++ ) //unsorted sub array
	{	
		value = arr[i];  
		hole=i;

		while(hole>0  && arr[hole-1]>value)
		{
			arr[hole]= arr[hole-1];
			hole--;
		}
		arr[hole]= value;
	}
	
}
