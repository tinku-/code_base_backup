#include <stdio.h>

#define MAX 40

int floyd[MAX][MAX], rad, dia;

int min(int a, int b){
	return a>b ? b : a;
}

int max(int a, int b){
	return a>b ? a : b;
}

int main(){
	int n, m, i, j, k, temp;
	scanf("%d %d", &n, &m);

	rad = MAX;

	for(i=0 ; i<n ; i++)
		for(j=0 ; j<n ; j++)
			floyd[i][j] = i^j ? MAX : 0;
	
	for(i=0 ; i<m ; i++){
		scanf("%d %d", &j, &k);
		floyd[j][k] = floyd[k][j] = 1;
	}

	for(k=0 ; k<n ; k++)
		for(i=0 ; i<n ; i++)
			for(j=0 ; j<n ; j++)
				floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);

	for(i=0 ; i<n ; i++){
		temp = 0;
		for(j=0 ; j<n ; j++)
			temp = max(temp, floyd[i][j]), dia = max(temp, dia);
		rad = min(rad, temp);
	}

	printf("%d %d", rad, dia);

	return 0;
}