/*
因为负数乘负数会变正，因此初始化d数组为0，起点设为1，从起点开始
更新各个点
*/
#include <bits/stdc++.h>

using namespace std;
int n,m;
double road[1002][1002],d[1002];
using namespace std;
void init()
{
    memset(d,0,sizeof(d));
}
void spfa(int from,int to)
{
    memset(d,0,sizeof(d));
    d[from]=1;
    bool vis[1002];memset(vis,0,sizeof(vis));
    vis[from]=1;
    stack<int>P;
    P.push(from);
    while(!P.empty())
    {
        int v=P.top();
        P.pop();
        vis[v]=0;
        for(int i=1;i<=n;i++)
        {
            if(v==i)continue;
            if(d[i]<d[v]*road[v][i])
            {
                d[i]=d[v]*road[v][i];
                if(!vis[i])
                {
                    P.push(i);
                    vis[i]=1;
                }
            }
        }
    }


}

int main()
{
    while(~scanf("%d",&n))
    {
        int i,j;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                scanf("%lf",&road[i][j]);
            }
        }
        int q;
        scanf("%d",&q);
        while(q--)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            spfa(x,y);
            if(d[y]==0)
                printf("What a pity!\n");
            else printf("%.3lf\n",d[y]);
        }
    }
    return 0;
}
