#include<stdio.h>
#define MAX_size 10

void concat(int a[],int b[],int m,int n)
{	
	int i = 0, j = 0, k = m+n, c[MAX_size*2];
	
	for(i=0; i < m; i++)
		c[i]=a[i];

	for(j=0; j < n; i++,j++)
		c[i]=b[j];
		
	for(i=0;i<k;i++)
		printf("%d ",c[i]);
}

int main()
{	
	int a[MAX_size],b[MAX_size],n,m,i;

	printf("Enter the number of elements in first array: ");
	scanf("%d",&m);

	printf("Enter the elements in first array: ");

	for(i=0;i<m;i++)
		scanf("%d",&a[i]);


	printf("\nEnter the number of elements in second array: ");
	scanf("%d",&n);
	
	printf("\nEnter the elements in second array: ");
	
	for(i=0;i<n;i++)
		scanf("%d",&b[i]);
		
	concat(a,b,m,n);
	
	return 0;
}
