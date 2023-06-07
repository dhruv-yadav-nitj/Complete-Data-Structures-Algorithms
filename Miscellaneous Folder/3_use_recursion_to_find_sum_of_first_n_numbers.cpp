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

l find_sum(int n)
{
    if (n == 0)
    {
        return 0;
    }
    l ans = n + find_sum(n - 1);
    return ans;
}

int main()
{
    IOS;
    int n;
    cin >> n;
    cout << find_sum(n) << endl;

    return 0;
}