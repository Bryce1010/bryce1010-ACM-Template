#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 105*3;
const ll INF = 1000000000;
int n,m,u,v,c,b,t,p[maxn],a[maxn],inq[maxn],d[maxn];
struct Edge {
    int from, to, cap, flow, cost;
    Edge(int u,int v,int c,int f,int w):from(u),to(v),cap(c),flow(f),cost(w) {}
};
vector<Edge> edges;
vector<int> g[maxn];
void init() {
    for(int i=0;i<maxn;i++) g[i].clear();
    edges.clear();
}
void AddEdge(int from, int to, int cap, int cost) {
    edges.push_back(Edge(from,to,cap,0,cost));
    edges.push_back(Edge(to,from,0,0,-cost));
    t = edges.size();
    g[from].push_back(t-2);
    g[to].push_back(t-1);
}
bool BellmanFord(int s,int t,int& flow, ll& cost) {
    for(int i=0;i<maxn;i++) d[i] = INF;
    memset(inq,0,sizeof(inq));
    d[s] = 0; inq[s] = 1; p[s] = 0; a[s] = INF;
    queue<int> Q;
    Q.push(s);
    while(!Q.empty()) {
        int u = Q.front(); Q.pop();
        inq[u] = 0;
        for(int i = 0; i < g[u].size(); i++) {
            Edge& e = edges[g[u][i]];
            if(e.cap > e.flow && d[e.to] > d[u] + e.cost) {
                d[e.to] = d[u] + e.cost ;
                p[e.to] = g[u][i];
                a[e.to] = min(a[u],e.cap - e.flow);
                if(!inq[e.to]) { Q.push(e.to); inq[e.to] = 1; }
            }
        }
    }
    if(d[t] == INF) return false;

    flow += a[t];
    cost += (ll)d[t] *(ll)a[t];
    for(int u = t; u != s; u = edges[p[u]].from) {
        edges[p[u]].flow += a[t];
        edges[p[u]^1].flow -= a[t];
    }
    return true;
}
int MincostMaxflow(int s,int t, ll& cost) {
    int flow = 0; cost = 0;
    while(BellmanFord(s,t,flow,cost)) ;
    return flow;
}
int main() {
    while(~scanf("%d",&n)&&n) {
        init();
        for(int i=1;i<=n;i++) {
            while(true) {
                scanf("%d",&b);
                if(b == 0) break;
                scanf("%d",&c);
                AddEdge(i,b+n,1,c); //²ð·Ö½áµã
            }
            AddEdge(0,i,1,0);
            AddEdge(i+n,2*n+1,1,0);
        }
        ll cost;
        int flow = MincostMaxflow(0,2*n+1,cost);
        if(flow == n) printf("%lld\n",cost);
        else printf("N\n");
    }
    return 0;
}
