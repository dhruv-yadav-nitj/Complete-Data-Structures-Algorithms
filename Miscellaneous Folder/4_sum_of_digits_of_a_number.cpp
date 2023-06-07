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

int find_sum(int n)
{
    if (n == 0)
    {
        return 0;
    }
    l ans = (n % 10) + find_sum(n / 10);
}

int main()
{
    IOS;
    int n;
    cin >> n;
    cout << find_sum(n) << endl;

    return 0;
}