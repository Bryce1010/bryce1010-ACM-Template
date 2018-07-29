/**************
*扩展欧几里得算法
*返回d=gcd(a,b)，和对应等式ax+by=d中的x,y
*/
long long extend_gcd(long long a,long long b,long long &x,long long &y)
{
    if(a==0&&b==0)return -1;//无最大公约数
    if(b==0){x=1;y=0;return a;}
    long long d=extend_gcd(b,a%b,y,x);
    y-=a/b*x;
}


