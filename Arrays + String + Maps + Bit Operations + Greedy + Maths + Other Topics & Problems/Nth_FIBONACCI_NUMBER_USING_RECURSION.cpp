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

int fib(int n)
{
    if (n == 0 or n == 1)
    {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

int main()
{
    IOS;
    int n;
    cin >> n;
    // assume fib(0) = 0, fib(1) = 1 and so on.
    cout << fib(n) << endl;

    return 0;
}