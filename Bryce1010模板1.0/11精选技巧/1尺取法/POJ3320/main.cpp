#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <math.h>
using namespace std;
#pragma warning(disable:4996)
typedef long long LL;
#define cinInt(a) scanf("%d",&a)
#define cinInt64(a) scanf("%I64d",&a)
#define cinDouble(a) scanf("%lf",&a)
const int INF = 1 << 30;
void input(int &x)
{
    char ch = getchar();
    while(ch>'9' || ch<'0')
        ch = getchar();
    x = 0;
    while(ch>='0' && ch<='9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
}
map<int,int> vis;
int a[10000000+10];
int main()
{
    int n,i;
    int cnt = 0;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0; i<n; ++i)
        {
           input(a[i]);
            if(!vis[a[i]])
            {
                vis[a[i]]++;
                cnt++;//知识点的个数
            }
        }
        vis.clear();
        int ans = INF;
        int s=0,t=0,cnt2=0;
        for(;;)
        {
            while(t<n && cnt2<cnt)//一定要找够cnt个知识点才能够跳出循环
            {
                if(vis[a[t]]==0)
                    cnt2++;
                vis[a[t++]]++;
            }
            if(cnt2<cnt)
                break;
            ans = min(ans,t-s);
            vis[a[s]]--;
            if(!vis[a[s++]])//因为区间的缩小，导致知识点的个数减少
                cnt2--;
        }
        printf("%d\n",ans);
    }
    return 0;
}
