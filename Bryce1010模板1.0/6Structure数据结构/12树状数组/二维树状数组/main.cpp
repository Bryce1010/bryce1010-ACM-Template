struct BIT_2D
{
    int d[301][301];
    void update(int x,const int&y.const int&v)
    {
        for(;x<=n;x+=(x&(-x)))
            for(int j=y;j<=n;j+=(j&(-j)))
            d[x][j]+=V;
    }
    int getSum(int x,const int&y)
    {
        int res=0;
        for(;x;x-=(x&(-x)))
            for(int j=y;j;j-=(j&(-y)))
            res+=d[x][j];
        return res;
    }
}T;
