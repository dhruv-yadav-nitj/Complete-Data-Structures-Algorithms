#include <bits/stdc++.h>
#define l long long
#define vl vector<long long>
#define vi vector<int>
#define v2 vector<vector<int>>
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
using namespace std;

void solve()
{
    string s;
    cin >> s;
    char temp = '9';
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] <= temp)
        {
            temp = s[i];
        }
        else
        {
            s[i] = min((char)(s[i]+1), '9') ;
        }
    }
    sort(s.begin(), s.end()) ;
    cout << s << endl ;
}

int main()
{
    IOS;
    l t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}