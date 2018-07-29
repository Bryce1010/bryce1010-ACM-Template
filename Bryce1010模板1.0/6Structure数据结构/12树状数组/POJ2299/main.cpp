#include<bits/stdc++.h>
using namespace std;
#define ll long long


const int MAXN=5e5+10;


ll sum[MAXN],n;
struct Node
{
    int id,digit;
    Node(){}
    Node(int i,int d):id(i),digit(d){}
}node[MAXN];


bool cmp(Node a,Node b)
{
    return a.digit<b.digit;
}

ll lowbit(ll x)
{
    return x&(-x);
}

void update(ll pos,ll val)
{
    while(pos<=n)
    {
        sum[pos]+=val;
        pos+=lowbit(pos);
    }
}



ll getSum(ll x)
{
    ll ans=0;
    while(x>0)
    {
        ans+=sum[x];
        x-=lowbit(x);
    }
    return ans;
}



int main()
{
    while(~scanf("%d",&n))
    {
        if(n==0)break;
        int x;
        for(int i=1;i<=n;i++)
        {
            cin>>x;
            node[i]=Node(i,x);
        }
        sort(node+1,node+n+1,cmp);
        memset(sum,0,sizeof(sum));
        ll cnt=0;
        for(int i=1;i<=n;i++)
        {
            update(node[i].id,1);
            cnt+=(i-getSum(node[i].id));
        }
        cout<<cnt<<endl;


    }
    return 0;

}



