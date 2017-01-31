#include <bits/stdc++.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;
int main()
{
	for(int i=0;i<5;i++)
	{
		sleep(2);
		//system("rhythmbox-client --volume-down");
		system("rhythmbox-client --next");
	}
}