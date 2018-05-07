/*

	RECURSIVE algo
	average case time complexity = 0(n log n)
	
	worst case time complexity 	 = 0(n*n)
	this can be avoided by randomizing the approach

	no need to make auxiliary arrays unlike merge sort

	IN PLACE

	logic
		till segment is only 1 element 			
			int create PARTITION:
				select any number, call it pivot
				rearrange to get all elements < pivot to the left
				rearrange to get all elements > pivot to the right 
				return partition index

			quicksort(left array of partition index)
			quicksort(right array of patition index)



*/

#include <stdio.h>

void displayarray(int arr[],int n)
{	
	int i;
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

int partition(int arr[], int start,int end)
{
	int i;
	int pivot = arr[end];
	int partition_index = start;

	for(i= start; i<end; i++)
	{
		if(arr[i]<= pivot)
		{
			swap (&arr[i],&arr[partition_index]);
			partition_index++;
		}
	}
	swap(&arr[partition_index], &arr[end]);

	displayarray(arr,end+1);
	printf("\n\nPI ==%d\n\n",partition_index);
	return partition_index;
}
void quicksort(int arr[], int start,int end)
{
	if (start<end)
	{	
		int partition_index = partition(arr,start,end);
		quicksort(arr,	start,	partition_index-1);
		quicksort(arr,	partition_index+1,	end);
	}

}

int main() {

	int arr[] = {64,34, 25, 12, 22, 11,90,120,100};
	int n = sizeof(arr)/sizeof(arr[0]);;
	//displayarray(arr,n);
	quicksort(arr,0,n-1);
	printf("\n\nSorted array is :\n");
	displayarray(arr,n);

    return 0;
}