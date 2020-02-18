#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXN=40010;
const int MAXQ=40010;

int n;
//并查集部分
int F[MAXN];//初始为-1
int find(int x)
{
    if(F[x]==-1)return x;
    return F[x]=find(F[x]);
}

int bing(int u,int v)
{
    int t1=find(u);
    int t2=find(v);
    if(t1!=t2)
    {
        F[t1]=t2;
    }
}


//建图部分
bool vis[MAXN];
int ancestor[MAXN];
struct Edge
{
    int to,next;
    int val;//每条边的权重
}edge[MAXN<<2];
int head[MAXN],tot;//head初始为-1

void add_edge(int u,int v,int val)
{
    edge[tot].next=head[u];
    edge[tot].to=v;
    edge[tot].val=val;
    head[u]=tot++;
//    edge[tot].next=head[v];
//    edge[tot].to=u;
//    edge[tot].val=val;
//    head[v]=tot++;
}
int dist[MAXN];
bool flag[MAXN];
//查询部分
struct Query
{
    int q,next;
    int index;//查询标号
}query[MAXQ<<1];
int answer[MAXQ];//存储每个查询的结果
int h[MAXQ];
int tt;
int Q;
void add_query(int u,int v,int index)
{
    query[tt].next=h[u];
    query[tt].q=v;
    query[tt].index=index;
    h[u]=tt++;
    query[tt].next=h[v];
    query[tt].q=u;
    query[tt].index=index;
    h[v]=tt++;
}



//LCA部分
void init()
{
    tot=0;
    memset(F,-1,sizeof(F));
    memset(vis,false,sizeof(vis));
    memset(ancestor,0,sizeof(ancestor));
    memset(head,-1,sizeof(head));
    memset(h,-1,sizeof(h));
    memset(dist,0,sizeof(dist));
    memset(flag,false,sizeof(flag));
    tt=0;
}
void LCA(int u,int val)
{
    ancestor[u]=u;
    vis[u]=true;
    dist[u]=val;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].to;
        int weight=edge[i].val;
        if(vis[v])continue;
        LCA(v,val+weight);
        bing(u,v);
        ancestor[find(u)]=u;
    }
    for(int i=h[u];i!=-1;i=query[i].next)
    {
        int v=query[i].q;
        if(vis[v])
        {
//            cout<<ancestor[find(v)]<<endl;
            answer[query[i].index]=dist[v]+dist[u]-2*dist[ancestor[find(v)]];
        }
    }
}

int root;

int main()
{
    int T,u,v,val;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&Q);
        init();
        for(int i=1;i<n;i++)
        {
            scanf("%d%d%d",&u,&v,&val);
            flag[v]=true;
            add_edge(u,v,val);
            add_edge(v,u,val);
        }
        for(int i=0;i<Q;i++)
        {
            scanf("%d%d",&u,&v);
            add_query(u,v,i);
        }
        //找到没有入度的节点作为root
        for(int i=1;i<=n;i++)
            if(!flag[i])
            {
                root=i;
                break;
            }
        LCA(root,0);
        for(int i=0;i<Q;i++)
        {
            printf("%d\n",answer[i]);
        }
    }



}


/*
2
3 2
1 2 10
3 1 15
1 2
2 3

*/










