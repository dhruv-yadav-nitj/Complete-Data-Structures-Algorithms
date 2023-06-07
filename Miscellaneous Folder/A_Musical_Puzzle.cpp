#include <bits/stdc++.h>
using namespace std ;

void solve()
{
    int n ; cin >> n ; 
    string s ; cin >> s ;

    unordered_set<string> ans ;

    while(s.length() > 2){

        string temp = "" ; temp += s[s.length() - 2] ; temp += s[s.length() - 1] ; s.pop_back() ; ans.insert(temp) ;

    }

    string temp = "" ; temp += s ; ans.insert(temp) ;
    cout << ans.size() << endl ;

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