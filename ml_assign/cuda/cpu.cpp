#include <bits/stdc++.h>
#include <time.h>
#define N (1024*1024)
#define M (10000)
 int main()
{  
   float data[N]; int count = 0;
   for(int j = 0; j < N; j++)
      data[j] = j;
   for(int i = 0; i < N; i++)
   {
      data[i] *= data[i];
      for(int j = 0; j < M; j++)
        data[i]++;
    }
    int sel =253454;

   //printf("Enter an index: ");
    //scanf("%d", &sel);
   printf("data[%d] = %f\n", sel, data[sel]);
}