
//try to reduce memory consumption ! eliminate array

/*
	divide and conquer
	recursive algorithm
	stable

	NOT IN PLACE 
	space will be proportional to size of array
	ie space cmplexity = 0(n) //if we delete arrays after merging 
	time complexity = 0(n log n)
*/

#include <stdio.h>

void displayarray(int arr[],int n)
{	
	int i;
	for(i=0;i<n;i++)
		printf("%d\t",arr[i] );
	printf("\n");
}

void merge( int left[],int nL,int right[], int nR,int *arr)
{	
	int i=0,	//smallest unmerged element in left
		j=0,	//smallesT unmerged element in right
		k=0;	//index value being overwritten on main array


		printf("\n\n\n------------------------------------------");
		printf("\nmerging \n");
		displayarray(left,nL);displayarray(right,nR);
		printf("------------------------------------------\n\n\n");


	while(i<nL && j<nR)
	{
		if (left[i]<right[j])
		{
			arr[k]= left[i];
			i++;
		}
		else
		{
			arr[k]=right[j];
			j++;
		}
		k++;
	}

	while(i<nL)
	{	
		arr[k]= left[i];
		i++;
		k++;
	}
	while(j<nL)
	{
		arr[k]=right[j];
		j++;
		k++;
	}
}

void mergesort(int arr[],int n)
{	
	int i;
	if(n>1)
	{
		int middle= n/2;
		int left[middle];
		int right[n-middle];

		for(i=0; i<middle; i++)
			left[i]=arr[i];
		for(i=middle; i<n; i++)
			right[i-middle]= arr[i];

		displayarray(arr,n);

		mergesort(left,middle);
		mergesort(right, n-middle);

		merge(left,middle, right,n-middle, arr);
	}
}


int main() {
	int arr[] = {64,34, 25, 12, 22, 11,90,120};
	int n = sizeof(arr)/sizeof(arr[0]);;
	
	displayarray(arr,n);
	mergesort(arr,n);
	printf("\n\nSorted array is :\n");
	displayarray(arr,n);

    return 0;
}
