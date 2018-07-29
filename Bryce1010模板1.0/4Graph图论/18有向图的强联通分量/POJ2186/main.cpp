#include <iostream>
#include<vector>
#include<string.h>
#include<algorithm>
#include<stdio.h>
using namespace std;
const int MAXN=5e4+10;


int N,M;
int A[MAXN],B[MAXN];
int V;
vector<int>G[MAXN];//图的邻接表表示
vector<int>rG[MAXN];//把边反向后的图
vector<int>vs;//后续遍历后的顶点列表
bool used[MAXN];//访问标记
int cmp[MAXN];//所属强联通分量的拓扑序
void add_edge(int from,int to)
{
    G[from].push_back(to);
    rG[to].push_back(from);
}
void dfs(int v)
{
    used[v]=true;
    for(int i=0;i<G[v].size();i++)
    {
        if(!used[G[v][i]])dfs(G[v][i]);
    }
    vs.push_back(v);//标记后序
}
void rdfs(int v,int k)
{
    used[v]=true;
    cmp[v]=k;
    for(int i=0;i<rG[v].size();i++)
    {
        if(!used[rG[v][i]])rdfs(rG[v][i],k);
    }
}
int scc()
{
    memset(used,0,sizeof(used));
    vs.clear();
    for(int v=0;v<V;v++)
    {
        if(!used[v])dfs(v);
    }
    memset(used,0,sizeof(used));
    int k=0;
    for(int i=vs.size()-1;i>=0;i--)
    {
        if(!used[vs[i]])rdfs(vs[i],k++);
    }
    return k;
}
void solve()
{
    V=N;
    for(int i=0;i<M;i++)
    {
        add_edge(A[i]-1,B[i]-1);
    }
    int n=scc();

    //统计备选解的个数
    int u=0,num=0;
    for(int v=0;v<V;v++)
    {
        if(cmp[v]==n-1)
        {
            u=v;
            num++;
        }
    }
    //检查是否所有点可达
    memset(used,0,sizeof(used));
    rdfs(u,0);//重用强联通分量分解的代码。
    //检查该强联通分量是否从所有顶点可达
    for(int v=0;v<V;v++)
    {
        if(!used[v])
        {
            //该点不可达
            num=0;
            break;
        }
    }
    printf("%d\n",num);
}
int main()
{
        cin>>N>>M;
        for(int i=0;i<M;i++)
        {
            cin>>A[i]>>B[i];
        }
        solve();
        return 0;
}
