#include <bits/stdc++.h>

using namespace std;
#define LL long long
const int MAXN=256;
const int INF=0x3f3f3f3f;

int num[MAXN<<2];
int n,t,s,e,cnt;

struct Matrix
{
    LL data[MAXN][MAXN];
    Matrix()
    {
        for(int i=0;i<MAXN;i++)
        {
            for(int j=0;j<MAXN;j++)
            {
                data[i][j]=INF;
            }
        }
    }

    Matrix& operator = (const Matrix &x)
    {
        for(int i=0;i<cnt;i++)
        {
            for(int j=0;j<cnt;j++)
            {
                data[i][j]=x.data[i][j];
            }
        }
        return *this;
    }

    Matrix& operator * (const Matrix &x)
    {
        Matrix res;
        for(int k=0;k<cnt;k++)
        {
            for(int i=0;i<cnt;i++)
            {
                for(int j=0;j<cnt;j++)
                {
                    res.data[i][j]=min(res.data[i][j],res.data[i][k]+res.data[k][j]);
                }
            }
        }
        return res;
    }


}a,b;



void mypow()
{
    for(int i=0;i<cnt;i++)
    {
        b.data[i][i]=0;
    }
    while(n)
    {
        if(n&1)
            b=b*a;
        a=a*a;
        n>>=1;
    }
}
int main()
{
    cnt=0;
    cin>>n>>t>>s>>e;
    int from,to,val;
    memset(num,-1,sizeof(num));
    for(int i=0;i<t;i++)
    {
        cin>>val>>from>>to;
        if(num[from]==-1)num[from]=cnt++;
        if(num[to]==-1)num[to]=cnt++;
        from=num[from];
        to=num[to];
        a.data[from][to]=a.data[to][from]=val;
    }
    mypow();
    cout<<b.data[num[s]][num[e]]<<endl;
    return 0;
}
