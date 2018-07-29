#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<queue>
#include<map>
#include<cmath>
#include<set>
#include<stack>
#define ll long long
#define pb push_back
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)>(y)?(y):(x))
#define cls(name,x) memset(name,x,sizeof(name))
using namespace std;


ll high[50005];
int main()
{
    ll n;
    cin>>n;
    stack<ll>s;
    int h;
    for(ll i=0;i<n;i++)
    {
        cin>>high[i];

    }
    high[n]=-1;
    ll last=0;
    ll area=0;
    for(ll i=0;i<=n;i++)
    {
        if(s.empty()||high[i]>high[s.top()])
        {
            s.push(i);
        }
        else if(high[i]<high[s.top()])
        {
            while(!s.empty()&&high[i]<high[s.top()])
            {
                ll temp=(i-s.top())*high[s.top()];
                if(temp>area)
                {
                    area=temp;
                }
                last=s.top();
                s.pop();
            }
            s.push(last);
            high[last]=high[i];
        }
    }
    cout<<area<<endl;
    return 0;
}
