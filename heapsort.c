#include <stdio.h>
#include<stdlib.h>
struct heap
{
		int *hp;
		int capacity;
		int heap_size;
		int temp;
};
void initialise(struct heap *h,int v)
{
	h->capacity=v;
	h->heap_size=0;
	h->hp=(int*)malloc(h->capacity*sizeof(int));
	h->temp=0;
}
int parent(int i)
{
	return (i-1)/2;
}
int left_child(int i)
{
    return (2*i+1);
}
int right_child(int i) 
{
    return (2*i+2);
}
void swap(int *x, int *y)
{
	int temp=*x;
	*x=*y;
	*y=temp;
}
void add(struct heap *h,int n)
{
	if (h->heap_size==h->capacity)
	{
		printf(" OVERFLOW ");
		return;
	}
	h->heap_size++;
	int i=h->heap_size-1;
	h->hp[i]=n;
	h->temp++;
}
void heapify_util(struct heap *h,int i)
{
	int l=left_child(i);
	int r=right_child(i);
	int smallest=i;
	if (l<h->heap_size && h->hp[l]>h->hp[i])
	{
		smallest=l;
		swap(&h->hp[i],&h->hp[smallest]);
		heapify_util(h,smallest);
	}
	if (r<h->heap_size && h->hp[r]>h->hp[i])
	{
		smallest=r;
		swap(&h->hp[i],&h->hp[smallest]);
		heapify_util(h,smallest);
	}
}
void heapify(struct heap *h)
{
	for (int i=h->heap_size-1;i>=0;i--)
	{
		heapify_util(h,i);
	}
}
void display(struct heap *h)
{
	for (int i=0;i<h->heap_size;i++)
	{
		printf("%d ",h->hp[i]);
	}
	printf("\n");
}
void delete(struct heap *h)
{
	if (h->heap_size==0)
	{
		return;
	}
	int i=h->heap_size-1;
	swap(&h->hp[0],&h->hp[i]);
	i=0;
	h->heap_size--;
	heapify_util(h,i);
}
void heapify_heapsort(struct heap *h)
{
	int a[h->temp];
	int p=h->temp-1;
	for (int i=h->heap_size-1;i>=0;i--)
	{
		a[p]=h->hp[0];
		p--;
		delete(h);
	}
	for(p=0;p<h->temp;p++)
	{
		printf("%d ",a[p]);
	}
}
int main()
{
	struct heap *h;
	int n,i,a;
	h=(struct heap*)malloc(sizeof(struct heap));
    printf("Enter the number of elements : ");
	scanf("%d",&n);
	initialise(h,n);
    printf("Enter the elements : ");
    for(i=0;i<n;i++)
    {
    	scanf("%d",&a);
    	add(h,a);
	}
	heapify(h);
	display(h);
	heapify_heapsort(h);
}