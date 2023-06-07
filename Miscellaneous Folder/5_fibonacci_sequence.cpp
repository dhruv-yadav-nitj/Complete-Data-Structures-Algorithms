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

// print nth fibonacci number and fibonacci sequence till n

int nth_fib(int n)
{
    if (n == 0 or n == 1)
    {
        return n;
    }
    else
    {
        return nth_fib(n - 1) + nth_fib(n - 2);
    }
}

int main()
{
    IOS;
    int n;
    cin >> n;
    cout << nth_fib(n) << endl;
    for (int i = 0; i <= n; i++)
    {
        cout << nth_fib(i) << " ";
    }
    cout << endl;

    return 0;
}