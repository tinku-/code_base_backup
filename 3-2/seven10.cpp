#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int heap[10000];
int size = 0;
void insert(int x)
{
    size++;
    int n = size;
    heap[n] = x;
    while(heap[n/2] < x)
    {
        heap[n] = heap[n/2];
        n = n/2;
    }
    heap[n] = x;
}
void disp()
{
    int i=0;
    for(i=1;i<=size;i++)
        printf("%d ",heap[i]);
}
int main()
{
    int n,i;
    heap[0] = 99999999;

    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int x;scanf("%d",&x);
        insert(x);
    }
    disp();

}