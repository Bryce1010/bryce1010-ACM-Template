#include<bits/stdc++.h>
using namespace std;
const int MAXN=205;
const int INF=0x3f3f3f3f;
char ma[MAXN][MAXN];
int kfc[MAXN][MAXN];
int len[3][MAXN*MAXN];
bool vis[MAXN][MAXN];

int dirx[]={0,0,1,-1};
int diry[]={1,-1,0,0};

int n,m;

struct Node
{
    int x,y,step;
}node;

bool check(int x,int y)
{
    if(x<0||x>=n||y<0||y>=m||ma[x][y]=='#'||vis[x][y])
        return 0;
    return 1;
}

void bfs(int x,int y,int p)
{
    node.x=x,node.y=y;node.step=0;
    queue<Node>que;
    que.push(node);

    vis[node.x][node.y]=1;


    Node now,next;
    while(!que.empty())
    {
        now=que.front();
        que.pop();
        if(ma[now.x][now.y]=='@')
        {
            len[p][kfc[now.x][now.y]]=now.step;
            //return;
        }
        for(int i=0;i<4;i++)
        {
            next.x=now.x+dirx[i];
            next.y=now.y+diry[i];
            next.step=now.step+1;
            if(check(next.x,next.y))
            {
                que.push(next);
                vis[next.x][next.y]=1;
            }
        }


    }



}

int main()
{
    while(cin>>n>>m)
    {
        int yx,yy,mx,my;
        int cnt=0,ans=INF;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>ma[i][j];
                if(ma[i][j]=='Y')yx=i,yy=j;
                if(ma[i][j]=='M')mx=i,my=j;
                if(ma[i][j]=='@')kfc[i][j]=cnt++;
            }
        }
        bfs(yx,yy,0);
        bfs(mx,my,1);
        for(int i=0;i<cnt;i++)
        {
            ans=min(ans,(len[0][i]+len[1][i]));
        }
        cout<<ans*11<<endl;
    }


}

