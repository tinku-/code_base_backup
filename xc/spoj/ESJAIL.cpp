#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
struct room
{
        bool visited,unlocked;
        int unlocks;
        vector <int> neighbors;
};
int main()
{
        int n,k,m;
        while(true)
        {
                scanf("%d%d%d",&n,&k,&m);
                if(n==-1)
                        break;
                room x;
                x.visited=false;
                x.unlocked=true;
                x.unlocks=-1;
                x.neighbors.clear();
                vector <room> A(n,x);
                deque <int> que;
                int y,z;
                for(int i=0;i<k;i++)
                {
                        scanf("%d%d",&y,&z);
                        A[y-1].unlocks=z-1;
                        A[z-1].unlocked=false;
                }
                for(int i=0;i<m;i++)
                {
                        scanf("%d%d",&y,&z);
                        A[y-1].neighbors.push_back(z-1);
                        A[z-1].neighbors.push_back(y-1);
                }
                int curr_unlocked=1;
                bool ans=false;
                que.push_back(0);
                A[0].visited=true;
                while(curr_unlocked>0&&!A.empty())
                {
                        y=que.front();
                        if(y==n-1)
                        {
                                ans=true;
                                break;
                        }
                        if(A[y].unlocked)
                        {
                                if(A[y].unlocks!=-1)
                                {
                                        A[A[y].unlocks].unlocked=true;
                                        if(A[A[y].unlocks].visited)
                                                curr_unlocked++;
                                }
                                for(int i=0;i<A[y].neighbors.size();i++)
                                {
                                        if(!A[A[y].neighbors[i]].visited)
                                        {
                                                que.push_back(A[y].neighbors[i]);
                                                A[A[y].neighbors[i]].visited=true;
                                                if(A[A[y].neighbors[i]].unlocked)
                                                        curr_unlocked++;
                                        }
                                }
                                curr_unlocked--;
                        }
                        else
                        {
                                que.push_back(y);
                        }
                        que.pop_front();
                }
                if(ans)
                        printf("Y\n");
                else
                        printf("N\n");
        }
        return 0;
}