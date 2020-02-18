#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=40010;
const int MAXQ=40010;

//并查集部分
int F[MAXN];
int find(int x)
{
    if(F[x]==-1)return x;
    return F[x]=find(F[x]);
}

void bing(int u,int v)
{
    int t1=find(u);
    int t2=find(v);
    if(t1!=t2)
        F[t1]=t2;
}

// 建图部分
struct Edge
{
    int to,next;
    int val;
}edge[MAXN<<2];
int head[MAXN];
bool vis[MAXN];
int ancestor[MAXN];
int tot;
void add_edge(int u,int v,int val)
{
    edge[tot].next=head[u];
    edge[tot].to=v;
    edge[tot].val=val;
    head[u]=tot++;
}


//查询部分
struct Query
{
    int to,next;
    int index;
}query[MAXQ<<1];
int h[MAXQ],tt;
int Q;
int n;
int anwser[MAXQ];

void add_query(int u,int v,int index)
{
    query[tt].next=h[u];
    query[tt].to=v;
    query[tt].index=index;
    h[u]=tt++;
    query[tt].next=h[v];
    query[tt].to=u;
    query[tt].index=index;
    h[v]=tt++;
}
bool flag[MAXN];
int dist[MAXN];
//LCA部分
void init()
{
    memset(F,-1,sizeof(F));
    memset(head,-1,sizeof(head));
    memset(vis,false,sizeof(vis));
    memset(ancestor,0,sizeof(ancestor));
    tot=0;
    memset(h,-1,sizeof(h));
    tt=0;
    memset(flag,false,sizeof(flag));
    memset(dist,0,sizeof(dist));
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
        int v=query[i].to;
        if(vis[v])
        {
            anwser[query[i].index]=dist[u]-dist[ancestor[find(v)]];
        }
    }
}

void init1()
{
    memset(F,-1,sizeof(F));
    memset(head,-1,sizeof(head));
    memset(vis,false,sizeof(vis));
    memset(ancestor,0,sizeof(ancestor));
    tot=0;
    memset(dist,0,sizeof(dist));
}
void LCA1(int u,int val)
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
        int v=query[i].to;
        if(vis[v])
        {
            anwser[query[i].index]+=dist[v]-dist[ancestor[find(v)]];
        }
    }
}






int root;
int main()
{
    int T,u,v,valu,valv;
    scanf("%d",&T);
    while(T--)
    {
        init();
        int sum=0;
        scanf("%d",&n);
        for(int i=1;i<n;i++)
        {
            scanf("%d%d%d%d",&u,&v,&valu,&valv);
            flag[v]=true;
            sum+=valu;
            sum+=valv;
            add_edge(u,v,valv);//在这个位置我们把正向和反向的边互换一下
            add_edge(v,u,valu);
        }
        scanf("%d",&Q);
        for(int i=0;i<Q;i++)
        {
            scanf("%d%d",&u,&v);
            add_query(u,v,i);
        }
        for(int i=1;i<=n;i++)
        {
            if(!flag[i])root=i;
        }
        LCA(root,0);
        init1();
        for(int i=1;i<n;i++)
        {
            add_edge(u,v,valu);
            add_edge(u,v,valv);
        }
        LCA1(root,0);




        for(int i=0;i<Q;i++)
        {
            cout<<anwser[i]<<endl;
            printf("%d\n",sum-anwser[i]);
        }
    }


    return 0;
}

//未解决


