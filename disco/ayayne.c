#include <stdio.h>

#define N 100

struct edge{
	int s, e, w;
}arr[N];

void swap(struct edge *a, struct edge *b){
	struct edge temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int dsu[N];

int find(int x){
	while(x != dsu[x])
		x = dsu[x];
	return x;
}

int main(){	
	int v, e, i, j, k, a, b, cnt = 0;
	scanf("%d %d", &v, &e);

	for(i=0 ; i<e ; i++)
		scanf("%d %d %d", &arr[i].s, &arr[i].e, &arr[i].w);

	// Bubble Sort
	for(i=0 ; i<e-1 ; i++)
		for(j=0 ; j<e-i-1 ; j++)
			if(arr[j].w > arr[j+1].w)
				swap(&arr[j], &arr[j+1]);

	for(i=0 ; i<N ; i++)
		dsu[i] = i;

	for(i=0 ; i<e ; i++){
		if(find(arr[i].s) != find(arr[i].e)){
			dsu[find(arr[i].s)] = find(arr[i].e);
			cnt += arr[i].w;
		}
	}

	printf("%d\n", cnt);

	return 0;
}