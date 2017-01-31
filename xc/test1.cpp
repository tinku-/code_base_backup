#include <stdio.h>
#include <stdlib.h>
int stack[100];
int top=-1;
int tp;
void push(int x){
	if(top == 100)
	return;
	else
	stack[++top]=x;
}
int topval(){
	if(top==0)
	return -1;
	else
	return stack[top];
}
int pop(){
	if(top==0)
	return;
	else{
		return stack[top];
		top=top-1;
	}
}
int maxHistogram(int input[],int n){
	int maxarea=0;
	int area=0;
	int i=0;
	for(i=0;i<n;i++){
		if(topval()==-1 || input[topval()]<=input[i])
		push(i);
		else{
			while(input[topval()]<=input[i]){
				tp=pop();
				if(topval()==-1)
				area=input[tp]*i;
				else
				area= input[tp]*(i-topval()-1);
				if(area>maxarea)
				maxarea=area;
			}
			push(i);
		}
			
		}
	while(topval()!=-1){
		tp=pop();
		if(topval()==-1)
		area=input[tp]*i;
		else
		area= input[tp]*(i-topval()-1);
		if(area>maxarea)
		maxarea=area;
	}
	return maxarea;
	}
	int main(){
		printf("Enter the size of input:\n");
		int n;
		scanf("%d",&n);
		printf("\nEnter the array\n");
		int i=0;
		int input[n];
		for(i=0;i<n;i++){
			scanf("%d",&input[i]);
		}
		printf("\nArea as: %d",maxHistogram(input[i],n));
		return 0;
	}