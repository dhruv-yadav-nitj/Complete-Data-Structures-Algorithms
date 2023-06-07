#include <bits/stdc++.h>
using namespace std ;

void solve()
{
    int n ; cin >> n ;
    int odd = 0, even =0 ;
    for(int i=0; i < n ; i++){
        int temp ; cin >> temp ;
        if(temp%2 ==1){
            // means odd
            odd += temp ;
        }
        else{
            even += temp ;
        }
    }

    if(even > odd){cout << "YES" << endl ;}
    else{cout << "NO" << endl;}
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