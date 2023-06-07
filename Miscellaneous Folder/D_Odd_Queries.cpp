#include <bits/stdc++.h>
using namespace std ;

void solve()
{
    int n , q ; cin >> n >> q ; unordered_map<int, int> m ; int sum(0) ;
    for(int i =1; i<= n ; i++){
        int temp; cin >> temp ; sum += temp ;
        m[i] = sum ;
    }
    m[0] = 0 ;

    while(q--){
        int totalSum = sum ;
        int l, r, k ; cin >> l >> r >> k ;
        int newlyAdded = (r - l+ 1)* k ; int lrSum = m[r] - m[l-1] ; totalSum -= lrSum ;
        totalSum = totalSum + newlyAdded ;
        if(totalSum&1 ==1){cout << "YES" << endl ;}
        else{cout <<"NO" << endl ;}
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