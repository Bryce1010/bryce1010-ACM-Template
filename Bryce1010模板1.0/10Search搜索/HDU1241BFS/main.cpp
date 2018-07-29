#include <bits/stdc++.h>

using namespace std;
const int MAXN=105;
char ma[MAXN][MAXN];
int n,m;
int x[]={-1,-1,0,1,1,1,0,-1};
int y[]={0,1,1,1,0,-1,-1,-1};
struct Node
{
    int x,y;
}node;
int check(int x,int y)
{
    if(x<0||x>=n||y<0||y>=m||ma[x][y]=='*')
        return 0;
    return 1;
}

void bfs()
{
    queue<Node>que;
    que.push(node);
    Node now,next;
    while(!que.empty())
    {
        now=que.front();
        que.pop();
        for(int i=0;i<8;i++)
        {
            next.x=now.x+x[i];
            next.y=now.y+y[i];
            if(check(next.x,next.y))
            {
                ma[next.x][next.y]='*';
                que.push(next);
            }
        }

    }

}


int main()
{
    while(cin>>n>>m)
    {
        if(n==0&&m==0)
            return 0;
        int cnt=0;
        for(int i=0;i<n;i++)
            cin>>ma[i];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(ma[i][j]=='@')
                {
                    cnt++;
                    node.x=i;
                    node.y=j;
                    bfs();
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
