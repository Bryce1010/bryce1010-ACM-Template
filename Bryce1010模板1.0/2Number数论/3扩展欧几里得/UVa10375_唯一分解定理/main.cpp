#include<bits/stdc++.h>
using namespace std;



const int MAXN=10000+10;
int prime[MAXN];
int e[MAXN];
void getPrime()
{
    memset(prime,0,sizeof(prime));
    for(int i=2;i<=MAXN;i++)
    {
        if(!prime[i])prime[++prime[0]]=i;
        for(int j=1;j<=prime[0]&&prime[j]<=MAXN/i;j++)
        {
            prime[prime[j]*i]=1;
            if(i%prime[j]==0)break;
        }

    }
}



void add_integer(int n,int d)
{
    for(int i=0;i<MAXN;i++)
    {
        while(n%prime[i]==0)
        {
            n/=prime[i];
            e[i]+=d;
        }
        if(n==1)break;
    }
}
void add_factorial(int n,int d)
{
    for(int i=1;i<=n;i++)
    {
        add_integer(i,d);
    }
}

int main()
{
    getPrime();
    int p,q,r,s;
    while(cin>>p>>q>>r>>s)
    {
        memset(e,0,sizeof(e));
        add_factorial(p,1);
        add_factorial(q,-1);
        add_factorial((p-q),-1);
        add_factorial(s,1);
        add_factorial((r-s),1);
        add_factorial(r,-1);
        double ans=1;
        for(int i=0;i<MAXN;i++)
        {
            ans*=pow(prime[i],e[i]);
        }
        printf("%.5lf\n",ans);
    }
    return 0;
}
