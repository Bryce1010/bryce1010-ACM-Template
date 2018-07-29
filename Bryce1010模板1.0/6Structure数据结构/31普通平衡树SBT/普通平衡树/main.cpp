#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define lc ch[0]
#define rc ch[1]


const int MAXN=500000;
const int INF=0x3f3f3f3f;

struct node
{
    node* ch[2];
    int sz,v;
    node(){}

}SBT[MAXN+10],*NILL=new node,*root=NILL,*tot=SBT;


int getint()
{
    int ret=0;bool f=0;char ch;
    while((ch=getchar())<'0'||ch>'9')f=!f;
    while(ch>='0'&&ch<='9')ret=ret*10+(ch-'0');
    return f?-ret:ret;
}
void init()
{
    NILL->lc=NILL;
    NILL->rc=NILL;
    NILL->sz=0;
}
//更新子树大小
inline void update(node* r)
{
    r->sz=r->lc->sz+rc->sz+1;
}

node* newnode()
{
    tot->lc=tot->rc=NILL;
    tot->sz=1;
    return tot++;
}

void rotate(node* r,bool f)
{
    node *t=r->ch[f];
    r->ch[f]=t->ch[!f];
    t->ch[!f]=r;
    t->sz=r->sz;
    update(r);
    r=t;
}

void mt(node* &r,bool f)//利用左右对称，带上参数f同时减去不必要的检查
{
    if(r==NILL)return;//NILL为空指针
    if(r->ch[f]->ch[f]->sz>r->ch[!f]->sz)//左左>右
    {
        rotate(r,f);
    }
    else if(r->ch[f]->ch[!f]->sz>r->ch[!f]->sz)//左右>右,先旋左儿子，再旋根
    {
        rotate(r->ch[f],!f);rotate(r,f);
    }
    else return;
    mt(r->ch[f],f);
    mt(r,f);
}

void insert(node* &r,int v)
{
    if(r==NILL)
    {
        r=newnode();
        r->v=v;
        return;
    }
    r->sz++;
    bool k=v>r->v;
    insert(r->ch[k],v);
    mt(r,k);
}

int del(node* &r,int x)
{
    int ret;
    r->sz--;
    if(r->v==x||(r->lc==NILL&&x<r->v)||(r->rc==NILL&&x>r->v))//删除根节点的情况
    {
        ret=r->v;
        if(r->lc==NILL||r->rc==NILL)
            r=r->lc==NILL?r->rc:r->lc;
        else
            r->v=del(r->lc,x);

    }
    else ret=del(r->ch[x>=r->v],x);
    return ret;
}

int sel(int val)//val的排位
{
    int ret=1;
    node* p=root;
    while(p!=NILL)
    {
        if(val<=p->v)
        {
            p=p->lc;
        }
        else
        {
            ret+=p->lc->sz+1;
            p=p->rc;
        }
    }
    return ret;
}


int rk(int x)//排第x的值
{
    node* p=root;
    while(p!=NILL)
    {
        if(x==p->lc->sz+1)
            return p->v;
        if(x<=p->lc->sz)
            p=p->lc;
        else
        {
            x-=p->lc->sz+1;
            p=p->rc;
        }
    }
    return INF;
}

//查询前驱（0）后继（1）
int query(int v,bool f)
{
    node* p=root;
    int ret=f?INF:-INF;
    while(p!=NILL)
    {
        if(p->v!=v&&(f==(p->v>v)&&f==(ret>p->v)))
        {
            ret=p->v;
        }
        if(v==p->v)
            p=p->ch[f];
        else p=p->ch[v>p->v];
    }
    return ret;
}


int main()
{
    init();
    int kase=getint();
    while(kase--)
    {
        int opt=getint(),x=getint();
        switch(opt)
        {
            case 1:insert(root,x);break;
            case 2:del(root,x);break;
            case 3:printf("%d\n",sel(x));break;
            case 4:printf("%d\n",rk(x));break;
            case 5:printf("%d\n",query(x,0));break;
            case 6:printf("%d/n",query(x,1));break;
        }
    }
    return 0;
}










