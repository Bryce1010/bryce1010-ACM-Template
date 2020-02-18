#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std ;
typedef long long LL ;
#define rep( i , a , b ) for ( int i = ( a ) ; i <  ( b ) ; ++ i )
#define For( i , a , b ) for ( int i = ( a ) ; i <= ( b ) ; ++ i )
#define rev( i , a , b ) for ( int i = ( a ) ; i >= ( b ) ; -- i )
#define clr( a , x ) memset ( a , x , sizeof a )
const int MAXN = 100005 ;
const int N = 26 ;

struct Palindromic_Tree {
    int next[MAXN][N] ;
    int fail[MAXN] ;
    int cnt[MAXN] ;
    int len[MAXN] ;
    int S[MAXN] ;
    int last ;
    int n ;
    int p ;

    int newnode ( int l ) {
        for ( int i = 0 ; i < N ; ++ i ) next[p][i] = 0 ;
        cnt[p] = 0 ;
        len[p] = l ;
        return p ++ ;
    }

    void init () {
        p = 0 ;
        newnode (  0 ) ;
        newnode ( -1 ) ;
        last = 0 ;
        n = 0 ;
        S[n] = -1 ;
        fail[0] = 1 ;
    }

    int get_fail ( int x ) {
        while ( S[n - len[x] - 1] != S[n] ) x = fail[x] ;
        return x ;
    }

    int add ( int c ) {
        c -= 'a' ;
        S[++ n] = c ;
        int cur = get_fail ( last ) ;
        if ( !next[cur][c] ) {
            int now = newnode ( len[cur] + 2 ) ;
            fail[now] = next[get_fail ( fail[cur] )][c] ;
            next[cur][c] = now ;
        }
        last = next[cur][c] ;
        cnt[last] ++ ;
        return len[last] ;
    }

    void count () {
        for ( int i = p - 1 ; i >= 0 ; -- i ) cnt[fail[i]] += cnt[i] ;
    }
} ;

Palindromic_Tree T ;
int n ;
int len[MAXN] ;
char s[MAXN] ;

void solve () {
    int ans = 0 ;
    n = strlen ( s ) ;
    T.init () ;
    for ( int i = n - 1 ; i >= 0 ; -- i ) {
        len[i] = T.add ( s[i] ) ;
    }
    T.init () ;
    for ( int i = 0 ; i < n - 1 ; ++ i ) {
        ans = max ( ans , T.add ( s[i] ) + len[i + 1] ) ;
    }
    printf ( "%d\n" , ans ) ;
}

int main () {
    while ( ~scanf ( "%s" , s ) ) solve () ;
    return 0 ;
}
