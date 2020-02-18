#include<bits/stdc++.h>
using namespace std;


const int MAXN=1e5+10;
const int INF=0x3f3f3f3f;
const int MOD=1e9+7;
int n,a[MAXN];
#define P pair<int,int>

void getMax(P& x,P y)
{
    if(x.first<y.first)x=y;
    else if(x.first==y.first)
    {
        if((x.second+=y.second)>=MOD)
            x.second-=MOD;
    }
}

int id[MAXN];

/*排序小技巧
避开相等，间隔排序，把可能成为询问的排到第一个
*/
bool cmp(int x,int y)
{
    if(a[x]!=a[y])return a[x]<a[y];
    return x>y;
}


void cdq(int l,int r)
{
    if(l==r)return;
    int m=(l+r)>>1;
    cdq(l,m);

    for(int i=l;i<=r;i++)id[i]=i;
    sort(id+l,id+r+1,cmp);

    P maxf(0,0);
    for(int i=l;i<=r;i++)
    {
        int idx=id[i];
        if(idx<=m)getMax(maxf,f[idx]);
        else
        {
            P cur=maxf;
            ++cur.first;
            getMax(f[idx],cur);
        }
    }
    cdq(m+1,r);
}






int main()
{

    ios_base::sync_with_stdio(0);

    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    for(int i=1;i<=n;i++)f[i]=P(1,1);
    cdq(1,n);
    P ans(0,0);
    for(int i=1;i<=n;i++)getMax(ans,f[i]);
    printf("%d\n",ans.second);
    return 0;
}
