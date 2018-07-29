//http://www.cppblog.com/keroro/archive/2013/05/27/200622.html?opt=admin

#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <deque>
using namespace std;
#define     MAXN    101
#define     INF     99999999
#define     debug   printf("!\n")
struct Edge { int u,v; } edge[3001];
vector<int> vertex[MAXN];
int visit[MAXN], sum[MAXN], cnt[MAXN][MAXN];        //cnt[u][v]表u--v的边有多少条，用来处理重边
bool used[MAXN][MAXN][MAXN];                        //used[x][u][v]x的最短路树是否用到了边u--v
int n, m;

void init();
void dijkstra(int s, int when, int flag);
int main()
{
    int when = 0;
    int u, v;
    while(scanf("%d%d", &n, &m) != EOF) {
        init();
        for(int i = 0; i < m; i++) {
            scanf("%d%d", &u, &v);
            vertex[u].push_back(v);
            vertex[v].push_back(u);
            edge[i].u = u, edge[i].v = v;
            cnt[u][v]++, cnt[v][u]++;
        }
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            dijkstra(i, ++when, 1);
            ans += sum[i];
        }
        for(int i = 0; i < m; i++) {
            int tmp = ans;
            int u = edge[i].u, v = edge[i].v;
            //forbid_u = edge[i].u, forbid_v = edge[i].v;       因为有重边所以不能用这种方法
            for(int j = 1; j <= n; j++) if(used[j][u][v] && cnt[u][v] == 1) {       //不加cnt[u][v] == 1会超时。。卡的就是重边，靠！
                int tmp = sum[j];
                sum[j] = 0;
                //vector<int> :: iterator it1 = find(vertex[u].begin(), vertex[u].end(), v);
                //vector<int> :: iterator it2 = find(vertex[v].begin(), vertex[v].end(), u);
                //*it1 = u, *it2 = v;
                cnt[u][v]--, cnt[v][u]--;
                dijkstra(j, ++when, 2);
                cnt[u][v]++, cnt[v][u]++;
                //*it1 = v, *it2 = u;     //本来是用erase的，超时了。 现在换这种方法也超时了，估计find耗时太久。
                ans = ans - tmp + sum[j];   //用新的sum[j]来代替旧的tmp
                sum[j] = tmp;
                int k ;
                for(k = 1; k <= n; k++) if(visit[k] != when) break;     //如果删边了以后j不能到达k(即k没有进过队)
                if(k <= n) {
                    ans = INF;
                    break;
                }
            }
            ans == INF ? printf("INF\n") : printf("%d\n", ans);
            ans = tmp;  //不要把这个tmp和for_j里的tmp混了..
        }
        for(int i = 0; i < m; i++) cnt[edge[i].u][edge[i].v] = cnt[edge[i].v][edge[i].u] = 0;   //初始化因为感觉memset(cnt)会不会花更多时间
    }
    return 0;
}
void dijkstra(int s, int when, int flag)
{
    int floors = 1;
    int cur = 0;
    deque<int> Q[2];
    Q[cur].push_back(s);
    visit[s] = when;
    do {
        while(!Q[cur].empty()) {
            int u = Q[cur].front();
            Q[cur].pop_front();
            for(int Size = vertex[u].size(), i = 0; i < Size; i++) {
                int v = vertex[u][i];
                if(visit[v] != when && cnt[u][v] > 0) {
                    if(flag == 1) used[s][u][v] = used[s][v][u] = true;   //第一次最短路才标记used因为懒得写两遍，所以要flag来标记是删边前还收删边后做的最短路，1则是预处理时的最短路，此时要标记used；2则是删边后的最短路，这个时候不能标记used.
                    visit[v] = when;
                    sum[s] += floors;
                    Q[1-cur].push_back(v);
                }
            }
        }
        floors++;
        cur = 1 - cur;
    } while(!Q[cur].empty());
}
void init()
{
    memset(sum, 0, sizeof(sum));
    memset(used, false, sizeof(used));
    for(int i = 1; i <= n; i++) vertex[i].clear();
}
