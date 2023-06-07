#include <bits/stdc++.h>
using namespace std ;

void solve()
{
    int l , r; cin >> l >> r ;
    if(l == r){
        cout << l << endl ; return ;
    }

    int ans = l , diff = INT_MIN ;
    for(int i = l ; i <= r; i++){

        // this implementation is great
        string s = to_string(i) ; int low = 10 , high = 0 ; // ab 10 se divide kr kr to dekhoge nhi --> do something smart
        for(int j = 0 ; j  < s.length() ; j++){
            low = min(low , s[j] - '0') ; high = max(high , s[j] - '0') ;
            if(high -low == 9){cout << i << endl ; return ;}
        }
        if(high - low > diff){diff = high -low ; ans = i ;}
    }
    cout << ans << endl ;
    
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