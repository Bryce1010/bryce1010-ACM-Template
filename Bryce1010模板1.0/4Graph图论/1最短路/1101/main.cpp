#include <iostream>

using namespace std;


//dp[i][j]
const int MAXN=1e5+5;
int a[]={1,2,5,10,20,50,100,200,500,1000,2000,5000,10000};
const int MOD=1e9+7;
int dp[MAXN];


int main()
{
    int n;
    cin>>n;
    dp[0]=1;
    for(int i=0;i<13;i++)
    {
        for(int j=a[i];j<=n;j++)
        {
            dp[j]=(dp[j]+dp[j-a[i]])%MOD;
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}
