#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXN=1e3+10;
int c[MAXN<<1][MAXN<<1];
int n,q;
int lowbit(int x)
{
    return x&(-x);
}

void update(int posi,int posj,int val)
{
    int tmpj;
    while(posi<=n)
    {
        tmpj=posj;
        while(tmpj<=n)
        {
            c[posi][tmpj]+=val;
            tmpj+=lowbit(tmpj);
        }
        posi+=lowbit(posi);
    }
}

int getSum(int posi,int posj)
{
    int ans=0;
    int tmpj=posj;
    while(posi>0)
    {
        tmpj=posj;
        while(tmpj>0)
        {
            ans+=c[posi][tmpj];
            tmpj-=lowbit(tmpj);
        }
        posi-=lowbit(posi);
    }
    return ans;
}






int main()
{
    int t;
    cin>>t;
    while(t--)
    {

        char ch;
        int x1,y1,x2,y2;
        int x,y;
        cin>>n>>q;
        while(q--)
        {
            cin>>ch;
            if(ch=='C')
            {
                cin>>x1>>y1>>x2>>y2;
                update(x1,y1,1);
                update(x2+1,y1,1);
                update(x1,y2+1,1);
                update(x2+1,y2+1,1);
            }
            else
            {
                cin>>x>>y;
                //查询前k的和对2取模即可
                cout<<getSum(x,y)%2<<endl;
            }
        }
    }


    return 0;
}




