#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll extgcd(ll a,ll b,ll &x,ll &y)
{
    if(a==0&&b==0)return -1;//没有最大公约数
    if(b==0){x=1;y=0;return a;}
    else
    {
        ll d=extgcd(b,a%b,y,x);
        y-=a/b*x;
        return d;
    }
}



int main()
{
    ll a,b,x,y;
    cin>>a>>b;
    a%=b;
    extgcd(a,b,x,y);
    while(x<=0)x+=b;
    cout<<x<<endl;
    return 0;
}
