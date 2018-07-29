#include <bits/stdc++.h>

using namespace std;
const int MAXN=1e6+7;
int p[MAXN];

int _find(int x)
{
    return p[x]==x?x:p[x]=_find(p[x]);
}

void _union(int x,int y)
{
    int p1=_find(x),p2=_find(y);
    if(p1==p2)return;
    else p[a]=y;
    //注意带权并查集的写法
}

int check(int x,int y)
{
    int p1=_find(x),p2=_find(y);
    if(p1==p2)return 1;
    else return 0;
}

int main()
{
    int n;
    for(int i=1;i<=n;i++)
        p[i]=i;
    return 0;
}
