#include <bits/stdc++.h>

using namespace std;
const int MAXN=110;
const int INF=0x3f3f3f3f;

int val[MAXN];//点权
int cost[MAXN][MAXN];
int lowcost[MAXN][MAXN];


int path[MAXN][MAXN];//i-j路径的第一个节点

void Floyd(int n)
{
    memccpy(lowcost,cost,sizeof(cost));
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            path[i][j]=j;
        }
    }

    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                int tmp=lowcost[i][k]+lowcost[k][j];
                if(lowcost[i][j]>tmp)
                {
                    lowcost[i][j]=tmp;
                    path[i][j]=path[i][k];
                }
                else if(lowcost[i][j]==tmp&&path[i][j]>path[i][k])
                {
                    path[i][j]=path[i][k];
                }
            }
        }
    }
}

int main()
{

    return 0;
}
