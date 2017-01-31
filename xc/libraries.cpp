#include <iostream>
#include <cstring>
#include <ctime>

https://www.hackerearth.com/notes/standard-template-library/

//ctime library to check tle .
#include <ctime>
using namespace std;
int main()
{
    clock_t t1,t2;
    t1=clock();
    
    
    t2=clock();
    float diff ((float)t2-(float)t1);
    float seconds = diff / CLOCKS_PER_SEC;
    cout<<seconds<<endl;
    return 0;    
}
#include <cstring>
{
    '\0' end of a string .  
	memset(arr ,0 ,sizeof(arr) );
	to initialize all elements to 0 for an array;
	//when size of array is not defined.
	//if defined size just use arr[max][max]={0};
}
#include <stdio.h>
{
    fgets(stringname,sizeofstring,stdin);//last element of string is \n;
    scanf("%[^\n]s",str);//string input for c;
}
#include <vector>
{   
    // erase the 6th element
    myvector.erase (myvector.begin()+5);
    // erase the first 3 elements:
    myvector.erase (myvector.begin(),myvector.begin()+3);
}
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int main() {
    int A[] = {5, 2, 6, 2, 2, 1, 1, 6, 3, 2};        
    vector <int> v(A, A + 10);            // v =  5, 2, 6, 2, 2, 1, 1, 6, 3, 2
    sort (v.begin(), v.end());                // v =  1, 1, 2, 2, 2, 2, 3, 5, 6, 6  this is unstable sort 
    stable_sort(arr,aarr+n,sort_by_name)   //lexographical sort stable one refer this https://ideone.com/2D86Zl
    vector <int>::iterator it;

    if(    binary_search(v.begin(), v.end(), 2)   )

        cout << "2 is in the array" << endl;
    else
        cout << "2 is not in the array" << endl;

    it =     lower_bound(v.begin(), v.end(), 2)    ;

    cout << "lower_bound: " << (it - v.begin()) << endl;

    it =     upper_bound(v.begin(), v.end(), 2)     ; 

    cout << "upper_bound: " << (it - v.begin()) << endl;
    pair < vector <int>::iterator, vector <int>::iterator > p;

    p =      equal_range(v.begin(), v.end(), 2)    ;

    cout << "equal_range First: " << (p.first - v.begin()) << endl;
    cout << "equal_range Second: " <<  (p.second - v.begin()) << endl;
    return 0;
    /*
    2 is in the array
    lower_bound: 2
    upper_bound: 6
    equal_range First: 2
    equal_range Second: 6
    */

}
#include <stack> //LIFO
{
declaration:
stack <int> s;

Push:
s.push(element);

Pop:
s.pop();

Top Element:
s.top()

IsEmpty:
s.empty()

Size:
s.size()

}
#include <queue> //FIFO // proprity queue can also be implimented using this library https://ideone.com/KiyOha
{
Declaration:
queue <int> q;

Enqueue:
q.push(element);

Dequeue:
q.pop();

Front:
q.front()

IsEmpty:
q.empty()

Size:
q.size()
}

escape sequence

\"  22  Double quotation mark
\'  27  Single quotation mark
\?  3F  Question mark
\\  5C  Backslash
\a  07  Alarm (Beep, Bell)
\b  08  Backspace
\f  0C  Formfeed
\n  0A  Newline (Line Feed); see notes below
\nnn    any The character whose numerical value is given by nnn interpreted as an octal number
\r  0D  Carriage Return
\t  09  Horizontal Tab
\v  0B  Vertical Tab
\xhh    any The character whose numerical value is given by hh interpreted as a hexadecimal numberT