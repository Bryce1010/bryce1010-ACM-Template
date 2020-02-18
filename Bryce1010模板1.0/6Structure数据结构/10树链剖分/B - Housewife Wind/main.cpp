#include <bits/stdc++.h>

using namespace std;

const int MAXN=10010;
struct Edge
{
    int to,next;
}edge[MAXN*2];


int head[MAXN],tot;//head[v]表示第v个重链的头结点，tot表示重链的总数
int top[MAXN];//top[v]表示v所在的重链顶端节点
int fa[MAXN];//父亲节点
int deep[MAXN];//深度
int num[MAXN];//num[v]表示v为根的子树节点数
int p[MAXN];//p[v]表示v与其父亲节点的连边在线段树中的位置
int fp[MAXN];//与p数组相反，记录线段树的某个位置存的是那些点
int son[MAXN];//重儿子
int pos;

void init()
{
    tot=0;
    memset(head,-1,sizeof(head));
    pos=0;
    memset(son,-1,sizeof(son));
}



void addEdge(int u,int v)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}
//u表示当前节点，pre表示父节点，d表示当前节点深度
//第一遍dfs求出fa,deep,num,son
void dfs1(int u,int pre,int d)
{
    deep[u]=d;
    fa[u]=pre;
    num[u]=1;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].to;
        //因为路径是双向的，所以不能等于父节点
        if(v!=pre)
        {
            dfs1(v,u,d+1);
            //更新u节点的子树数目
            num[u]+=num[v];
            //求出重儿子，所有儿子中size最大的节点v
            if(son[u]==-1||num[v]>num[son[u]])
            {
                son[u]=v;
            }
        }
    }
}

//第二遍求出top和p
void dfs2(int u,int sp)
{
    top[u]=sp;
    p[u]=pos++;
    fp[p[u]]=u;//
    if(son[u]==-1)
    {
        return;
    }
    dfs2(son[u],sp);
    //dfs结束
    //更新其他的节点
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v!=son[u]||v!=fa[u])
        {
            dfs2(v,v);//轻儿子的top[u]=u
        }
    }
}




int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
