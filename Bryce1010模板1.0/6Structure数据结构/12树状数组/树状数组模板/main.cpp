int d[100005],n;


int lowbit(int x)
{
    return x&(-x);
}
int query(int x)//查询前缀和
{
    int res=0;
    while(x)
    {
        res+=d[x];
        x-=lowbit(x);
    }
    return res;
}
void add(int x,int v)//单点加操作
{
    while(x<=n)
    {
        d[x]+=v;
        x+=lowbit(x);
    }
}


