#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef vector<int> VI;
typedef pair<int,int> PII;
const int mod=1e9+7;
ll powmod(ll a,ll b){ll res=1;a=a%mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}


//head

//tucunchu
const int MAXN=1e6+10;
int n,k;
struct Edge
{
    int to,next;
    bool flag;
    Edge(){}
    Edge(int a,int b):to(a),next(b){}
}edge[MAXN<<2];




