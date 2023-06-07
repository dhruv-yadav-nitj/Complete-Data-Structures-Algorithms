#include <bits/stdc++.h>
using namespace std ;

// logic : koi bhi letter jo hain agar wo kisi even index pr lie kr rha to phir usko pure string mein even index pr hi lie krna chaie aur agar odd pr kr rha to phir usko odd pr hi krna chaie

void solve()
{
    int n ; cin >> n ; string s; cin >> s ;
    unordered_map<char, int> m ; // we would consider 1 for odd and 0 for even
    for(int i=0; i < s.length() ; i++){
        if(m.find(s[i]) == m.end()){
            m[s[i]] = i%2 ;
        }
        else{
            int temp ; if(i%2==0){temp = 0 ;} else{temp = 1 ;}
            if(temp != m[s[i]]){cout << "NO" << endl ; return ;}
        }
    }
    cout << "YES" << endl;
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