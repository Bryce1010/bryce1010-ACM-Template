#include <iostream>
#include<algorithm>
#include<string.h>
#include<math.h>

using namespace std;

const int MAXN=2050;
const int INF=99999999;
const int mINF=-1;
bool vis[MAXN];
int pre[MAXN];
int cost[MAXN][MAXN],lowcost[MAXN];
int n,m;
int beg;

void Dijkstra(int beg)
{

    for(int i=0;i<n;i++)
    {
        lowcost[i]=cost[0][i];
        vis[i]=false;
        pre[i]=-1;
    }

    lowcost[beg]=0;
    vis[beg]=true;
    for(int j=0;j<n;j++)
    {
        int k=-1;
        int _max=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i]&&lowcost[i]>_max)
            {
                _max=lowcost[i];
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
            if(!vis[i]&&lowcost[i]<min(cost[k][i],lowcost[k]))
            {
                lowcost[i]=min(cost[k][i],lowcost[k]);
                pre[i]=k;
            }
        }
    }

}


int main()
{
    int T;
    cin>>T;
    int time=1;
    while(T--)
    {
        memset(vis,false,sizeof(vis));
        memset(pre,0,sizeof(pre));
        memset(cost,0,sizeof(cost));
        memset(lowcost,0,sizeof(lowcost));
        int from,to,val;
        cin>>n>>m;
        for(int i=0;i<m;i++)
        {
            cin>>from>>to>>val;
            if(val>cost[from-1][to-1])
                cost[from-1][to-1]=cost[to-1][from-1]=val;
        }
        beg=0;
        Dijkstra(beg);
        cout<<"Scenario #"<<time++<<":"<<endl<<lowcost[n-1]<<endl<<endl;


    }
    return 0;
}

