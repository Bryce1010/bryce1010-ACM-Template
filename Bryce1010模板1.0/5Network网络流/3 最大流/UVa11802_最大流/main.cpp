#include<bits/stdc++.h>
#define maxn 1000
#define INF (1<<31)-1

using namespace std;

struct Edge
{
    int from,to,cap,flow;
    Edge(int u,int v,int c,int f):
        from(u),to(v),cap(c),flow(f) {}
};

struct Dinic
{
    int n,m,s,t;
    vector<Edge> edges;
    vector<int> G[maxn];
    int d[maxn];
    int cur[maxn];
    bool vis[maxn];

    void init(int n)
    {
        for (int i=0; i<n; i++)
            G[i].clear();
        edges.clear();
    }

    void Addedge(int from,int to,int cap)
    {
        edges.push_back(Edge(from,to,cap,0));
        edges.push_back(Edge(to,from,0,0));
        m = edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }

    bool BFS()
    {
        memset(vis,false,sizeof(vis));
        for (int i=0; i<n; i++) d[i] = INF;
        d[s] = 0; vis[s] = true;

        queue<int> Q;
        Q.push(s);
        while (!Q.empty())
        {
            int x = Q.front();
            Q.pop();
            for (int i=0; i<G[x].size(); i++)
            {
                Edge e = edges[G[x][i]];
                if (!vis[e.to] && e.cap>e.flow)
                {
                    vis[e.to] = true;
                    d[e.to] = d[x]+1;
                    Q.push(e.to);
                }
            }
        }
        return vis[t];
    }

    int DFS(int x,int a)
    {
        if (x == t || a == 0)
            return a;
        int flow = 0,f;
        for (int i=cur[x]; i<G[x].size(); i++)
        {
            Edge& e = edges[G[x][i]];
            if (d[e.to] == d[x]+1 && (f = DFS(e.to,min(a,e.cap-e.flow))) > 0)
            {
                e. flow += f;
                edges[G[x][i]^1].flow -= f;
                flow += f;
                a -= f;
                if (a == 0)
                    break;
            }
        }
        return flow;
    }

    bool OKA()
    {
        for (int i=0; i<G[s].size(); i++)
        {
            Edge e = edges[G[s][i]];
            if (e.cap!=e.flow)
                return false;
        }
        return true;
    }

    bool OKB(int R,int C)
    {
        for (int j=R+1; j<=R+C; j++)
        {
            Edge& e = edges[G[j][0]];
            if (e.cap!=e.flow)
                return false;
        }
        return true;
    }

    void Maxflow(int t,int R,int C)
    {
        int flow = 0;
        while (BFS())
        {
            memset(cur,0,sizeof(cur));
            flow += DFS(s,INF);
        }

        cout<<"Matrix "<<t<<endl;
        if (OKA() && OKB(R,C))
        {
            for (int i=1; i<=R; i++)
            {
                int j;
                for (j=1; j<G[i].size()-1; j++)
                    cout<<edges[G[i][j]].flow+1<<' ';
                cout<<edges[G[i][j]].flow+1<<endl;
            }
        }
        cout<<endl;
    }
};

int main()
{
    Dinic aa;
    int T,R,C,tmp;
    int a[30],b[30],c[30],d[30];
 #ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    cin>>T;
    tmp = T;
    while (T>0)
    {
        T--;
        aa.init(maxn);
        cin>>R>>C;
        for (int i=1; i<=R; i++) cin>>a[i];
        for (int i=1; i<=C; i++) cin>>b[i];
        for (int i=1; i<=R; i++) c[i] = a[i]-a[i-1]-C;
        for (int i=1; i<=C; i++) d[i] = b[i]-b[i-1]-R;

        for (int i=1; i<=R; i++)
            aa.Addedge(0,i,c[i]);
        for (int i=1; i<=C; i++)
            aa.Addedge(R+i,R+C+1,d[i]);
        for (int i=1; i<=R; i++)
            for (int j=1; j<=C; j++)
                aa.Addedge(i,R+j,19);
        aa.s = 0; aa.t = R+C+1;
        aa.Maxflow(tmp-T,R,C);
    }
    return 0;
}
