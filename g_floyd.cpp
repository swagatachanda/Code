#include<stdio.h>
#include<stdlib.h>
void print_matrix(int *a,int n)
{
	int i,j;
	for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d\t",*(a+i*n+j));
        }
        printf("\n\n");
    }
}
void create_matrix(int *a, int n, int p)
{
	int i,j,k;
	for(i=0;i<n;i++)
	{
		*(a+i*n+i)=0;
	}
	for(i=0;i<n;i++)
	{
		if(i==p)
		{
			i++;
		}
		for(j=0;j<n;j++)
		{
			if(i==j||j==p)
			{
				continue;
			}
			if((*(a+i*n+p)+*(a+p*n+j))<*(a+i*n+j))
			{
				*(a+i*n+j)=(*(a+i*n+p)+*(a+p*n+j));
			}
		}
	}
	printf("\nA%d : \n",p+1);
    print_matrix(a,n);
    p++;
    if(p==n)
    {
    	return;
	}
    create_matrix(a,n,p);
}
int main()
{
	int n, *a,p=0;
	printf("Enter the number of vertices : ");
	scanf("%d", &n);
	a=(int*)malloc(n*n*sizeof(int));
	int i,j,col;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("Enter the data for A%d[%d][%d] (for infinity enter larger number like 999): ",p,i,j);
			scanf("%d",&col);
			*(a+i*n+j)=col;
		}
	}
	printf("\nA%d : \n",p);
	print_matrix(a,n);
    create_matrix(a,n,p);
}
