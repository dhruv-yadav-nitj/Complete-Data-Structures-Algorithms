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
    string keyboard, word;
    cin >> keyboard >> word;
    if (word.length() == 1)
    {
        cout << 0 << endl;
    }
    else
    {
        vector<int> store;
        for (int i = 0; i < word.length(); i++)
        {
            int index = keyboard.find(word[i]);
            store.push_back(index);
        }
        int ans(0);
        for (int i = 1; i < store.size(); i++)
        {
            ans += abs(store[i] - store[i - 1]);
        }
        cout << ans << endl ;
    }
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