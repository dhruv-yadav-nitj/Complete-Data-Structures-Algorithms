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
    string actual = "", pm = "";
    for (int i = 0; i < n; i++)
    {
        if (s[i] != '+' and s[i] != '-')
        {
            actual += s[i];
        }
        else
        {
            pm += s[i];
        }
    }
    sort(actual.begin(), actual.end(), greater<char>());
    // cout << actual << endl ;
    // sort(plusminus.begin(), plusminus.end()) ;
    // cout << plusminus << endl ;
    string ans = "";
    int j(0);
    for (int i = 0; i < actual.length() - pm.length(); i++)
    {
        ans += actual[i];
        j = i + 1;
    }
    int countplus(0), countmin(0);
    for (int i = 0; i < pm.length(); i++)
    {
        if (pm[i] == '+')
        {
            countplus++;
        }
        else
        {
            countmin++;
        }
    }
    // cout << actual << endl ;
    for (int i = 0; i < countplus; i++, j++)
    {
        ans += '+';
        ans += actual[j];
    }
    for (int i = 0; i < countmin; i++, j++)
    {
        ans += '-';
        ans += actual[j];
    }
    cout << ans << endl;
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