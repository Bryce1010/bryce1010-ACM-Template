#include<bits/stdc++.h>
using namespace std;
const int N=25;

char s1[N],s2[N];
int vis[N][N],cnt[N][N];

int n,m;
void dfs(int x,int y){
    if(x<1||x>n||y<1||y>m||vis[x][y])return;
    ++cnt[x][y];
    vis[x][y]=1;
    if(s1[x]=='<')
        dfs(x,y-1);
    else dfs(x,y+1);
    if(s2[y]=='v')
        dfs(x+1,y);
    else dfs(x-1,y);
}


int main(){

    scanf("%d%d",&n,&m);
    scanf("%s%s",s1+1,s2+1);

    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            memset(vis,0,sizeof(vis));
            dfs(i,j);
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(cnt[i][j]!=m*n) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout<<"YES"<<endl;
    return 0;

}









