/*划分树
查询区间第K大

*/

#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

#define ll long long
const int MAXN=100009;
int tree[21][MAXN];//表示每层每个位置的值
int sorted[MAXN];//已经排序好的数
int toleft[21][MAXN];//toleft[p][i]表示第i层从1到i有多少数划入左边

/*建树
same表示等于sorted[mid]的个数,初始化为mid-l+1，扫描后每出现一个更小的值，减1
所以same表示要被分入左边等于中间值的个数
建树分三种情况：
1、如果tree[[dep][i]<sorted[mid]划入左边
2、如果tree[dep][i]==sorted[mid],same>0的话划入左边
3、否则就是划入右边
*/

void build(int l,int r,int dep)
{
    if(l==r)return;
    int mid=(l+r)>>1;
    int same=mid-l+1;
    for(int i=l;i<=r;i++)
    {
        if(tree[dep][i]<sorted[mid])
        {
            same--;
        }
    }
    int lpos=l;
    int rpos=mid+1;
    for(int i=l;i<=r;i++)
    {
        if(tree[dep][i]<sorted[mid])
            tree[dep+1][lpos++]=tree[dep][i];
        else if(tree[dep][i]==sorted[mid]&&same)
        {
            tree[dep+1][lpos++]=tree[dep][i];
            same--;
        }
        else
        {
            tree[dep+1][rpos++]=tree[dep][i];
        }
        toleft[dep][i]=toleft[dep][l-1]+lpos-l;
    }
    build(l,mid,dep+1);
    build(mid+1,r,dep+1);
}
/*查询操作
查询区间第K大值，[L,R]是大区间，[l,r]是要查询的小区间
cnt记录划入左边的个数
1、如果cnt>=k，说明第K大在左子树
2、否则，说明第K大在右子树
*/
int query(int L,int R,int l,int r,int dep,int k)
{
    if(l==r)return tree[dep][l];
    int mid=(L+R)>>1;
    int cnt=toleft[dep][r]-toleft[dep][l-1];
    if(cnt>=k)
    {
        int newl=L+toleft[dep][l-1]-toleft[dep][L-1];
        int newr=newl+cnt-1;
        return query(L,mid,newl,newr,dep+1,k);
    }
    else
    {
        int newr=r+toleft[dep][R]-toleft[dep][r];
        int newl=newr-(r-l-cnt);
        return query(mid+1,R,newl,newr,dep+1,k-cnt);
    }
}

int main()
{
    int n,m;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        memset(tree,0,sizeof(tree));
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&tree[0][i]);
            sorted[i]=tree[0][i];
        }
        sort(sorted+1,sorted+n+1);
        build(1,n,0);
        int s,t,k;
        while(m--)
        {
            scanf("%d%d%d",&s,&t,&k);
            printf("%d\n",query(1,n,s,t,0,k));
        }
    }
    return 0;
}









