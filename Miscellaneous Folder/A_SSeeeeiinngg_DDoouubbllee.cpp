#include <bits/stdc++.h>
#define l long long
#define vl vector<long long> 
#define vi vector<int> 
#define v2 vector<vector<int>> 
#define loop(i, low, high) for(int i= low; i < high;i++) 
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

void solve()
{
    string s ; cin >> s ;
    string ans= "";
    ans += s ; reverse(s.begin(), s.end()) ; ans += s;
cout << ans << endl;;
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