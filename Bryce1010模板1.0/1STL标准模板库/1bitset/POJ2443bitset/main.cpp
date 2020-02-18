
/*
题意：给出n个集合(n<=1000),每个集合中最多有10000个数，
每个数的范围为1~10000，给出q次询问(q<=200000),
每次给出两个数u，v判断是否有一个集合中同时含有u，v两个数
*/
#include<iostream>
#include<bitset>
#include<stdio.h>
using namespace std;

bitset<1001>b[10010];

int main()
{
    int n,c,q;
    int p,x,y;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&c);
        for(int j=1;j<=c;j++)
        {
            scanf("%d",&p);
            b[p].set(i);
        }
    }
    cin>>q;
    for(int i=1;i<=q;i++)
    {
        scanf("%d%d",&x,&y);
        int flag=0;
        if((b[x]&b[y]).any())flag=1;
        if(flag)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;

    }

    return 0;
}
