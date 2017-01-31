#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N (1024*1024)
#define M (10000)

float data[N];
__global__ void cudakernel(float *d_data)
{
   int i = threadIdx.x + blockIdx.x * blockDim.x;
   //d_data[i] = 1.0f * i / N;
   d_data[i] *= d_data[i];
   for(int j = 0; j < M; j++)
      d_data[i]++;
}

void graphic()
{
  float *d_data;
 
  cudaMalloc(&d_data, N * sizeof(float));
  for(int j = 0; j < N; j++)
      data[j] = j;
  
  cudaMemcpy(d_data, data, N * sizeof(float), cudaMemcpyHostToDevice);
  
  cudakernel<<<N/256, 256>>>(d_data);
  
  cudaMemcpy(data, d_data, N * sizeof(float), cudaMemcpyDeviceToHost);
  
  cudaFree(d_data); 
}
int main()
{

  graphic();
  int sel = 253454;

   //printf("Enter an index: ");
    //scanf("%d", &sel);
   printf("data[%d] = %f\n", sel, data[sel]);
}