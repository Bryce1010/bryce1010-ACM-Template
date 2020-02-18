#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

const int MAXN=5e4+10;
int sum[MAXN<<2];

void pushup(int rt)
{
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
int x;
void build(int l,int r,int rt=1)
{
    if(l==r)
    {
        scanf("%d",&x);
        sum[rt]=x;
        return ;
    }
    int m=(r+l)/2;
    build(lson);
    build(rson);
    pushup(rt);

}

void update(int pos,int val,int l,int r,int rt=1)//单点更新,增加val
{
    if(l==r)
    {
        sum[rt]+=val;
        return;
    }
    int m=(r+l)/2;
    if(pos<=m)
    {
        update(pos,val,lson);
    }
    else
    {
        update(pos,val,rson);
    }
    pushup(rt);
}


int query(int L,int R,int l,int r,int rt=1)
{
    if(L<=l&&r<=R)//包含整个区间
    {
        return sum[rt];
    }
    int m=(l+r)/2;
    int ans=0;
    //左端点在左子树
    if(L<=m)
        ans+=query(L,R,lson);
    //又端点在右子树
    if(R>m)
        ans+=query(L,R,rson);
    return ans;
}











int main()
{
    //cout << "Hello world!" << endl;
    //freopen("in.txt","r",stdin);
    int t;
    cin>>t;
    int Case=1;
    while(t--)
    {
        printf("Case %d:\n",Case++);
        //cout<<"Case "<<Case++<<":"<<endl;
        int n;
        scanf("%d",&n);
        build(1,n,1);
        //int x;
        string str;
        while(cin>>str)
        {
            if(str=="End")break;
            if(str=="Query")
            {
                int le,ri;
                scanf("%d%d",&le,&ri);
                //cin>>le>>ri;
                printf("%d\n",query(le,ri,1,n,1));
                //cout<<query(le,ri,1,n,1)<<endl;
            }
            else if(str=="Add")
            {
                int pos,val;
                scanf("%d%d",&pos,&val);
                //cin>>pos>>val;
                update(pos,val,1,n,1);
            }
            else
            {
                int pos,val;
                scanf("%d%d",&pos,&val);
                //cin>>pos>>val;
                update(pos,-val,1,n,1);
            }
        }
    }

    return 0;
}
