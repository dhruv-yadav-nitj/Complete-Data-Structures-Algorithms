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

// for 0 based starting point
int jos(int n, int k)
{
    if (n == 1)
    {
        return 0;
    }
    return (jos(n - 1, k) + k) % n;
}

// for 1 based starting point
int josephus(int n, int k)
{
    if (n == 1)
    {
        return 1;
    }
    return ((josephus(n - 1, k) + k - 1) % n + 1);
}

int main()
{
    IOS;
    int n, k;
    cin >> n >> k;
    cout << jos(n, k) << endl;
    cout << josephus(n, k) << endl;

    return 0;
}