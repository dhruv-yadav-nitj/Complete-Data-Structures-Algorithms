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
    int a[] = {10, 14, 13, 12, 12, 12, 1, 0};
    int b[] = {24, 231, 123, 42, 12, 1, 0};

    // using unordered_set
    unordered_set<int> s;
    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
    {
        s.insert(a[i]);
    }
    for (int i = 0; i < sizeof(b) / sizeof(b[0]); i++)
    {
        s.insert(b[i]);
    }
    for (auto x : s)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}