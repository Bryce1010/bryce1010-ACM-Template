/*
d(i,j)表示子序列Si,Si+1,...,Sk对应的树的个数
（1）边界条件d(1,1）=1，d(i,j)=0
（2）从i到j扫描，如果S[i]==s[k]表明第一个分支回到根
用d(i+1,k-1)表示，剩余部分为Sk....Sj，用d(k,j)表示(i+2<=k<=j)

*/
#include <iostream>
#include<string.h>
#include<algorithm>
#include<stdio.h>
using namespace std;

const int MAXN=300+10;
const int MOD=1000000000;

#define ll long long
char str[MAXN];
ll d[MAXN][MAXN];




ll dp(int i,int j)
{
    if(i==j)return 1;
    if(str[i]!=str[j])return 0;//d(i,j)=0
    ll &ans=d[i][j];
    if(ans>=0)return ans%MOD;
    ans=0;
    for(int k=i+2;k<=j;k++)
    {
        if(str[i]==str[k])
        {
            ans=(ans+dp(i+1,k-1)*dp(k,j))%MOD;
        }
    }
    return ans;
}

int main()
{
    while(scanf("%s",str)==1)
    {
        memset(d,-1,sizeof(d));
        cout<<dp(0,strlen(str)-1)<<endl;
    }
    return 0;
}
