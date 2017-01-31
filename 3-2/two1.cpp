#include <stdio.h>

char s[200];

// flag 1 -> only number can be appended to the string
// flag 0 -> can append number or operator to the string

void solve(int sum, int num, int index, char last, int current, int flag){
	if(current == 10){
		if(last == '-')
			sum = sum - num;
		else
			sum = sum + num;
		s[index] = '\0';
		if(sum == 100)
			printf("%s=100\n", s);
		return;
	}

	if(flag){
		s[index] = current + '0';
		solve(sum, current, index+1, last, current+1, 0);
	} else {
		if(last == '-'){
			s[index] = '-';
			solve(sum - num, 0, index+1, '-', current, 1);
			s[index] = '+';
			solve(sum - num, 0, index+1, '+', current, 1);
		} else {
			s[index] = '+';
			solve(sum + num, 0, index+1, '+', current, 1);
			s[index] = '-';
			solve(sum + num, 0, index+1, '-', current, 1);
		}
		s[index] = current + '0';
		solve(sum, 10 * num + current, index+1, last, current+1, 0);
	}
}

int main(){
	solve(0, 0, 0, '+', 1, 1);
	return 0;
}