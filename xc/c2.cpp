#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a[5][2];
    int arr[5];  
    int ref[14] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13};
    int ref2[5] = {1,10,11,12,13};
    for(int i=0;i<5;i++)
        for(int j=0;j<2;j++)
            cin>>a[i][j];
    int temp =0;
    for(int i=0;i<4;i++)
        if(a[i][1] == a[i+1][1])
            temp++;
    cout<<temp<<endl;
    if(temp == 4)
        {
            for(int i=0;i<5;i++)
            { 

                if(a[i][0] == 'A')
                    arr[i] = 1;
                if(a[i][0] == 'T')
                    arr[i] = 10;
                if(a[i][0] == 'J')
                    arr[i] = 11;
                if(a[i][0] == 'Q')
                    arr[i] = 12;
                if(a[i][0] == 'K')
                    arr[i] = 13;
                else
                {
                    arr[i] = a[i][0] - '0';
                }

            }
            sort(arr,arr+5);
            for(int i=0;i<5;i++)
                cout<<arr[i]<<" ";
            int counter = 0;
            for(int i=0;i<5;i++)
            {
                int j = arr[0];
                if(ref[j] == arr[i])
                    counter++;
                j++;
            }
            if(counter != 5)
            {
               for(int i=0;i<5;i++)
               {
                    int j = arr[0];
                    if(ref2[j] == arr[i])
                        counter++;
                    j++;
                } 
            }
            if(counter == 5)
                printf("YES");
            else 
                printf("NO");


        }   
        else 
            printf("NO");
    return 0;   
}
