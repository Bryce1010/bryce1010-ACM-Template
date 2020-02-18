#include <iostream>
#include<queue>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<stdio.h>
using namespace std;

const int MAXN=200005;
bool vis[MAXN];
int n,k;
int st=MAXN;




struct Node
{
    int x;
    int step;
}node;

void bfs()
{
    queue<Node>que;
    que.push(node);
    vis[node.x]=1;
    Node now,next;
    node.step=0;
    while(!que.empty())
    {
        now=que.front();
        que.pop();
        if(now.x==k)
        {
            st=min(st,now.step);
            return;
        }
        if(now.x>0&&!vis[now.x-1])
        {
            next.x=now.x-1;next.step=now.step+1;que.push(next);

        }
        if(now.x<k&&!vis[now.x+1])
        {
            next.x=now.x+1;next.step=now.step+1;que.push(next);
        }

        if(now.x*2<=100005&&!vis[now.x*2])
        {
            next.x=now.x*2;next.step=now.step+1;que.push(next);
        }
    }

}
int main()
{
    cin>>n>>k;
    node.x=n;
    bfs();
    cout<<st<<endl;

    return 0;
}
