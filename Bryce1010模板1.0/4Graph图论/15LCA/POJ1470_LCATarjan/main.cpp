/*伪代码
Tarjan(u)//marge和find为并查集合并函数和查找函数
{
    for each(u,v)    //访问所有u子节点v
    {
        Tarjan(v);        //继续往下遍历
        marge(u,v);    //合并v到u上
        标记v被访问过;
    }
    for each(u,e)    //访问所有和u有询问关系的e
    {
        如果e被访问过;
        u,e的最近公共祖先为find(e);
    }
}

*/
//思想
/*
1.任选一个点为根节点，从根节点开始。
2.遍历该点u所有子节点v，并标记这些子节点v已被访问过。
3.若是v还有子节点，返回2，否则下一步。
4.合并v到u上。
5.寻找与当前点u有询问关系的点v。
6.若是v已经被访问过了，则可以确认u和v的最近公共祖先为v被合并到的父亲节点a。
*/

#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdio.h>
#include<math.h>
using namespace std;
#define ll long long


const int MAXN=1010;
const int MAXQ=500010;

//并查集部分
int F[MAXN];//初始化为-1
int find(int x)
{
    if(F[x]==-1)return x;
    return F[x]=find(F[x]);
}
//merge
void bing(int u,int v)
{
    int t1=find(u);
    int t2=find(v);
    if(t1!=t2)
    {
        F[t1]=t2;
    }
}
//****************
//建图部分
bool vis[MAXN];
int ancestor[MAXN];//存储查询过程节点的祖先
struct Edge
{
    int to,next;
}edge[MAXN<<2];
int head[MAXN],tot;
void add_edge(int u,int v)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}

//离线查询部分

struct Query
{
    int q,next;
    int index;// 查询编号
}query[MAXQ<<1];

int answer[MAXQ];//存储最后的每个查询的公共祖先,下标0,Q-1
int h[MAXQ];
int tt;int Q;

void add_query(int u,int v,int index)
{
    query[tt].q=v;
    query[tt].next=h[u];
    query[tt].index=index;
    h[u]=tt++;
    query[tt].q=u;
    query[tt].next=h[v];
    query[tt].index=index;
    h[v]=tt++;
}

//LCA部分
void init()
{
    tot=0;
    memset(head,-1,sizeof(head));
    tt=0;
    memset(h,-1,sizeof(h));
    memset(vis,false,sizeof(vis));
    memset(F,-1,sizeof(F));
    memset(ancestor,0,sizeof(ancestor));
}

void LCA(int u)
{
    ancestor[u]=u;
    vis[u]=true;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].to;
        if(vis[v])continue;
        LCA(v);
        bing(u,v);
        ancestor[find(u)]=u;//?
    }
    for(int i=h[u];i!=-1;i=query[i].next)
    {
        int v=query[i].q;
        if(vis[v])
        {
            answer[query[i].index]=ancestor[find(v)];
        }
    }
}

bool flag[MAXN];
int Count_num[MAXN];
int main()
{
    int n;
    int u,v,k;
    while(scanf("%d",&n)==1)
    {
        init();
        memset(flag,false,sizeof(flag));
        for(int i=1;i<=n;i++)
        {
            scanf("%d:(%d)",&u,&k);
            while(k--)
            {
                scanf("%d",&v);
                flag[v]=true;
                add_edge(u,v);
                add_edge(v,u);
            }
        }
        scanf("%d",&Q);
        for(int i=0;i<Q;i++)
        {
            char ch;
            cin>>ch;
            scanf("%d %d)",&u,&v);
            //cin>>ch;
            add_query(u,v,i);
        }
        int root;
        for(int i=1;i<=n;i++)//找到没有入度的点作为root
        {
            if(!flag[i])
            {
                root=i;
                break;
            }
        }
        LCA(root);
        memset(Count_num,0,sizeof(Count_num));
        for(int i=0;i<Q;i++)
        {
            Count_num[answer[i]]++;
        }
        for(int i=1;i<=n;i++)
        {
            if(Count_num[i]>0)
            {
                printf("%d:%d\n",i,Count_num[i]);
            }
        }
    }
//    getchar();getchar();
    return 0;
}






/*
5
5:(3) 1 4 2
1:(0)
4:(0)
2:(1) 3
3:(0)
6
(1 5) (1 4) (4 2) (2 3) (1 3) (4 3)
*/




















