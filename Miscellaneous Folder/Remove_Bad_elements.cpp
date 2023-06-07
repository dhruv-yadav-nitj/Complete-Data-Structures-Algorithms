#include <bits/stdc++.h>
#define l long long
#define vl vector<long long> 
#define vi vector<int> 
#define v2 vector<vector<int>> 
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

void solve()
{
    int n ; cin >> n;
    map<int, int> m ;
    int temp(0) ;
    for (int i = 0; i < n; i++)
    {
        int a; cin>> a ;
        m[a]++ ;
        temp = max(temp, m[a]) ;
    }
    cout << n-temp << endl ;
    
}

int main()
{
    IOS;
    l t ; cin >> t ;
    while (t--)
    {
        solve() ;
    }
    return 0;
}