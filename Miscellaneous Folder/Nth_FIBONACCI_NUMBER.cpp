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

int fibonacci(int n)
{
    // base condition is the most important element in any recursive code
    if (n == 0 or n == 1)
    {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    IOS;
    int n;
    cin >> n;

    // method 1 : iterative approach
    int a(0), b(1), c;
    for (int i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    cout << "Using Iterative Approach: " << c << endl;

    // method 2 : recursive approach
    cout << "Using Recursive Approach: " << fibonacci(n) << endl;

    return 0;
}