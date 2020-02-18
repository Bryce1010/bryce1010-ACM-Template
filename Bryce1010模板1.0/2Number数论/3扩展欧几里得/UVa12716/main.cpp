
#include<bits/stdc++.h>
using namespace std;

#define maxn 30000000
int cnt=0;
int v[maxn]={0};
int a,b,c,n;
int init(){
    for (c=1;c<=maxn/2;c++)
        for (a = c + c ; a <= maxn ; a += c){
            b=a-c;
            if (c==(a^b)) v[a]++;
        }
    for(int i = 2 ; i <= maxn ; i++)
         v[i] += v[i - 1];
}
int main (int argc, char* argv[]) {
    int T;
    scanf("%d",&T);
    int cas=0;
    init();
    while (T--){
        cas++;
        scanf("%d",&n);
        int ans=0;
        //for (int i=1;i<=n;i++) ans+=v[i];
        printf("Case %d: %d\n",cas,v[n]);
    }
    return 0;
}
