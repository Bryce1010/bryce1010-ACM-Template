#include <iostream>
#include<string.h>
#include<queue>
#include<stdio.h>
#include<string>
using namespace std;
#define MAXN 1000005



struct cmp
{
    bool operator()(int a,int b)
    {
        return a>b;
    }
};





int main()
{
    int n,k;
    while(cin>>n>>k)
    {
        priority_queue<int,vector<int>,cmp>que;
        int x;
        getchar();
        while(n--)
        {
            char ch;
            cin>>ch;
            //getline(cin,str);
            if(ch=='I')
            {
                cin>>x;
                que.push(x);
                if(que.size()>k)
                    que.pop();
            }
            else
                cout<<que.top()<<endl;
        }
    }
    getchar();getchar();
    return 0;
}
