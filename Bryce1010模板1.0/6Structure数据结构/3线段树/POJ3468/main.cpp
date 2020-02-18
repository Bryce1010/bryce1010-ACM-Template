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


//区间求和，[1,x]的和
int getSum(int x)
{
    int ans=0;
    while(x>0)
    {
        ans+=c[x];
        x-=lowbit(x);
    }
    return ans;
}

//更新节点
//向上更新
void update(int pos,int val)
{
    while(pos<=n)
    {
        c[pos]+=val;
        pos+=lowbit(pos);
    }
}


int main()
{
    int a,b;
    while(cin>>n)
    {
        if(n==0)break;
        memset(c,0,sizeof(c));
        for(int i=0;i<n;i++)
        {
            cin>>a>>b;
            update(a,1);
            update(b+1,-1);
        }
        for(int i=1;i<n;i++)
            cout<<getSum(i)<<" ";
        cout<<getSum(n)<<endl;
    }
}


