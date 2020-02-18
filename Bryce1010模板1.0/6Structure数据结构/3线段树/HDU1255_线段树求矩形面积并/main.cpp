#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lson l,m,rt<<1
#define rson m,r,rt<<1|1
const int MAXN=1e5+10;

double y[MAXN<<2];
struct Line
{
    double x;//记录线段位置
    double y_up,y_down;
    int flag;//左线段为1，右线段为-1
}line[MAXN<<2];

struct Node
{
    double l,r,x;//l维护区间,r维护右区间,x记录上一个x的位置，用于求面积
    bool flag;//标记只有一个区间的节点，将连续的区间离散化为节点
    int cover;//记录覆盖的线段数


}tree[MAXN<<2];

void pushup(int rt)
{
    tree[rt].l=tree[rt>>1].l;
    tree[rt].r=tree[rt>>1|1].r;
}

void build(int l,int r,int rt)
{
    tree[rt].l=y[l];
    tree[rt].r=y[r];
    tree[rt].x=-1;//前一个位置
    tree[rt].flag=false;//不是只有一个区间
    tree[rt].cover=0;
    if(l+1==r)//因为是区间是连续数
    {
        tree[rt].flag=true;//叶子节点
        return;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);//区间是连续的，m不需要+1
}
//flag表示左边线段还是右边线段，碰到左边线段+1,碰到右边线段-1
double query(double l,double r,int rt,double x,int flag)
{
    //如果查找区间不在范围内
    if(l>=tree[rt].r||r<=tree[rt].l)
    {
        return 0;
    }
    //如果是只有一个区间的节点,叶子节点
    if(tree[rt].flag)
    {
        //观察当前范围是否有覆盖区间
        if(tree[rt].cover>1)
        {
            //计算面积
            double pre=tree[rt].x;
            double ans=(x-pre)*(tree[rt].r-tree[rt].l);
            tree[rt].x=x;//更新这个节点，方便下一次计算
            tree[rt].cover+=flag;
            return ans;
        }
        else
        {
            tree[rt].x=x;
            tree[rt].cover+=flag;
            return 0;
        }
    }
    double ans1,ans2;
    ans1=query(l,r,rt<<1,x,flag);
    ans2=query(l,r,rt<<1|1,x,flag);
    return ans1+ans2;
}

bool cmp(Line l1,Line l2)
{
    return l1.x<l2.x;
}

int main()
{
    int t,n;
    double x1,y1,x2,y2;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int cnt=-1;
        for(int i=0;i<n;i++)
        {
            cin>>x1>>y1>>x2>>y2;
            y[++cnt]=y1;
            line[cnt].x=x1;
            line[cnt].y_down=y1;
            line[cnt].y_up=y2;
            line[cnt].flag=1;


            y[++cnt]=y2;
            line[cnt].x=x2;
            line[cnt].y_down=y1;
            line[cnt].y_up=y2;
            line[cnt].flag=-1;
        }
        //将所有高度排序
        sort(y,y+cnt+1);
        //将所有线段排序
        sort(line,line+cnt+1,cmp);
        build(0,cnt,1);
        //扫描线扫描所有的线段
        double area=0;
        for(int i=0;i<=cnt;i++)
        {
            area+=query(line[i].y_down,line[i].y_up,1,line[i].x,line[i].flag);
        }

        printf("%.2f\n",area);

    }


    return 0;
}























