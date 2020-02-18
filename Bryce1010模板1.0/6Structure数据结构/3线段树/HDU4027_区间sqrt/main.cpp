#include<cstdio>
#include<cstring>
#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
#define MAXN 100005
struct node
{
    int l,r,mid;
    __int64 sum,len;//32位会WA
}tree[MAXN<<2];
void build(int l,int r,int now)
{
    tree[now].l=l;
    tree[now].r=r;
    tree[now].sum=0;
    tree[now].len=r+1-l;
    if(l==r)
    {
        scanf("%I64d",&tree[now].sum);
        return ;
    }
    tree[now].mid=(l+r)>>1;
    build(l,tree[now].mid,now<<1);
    build(tree[now].mid+1,r,now<<1|1);
    tree[now].sum=tree[now<<1].sum+tree[now<<1|1].sum;//弱爆了，刚开始这里都忘记写了
}
void update(int l,int r,int now)
{
    if(tree[now].l==l && tree[now].r==r)
    {
        if(tree[now].len==tree[now].sum)
        return ;
    }
    if(tree[now].l==tree[now].r)
    {
        tree[now].sum=(__int64)sqrt(1.0*tree[now].sum);//不知道为什么，这里直接开方不行，可能是64位的原因吧
        return;
    }
    if(l>tree[now].mid)
    update(l,r,now<<1|1);
    else
    {
        if(r<=tree[now].mid)
        update(l,r,now<<1);
        else
        {
            update(l,tree[now].mid,now<<1);
            update(tree[now].mid+1,r,now<<1|1);
        }
    }
    tree[now].sum=tree[now<<1].sum+tree[now<<1|1].sum;
}
__int64 query(int l,int r,int now)//64君哦
{
    if(l==tree[now].l && r==tree[now].r)
    return tree[now].sum;
    if(l>tree[now].mid)
    return query(l,r,now<<1|1);
    else
    {
        if(r<=tree[now].mid)
        return query(l,r,now<<1);
        else
        return query(l,tree[now].mid,now<<1)+query(tree[now].mid+1,r,now<<1|1);
    }
}
int main()
{
    int n,m,te=0;
    while(~scanf("%d",&n))
    {
        te++;
        build(1,n,1);
        scanf("%d",&m);
        printf("Case #%d:\n",te);
        while(m--)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            int l=min(b,c);//区间左右大小不一定
            int r=max(b,c);
            if(a==0)
                update(l,r,1);
            else
            {
                printf("%I64d\n",query(l,r,1));
            }
        }
        cout<<endl;//还有这里最后还PE一发
    }
    return 0;
}
