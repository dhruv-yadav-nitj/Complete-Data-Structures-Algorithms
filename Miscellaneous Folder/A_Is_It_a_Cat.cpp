#include <bits/stdc++.h>
using namespace std ;

void solve()
{
    int n ; cin >> n ; string s; cin >> s ;
    if(s.length() == 0){cout << "NO" << endl; return ;}

    // convert all the characters of the input string to lower case letters
    transform(s.begin(), s.end() , s.begin() , ::tolower) ;

    string temp = "" ; temp += s[0] ; int i =1 ;
    while(i < n){
        while(i < n and s[i] == s[i-1]){
            i++ ;
        }
        if(i < n){temp += s[i++] ;}
    }

    if(temp == "meow"){cout << "YES" << endl ;}
    else{cout << "NO" << endl ;}
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