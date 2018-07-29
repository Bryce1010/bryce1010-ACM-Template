#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int MAXN=1e6+10;
ll prime[MAXN];


void getPrime(int maxn)
{
    memset(prime,0,sizeof(prime));
    for(int i=2;i<=maxn;i++)
    {
        if(!prime[i])prime[++prime[0]]=i;
        for(int j=i;j<=prime[0]&&prime[j]<=maxn/i;j++)
        {
            prime[prime[j]*i]=1;
            if(i%prime[j]==0)break;
        }
    }
}

int main()
{

    //cout<<(ll)pow(2,31)<<endl;
    ll n,k;
    int iCase=1;
   //getPrime();
    while(~scanf("%lld",&n))
    {
        if(n==0)break;
        getPrime(MAXN);
        ll cnt=0,ans=0,r;
        k=n;
        for(int i=1;i<=prime[0];i++)
        {
            if(k%prime[i]==0)
            {
                cnt++;
            }
            r=1;
            while(k%prime[i]==0)
            {
                k/=prime[i];
                r*=prime[i];
            }
            if(r>1)ans+=r;
            if(k==1)break;
        }
        if(cnt==0)ans=(ll)(n)+1;
        else if(cnt==1&&k==1)ans=(ll)(n+1);
        else if(k>1)ans=ans+k;
        printf("Case %d: %lld\n",iCase++,ans);
    }

    return 0;
}
