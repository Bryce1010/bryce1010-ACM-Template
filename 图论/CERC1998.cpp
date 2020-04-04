//
// Created by xyang01 on 2020/4/4.
//

#include<bits/stdc++.h>
using namespace std;
const int N=1e6,INF=0x3f3f3f3f;

struct qnode{
    int v, cost;
    qnode(int _v=0,int _cost=0):v(_v),cost(_cost){}

};

struct Edge{
    int nxt;
    int w;
    Edge(int _nxt=0,int w=0):nxt(_nxt),w(_w){}
};
vector<Edge>E[N];

void add_edge(int u,int v,int weight){
    E[u].push_back(Edge(v,weight));
}


bool vis[N];
int dist[N];

void dijkstra(int n,int start){

    dist[start]=0;
    for(int i=0;i<n;++i)dist[i]=INF;
    priority_queue<qnode>que;
    while(!que.empty())
        que.pop();
    qnode tmp;
    que.push(qnode(start,0));
    while(!que.empty()){
        tmp=que.top();
        que.pop();
        int u=tmp.v;
        if(vis[u])continue;
        vis[u]=true;
        for(int j=0;j<E[u].size();++j){
            int v=E[u][j].nxt;
            int cost=E[u][j].w;
            if(!vis[v]&&dist[u]+cost<dist[v]){
                dist[v]=dist[u]+cost;
                que.push(qnode(v,dist[v]));
            }
        }
    }




}















