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
    int n;
    cin >> n;
    string s;
    cin >> s;
    string temp = "";
    for (int i = 0; i < s.length() / 2; i++)
    {
        temp += s[i];
    }
    string temp2 = "";
    for (int i = s.length() / 2; i < s.length(); i++)
    {
        temp2 += s[i];
    }
    if (temp == temp2)
    {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
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