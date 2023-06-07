#include <bits/stdc++.h>
using namespace std ;

void solve()
{

    // phle to dimaag mein aaega ki set use kr liaa jaae but think of this test case: 2 2 2 2 3 3 --> isme set waale method se ans aaega 1 but ans hona chaie 2 --> so we would use map --> basically saare elements ka frequency store kra lo --> sbse jyada jis element ka frequency hain usko change nhi krenge baaki sbko change krenge --> so n - max frequency

    int n ; cin >> n ; unordered_map<int, int> m ;
    int ans = 0 ;
    for(int i =0 ; i < n ; i++){
        int temp ; cin >> temp ; m[temp]++ ;
        ans = max(ans, m[temp]) ;
    }

    cout << n - ans << endl ;
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