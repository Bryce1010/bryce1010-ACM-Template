#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
using namespace std;
typedef long long ll;
map<char,int>mp;
int main()
{  string s;
    while(cin>>s){
         int max1=-1;
         int max2=-1;
         bool flag=false;
         bool kk=false;
         for(int i=0;i<s.length();i++){
             if(s[i]>='A'&&s[i]<='Z')
                {flag=true;
                 max2=max(max2,s[i]-'A');
                }
              else if(s[i]>='0'&&s[i]<='9')
                    max1=max(max1,s[i]-'0');
         }
         if(!flag){
         for(int i=max1+1;i<=36;i++){
            ll k=1;
             ll sum=0;
             for(int j=0;j<s.length();j++){
                sum=sum*i+1ll*(s[j]-'0');
                sum%=(i-1);
                }
             if(!sum)
             {printf("%d\n",i);kk=true;break;}
         }
         }
         else{
             for(int i=max2+11;i<=36;i++){
                ll  k=1;
                ll sum=0;
                for(int j=0;j<s.length();j++){
                    if(s[j]>='0'&&s[j]<='9')
                    sum =1ll*(s[j]-'0')+sum*i;
                   else
                      sum=1ll*(s[j]-'A'+10)+sum*i;
                      sum%=(i-1);
                      }
                 //if(i==22)
                    //cout<<sum<<"@@@@"<<endl;

                if(!sum)
                    {printf("%d\n",i);
                      //cout<<"!!"<<max2+11<<endl;
                      //cout<<sum<<endl;
                      //cout<<(i-1)<<endl;
                      kk=true;
                     break;}

             }

         }
         if(!kk)
            puts("No solution");


    }




    return 0;
}
