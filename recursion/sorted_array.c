# include <stdio.h>
# include <stdlib.h>

int is_array_sorted(int A[],int n)
{
	if(n==1)
	return 1;
	return((A[n-1]<A[n-2])?0:is_array_sorted(A,n-1));
}

int main()
{
	int A[]={1,2,8,4};
	int result = is_array_sorted(A,4);
	if(result==1)
	{
		printf("Sorted!\n");
	}
	else
	printf("NAH!\n");
}
