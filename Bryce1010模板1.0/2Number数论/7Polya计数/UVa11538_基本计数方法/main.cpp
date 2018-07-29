#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long



int main()
{
    //cout << "Hello world!" << endl;
    ull n,m;
    while(cin>>n>>m)
    {
        if(n==0&&m==0)break;
        if(n>m)swap(n,m);
        ull A,B,D;
        A=n*m*(n-1);
        B=n*m*(m-1);
        D=2*n*(n-1)*(3*m-n-1)/3;
        cout<<(ull)A+B+D<<endl;
    }
    return 0;
}
