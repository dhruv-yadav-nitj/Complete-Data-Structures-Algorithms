#include <bits/stdc++.h>
using namespace std ;

void solve()
{
    int n ; cin >> n ;
    for(int i= n ; i > 0;  i--){
        if(i%2 ==0){cout <<  i/2 << endl ; break ;}
    }
}

int main()
{
    long long t ; cin >> t ;
    while (t--)
    {
        solve() ;
    }
    return 0;
}