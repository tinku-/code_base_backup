#include <bits/stdc++.h>
using namespace std;
#define I 960
#define H 20
#define O 20
#define alpha 0.6
#define eta 0.6
double input[I] = {0};
double wh[H][I] = {0};
double wk[O][H] = {0};
double hidden[H] = {0};
double output[O] = {0};
double target[O] = {0};
double delh[H] = {0};
double delk[O] = {0};
double delwh1[H][I] = {0}; //1 is old delta 
double delwk1[O][H] = {0};
double delwh2[H][I] = {0}; //2 is new
double delwk2[O][H] = {0};

double sigmoid(double x)
{
	return (1.0/(1.0 + exp(-x)));
}

int random_initialize()
{
	float r3;
	for(int i=0;i<H;i++)
		for(int j=0;j<I;j++)
			wh[i][j] = -0.05 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(0.1)));
	for(int i=0;i<O;i++)
		for(int j=0;j<H;j++)
			wk[i][j] = -0.05 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(0.1)));
	return 0;
}
int main()
{
	random_initialize();
	/*
	feed forward 
	*/
	for(int i=0;i<H;i++)
		for(int j=0;j<I;j++)
				hidden[i] += wh[i][j]*input[j];
	for(int i=0;i<H;i++)
		hidden[i] = sigmoid(hidden[i]);
	for(int i=0;i<O;i++)
		for(int j=0;j<H;j++)
				output[i] += wk[i][j]*hidden[j];
	for(int i=0;i<O;i++)
		output[i] = sigmoid(output[i]);


	/*
	back propogation
	*/

	//outer layer
	double sum=0;
	for(int k=0;k<O;k++)
		delk[k] = (target[k] - output[k])*output[k]*(1-output[k]);
	for(int j=0;j<H;j++)
	{
		for(int k=0;k<O;k++)
			sum = delk[k]*wk[k][j];
		delh[j] = hidden[j]*(1-hidden[j])*sum;
	}
	//outer update ...
	for(int k=0;k<O;k++)
		for(int j=0;j<H;j++)
		{
			delwk2[k][j] = eta*delk[k]*hidden[j] + alpha*delwk1[k][j];
			delwk1[k][j] = delwk2[k][j];
			wk[k][j] += delwk2[k][j];
		}
	// hidden layer ...
	for(int j=0;j<H;j++)
		for(int i=0;i<I;i++)
		{
			delwh2[j][i] = eta*delh[j]*input[i] + alpha*delwh1[j][i];
			delwh1[j][i] = delwh2[j][i];
			wh[j][i] += delwh2[j][i];
		}
}


