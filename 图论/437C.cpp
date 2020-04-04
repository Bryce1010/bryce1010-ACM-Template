//本题也可以用多种思路, 第一种是, 对node权重降序排列, 一个一个取 
// 第二个思路, 发现其实每条边的贡献是边的两个点之间的更小值, 遍历每条边, 累加最小值

#include<bits/stdc++.h>
using namespace std;



const int N=2000+10,INF=0x3f3f3f3f;
struct qnode{
    int v, cost;
    qnode(int _v=0,int _cost=0):v(_v),cost(_cost){}
    bool operator < (const qnode& r)const{
        return cost>r.cost;
    }
}node[N];


struct Edge{
    qnode nxt;
    int w;
    Edge(qnode _nxt,int _w=0):w(_w){
        nxt.v=_nxt.v;
        nxt.cost=_nxt.cost;
    }

};


vector<Edge>E[N];
int vis[N];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i){
        cin>>node[i].cost;
        node[i].v=i;
    }
    for(int j=0;j<m;++j){
        int u,v;
        cin>>u>>v;
        E[u-1].push_back(Edge(node[v-1],1));
        E[v-1].push_back(Edge(node[u-1],1));
    }
    sort(node,node+n);
    int ans=0;
    for(int i=0;i<n;++i){
        int id=node[i].v;
        vis[id]=1;
        for(int j=0;j<E[id].size();++j){
            int v=E[id][j].nxt.v;
            int cost=E[id][j].nxt.cost;
            if(!vis[v]){
                //vis[v]=1;
                ans+=cost;
            }
        }
    }
    cout<<ans<<endl;
}








