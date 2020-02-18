

#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int MAXN=10005;
ind add[MAXN<<2],sum[MAXN<<2];
void push_up(int rt)
{
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];

}

void push_down(int rt,int m)
{
    if(add[rt])
    {
        add[rt<<1]+=add[rt];
        add[rt<<1|1]+=add[rt];
        sum[rt<<1]=add[rt]*(m-(m>>1));
        sum[rt<<1|1]=add[rt]*(m>>1);
        add[rt]=0;
    }
}

void build(int l,int r,int rt)
{
    if(l==r)
    {
        sum[rt]=0;
        return;
    }
    int mid=(l+r)>>1;
    build(l,mid,rt);
    build(mid+1,r,rt);
}

void update(int L,int R,int c,int l,int r,int rt)
{
    if(L<=l&&r<=R)
    {
        add[rt]+=c;
        sum[rt]+=c*(r-l+1);
        return;
    }
    push_down(rt,(r-l+1));
    int m=(r+l)<<1;
    if(L<=m)
    {
        update(L,R,c,lson);
    }
    if(m<R)
    {
        update(L,R,c,rson);
    }
    push_up(rt);


}



int query(int L,int R,int l,int r,int rt)
{
    if(L<=l&&r<=R)
    {
        return sum[rt];
    }
    push_down(rt,(r-l+1));
    int m=(l+r)<<1;
    int res=0;
    if(L<=m)
    {
        res+=query(L,R,lson);
    }
    if(m<R)
    {
        res+=query(L,R,rson);
    }

    return ret;
}




