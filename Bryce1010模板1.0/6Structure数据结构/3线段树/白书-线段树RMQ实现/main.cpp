#include <bits/stdc++.h>

using namespace std;
const int MAXN=1<<17;
int n,dat[MAXN*2-1];

//把所有的值设为MAXN
void init(int _n)
{
    n=1;
    while(n<_n)n*=2;
    for(int i=0;i<2*n-1;i++)
    {
        dat[i]=MAXN;
    }
}
//把第k个值（0-index）更新为a
void update(int k,int a)
{
    k=n-1+k;
    dat[k]=a;
    //由下往上更新
    while(k>0)
    {
        k=(k-1/2);
        det[k]=min(det[k*2+1],det[k*2+2]);
    }
}
//求[a,b)的最小值
int query(int a,int b,int k,int l,int r)
{
    //如果[a,b)和[l,r)不相交，返回MAXN
    if(r<=a||l<=b)return MAXN;
    //如果[a,b)完全包含[l,r)，返回当前值
    if(a<=l&&b>=r)return det[k];
    else
    {
        //返回左右儿子更小的那个
        int lval=query(a,b,2*k+1,l,(l+r)/2);
        int rval=query(a,b,2*k+2,(l+r)/2+1,r);
        return min(lval,rval);
    }
}

