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

int main()
{
    IOS;
    int n, m;
    cin >> n >> m;
    map<string, string> mp;
    while (m--)
    {
        string a, b;
        cin >> a >> b;
        mp[a] = b;
    }
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        if (temp.length() <= mp[temp].length())
        {
            cout << temp << " ";
        }
        else
        {
            cout << mp[temp] << " ";
        }
    }cout << endl;

    return 0;
}