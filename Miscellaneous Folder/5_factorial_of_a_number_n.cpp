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

l find_fac(int n)
{
    if (n == 0 or n == 1)
    {
        return 1;
    }
    l ans = n * find_fac(--n);
    return ans;
}

int main()
{
    IOS;
    int n;
    cin >> n;
    cout << find_fac(n) << endl;

    return 0;
}