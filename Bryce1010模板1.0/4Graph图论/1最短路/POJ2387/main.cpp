#include <bits/stdc++.h>

using namespace std;
const int MAXN=2010;
const int INF=0x3f3f3f3f;

bool vis[MAXN];
int pre[MAXN];
int cost[MAXN][MAXN];
int lowcost[MAXN];
int beg;
int n,t;
void Dijkstra(int cost[][MAXN],int lowcost[],int beg)
{
    for(int i=0;i<n;i++)
    {
        lowcost[i]=INF;
        vis[i]=false;
        pre[i]=-1;
    }
    lowcost[beg]=0;
    for(int j=0;j<n;j++)
    {
        int k=-1;
        int _min=INF;
        for(int i=0;i<n;i++)
        {
            if(!vis[i]&&lowcost[i]<_min)
            {
                _min=lowcost[i];
                k=i;
            }
        }
        if(k==-1)
        {
            break;
        }
        vis[k]=true;
        for(int i=0;i<n;i++)
        {
            if(!vis[i]&&lowcost[k]+cost[k][i]<lowcost[i])
            {
                lowcost[i]=lowcost[k]+cost[k][i];
                pre[i]=k;
            }
        }
    }
}


int main()
{

    cin>>t>>n;
    int from,to,c;
    for(int i=0;i<t;i++)
    {
        cin>>from>>to>>c;
        cost[from-1][to-1]=c;
        cost[to-1][from-1]=c;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)cost[i][j]=0;
            else cost[i][j]=cost[j][i]=INF;
        }
    }
    beg=n-1;
    Dijkstra(cost,lowcost,n-1);
    for(int i=0;i<n;i++)
        cout<<lowcost[i]<<" ";
    cout<<endl;
    for(int i=0;i<n;i++)
        cout<<pre[i]<<" ";
    cout<<endl;
    cout<<lowcost[0]<<endl;
    return 0;
}
