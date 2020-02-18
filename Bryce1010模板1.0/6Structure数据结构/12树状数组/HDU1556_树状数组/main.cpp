#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=1e5+10;
int n,c[MAXN<<1];



//表示二进制x的最末尾的一个1
int lowbit(int x)
{
    return x&(-x);
}


//区间求和
int getSum(int x)
{
    int ans=0;
    while(x<=n)
    {
        ans+=c[x];
        x+=lowbit(x);
    }
    return ans;
}

//更新节点
void update(int pos,int val)
{
    while(pos>0)
    {
        c[pos]+=val;
        pos-=lowbit(pos);
    }
}


int main()
{
    int a,b;
    while(cin>>n)
    {
        memset(c,0,sizeof(c));
        for(int i=0;i<n;i++)
        {
            cin>>a>>b;
            update(b,1);
            update(a-1,-1);
        }
        for(int i=1;i<n;i++)
            cout<<getSum(i)<<" ";
        cout<<getSum(n)<<endl;
    }
}


