#include <stdio.h>

int main()
{       
	int i =10;char ch='a';
	int*ip = &i;
	char*chp = &ch;
	// printf("size of int data type:%lu\n",sizeof(int*));
	// printf("size of float data type:%lu\n",sizeof(float*));
	// printf("size of char data type:%lu\n",sizeof(char*));
	printf("size of int pointer :%lu\n",sizeof(int*));
	printf("size of int data type:%lu\n\n",sizeof(int));
	printf("size of char pointer:%lu\n",sizeof(char*));
	printf("size of char data type:%lu\n\n",sizeof(char));
	printf("size of float pointer:%lu\n",sizeof(float*));
	printf("size of float data type:%lu\n\n",sizeof(float*));

	printf("size of i:%lu\n",sizeof(i));
	printf("size of ip:%lu\n",sizeof(ip));
	printf("size of *ip:%lu\n",sizeof(*ip));
	printf("size of ch:%lu\n",sizeof(ch));
	printf("size of chp:%lu\n",sizeof(chp));
	printf("size of *chp:%lu\n",sizeof(*chp));
	return 0;

}