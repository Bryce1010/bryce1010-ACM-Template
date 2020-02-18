#include<bits/stdc++.h>
using namespace std;




const int MAXN=10010;
struct Node *null;
struct Node
{
    Node *fa,*ch[2];
    int Max,key;
    inline void push_up()
    {
        if(this==null)return;
        Max=max(key,max(ch[0]->Max,ch[1]->Max));
    }
    //设置儿子节点
    inline void setc(Node *p,int d)
    {
        char[d]=p;
        p->fa=this;
    }
    //判断儿子节点1是右儿子，0是左儿子
    inline bool d()
    {
        return fa->ch[1]==this;
    }
    //判断是否是根节点
    inline bool isroot()
    {
        return fa==null||fa->ch[0]!=this&&fa->ch[1]!=this;
    }
    //splay的rotate操作
    inline void rot()
    {
        Node *f=fa,*ff=fa->fa;
        int c=d(),cc=fa->d();
        f->setc(ch[!c],!c);
        this->setc(f,!c);
        if(ff->ch[cc]==f)ff->setc(this,cc);
        else this->fa=ff;
        f->push_up();
    }

    //splay操作
    inline Node * splay()
    {
        while(!isroot())
        {
            if(!fa->isroot())
                d()==fa->d()?fa->rot():rot();
            rot();
        }
        push_up();
        return this;
    }
    //access操作
    inline Node* access()
    {
        for(Node *p=this,*q=null;p!=null;q=p,p=p->fa)
        {
            p->splay()->setc(q,l);
            p->push_up();
        }
        return splay();
    }

};

Node pool[MAXN],*tail;





bool cmp(const  pair<int,int>p1,const pair<int,int>p2)
{
    return .....
}







