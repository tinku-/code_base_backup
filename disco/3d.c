#include <stdio.h>

#define scan(x) scanf("%d", &x)
#define MAX 1005
#define ll long long

int t, n, arr[MAX], i, q[MAX], start, end;
ll dp[MAX];

int main(){
	int count, s, num, done[MAX], dist[MAX], j, m;
	scan(t);

	while(t--){
		scan(n);
		for(i=0 ; i<n ; i++)
			scan(arr[i]);

		for(i=0 ; i<MAX ; i++)
			done[i] = 0, dist[i] = 0;

		start = 0, end = 1;
		count = 1;
		q[0] = 0;

		while(count){
			s = q[start++];
			count--;

			num = s + 1;
			if(!done[num] && num<=n){
				done[num] = 1;
				dist[num] = dist[s] + 1;
				q[end++] = num;
				count++;
			}

			num = s + arr[s];
			if(num>=0 && num<=n && !done[num]){
				done[num] = 1;
				dist[num] = dist[s] + 1;
				q[end++] = num;
				count++;
			}
		}

		printf("%d\n", dist[n]);
	}

	return 0;
}