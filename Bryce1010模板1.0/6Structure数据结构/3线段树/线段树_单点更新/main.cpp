

const int MAXN=2005+5;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
int sum[MAXN<<2];//表示线段树节点，需要开到最大值的四倍
void push_up(int rt)
{
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
//建树
void build(int l,int r,int rt=1)
{
    //建树，生成一个区间l~r的完全二叉树
    if(l==r)
    {
        sum[rt]=0;
        return;
    }
    int m=(l+r)>>1;
    build(l,m,rt);
    build(m+1,r,rt);
    push_up(rt);//由底向上更新
}


//更新点和包含点的枝
void update(int pos,int val,int l,int r,int rt=1)
{
    //pos为更新的位置，val为增加的值，正则加，负则减
    //l,r为两个端点值
    if(l==r)
    {
        sum[rt]+=val;
        return;
    }
    int m=(r+l)>>1;
    if(pos<=m)//pos在左子树
    {
        update(pos,val,l,mid,rt);
    }
    else
    {
        update(pos,val,mid+1,r,rt);
    }
    //更新包含该点的一系列区间
    push_up(rt);

}
//查询点或区间
int query(int L,int R,int l,int r,int rt=1)
{
    //L,R为被查询区间，l,r为当前树的总区间
    //如果子区间包当前树的总区间
    if(L<=l&&R>=r)
    {
        return sum[rt];//返回当前区间的和
    }
    int mid=(l+r)>>1;
    int res=0;
    if(L<=m)
    {
        res+=query(L,R,l,mid,rt);
    }
    else
    {
        res+=query(L,R,mid+1,r,rt);
    }
    return res;
}
