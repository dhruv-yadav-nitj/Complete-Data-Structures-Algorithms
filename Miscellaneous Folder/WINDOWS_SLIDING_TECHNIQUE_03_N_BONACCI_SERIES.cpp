// N-Bonacii Number
// Remember Fibonacci Number in which a number was the sum of the last two numbers. So, Fibonacci Series can be called as a Two-Bonacci Series, there are Tri-Bonacci Series and there are also N-Bonbacci Series. In N-Bonacci Series a number is sum of last N numbers.
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

void nBonacciSeries(int n, int m)
{
    // in fibonacci series first element is 0. in n-bonacci series, first (n-1) elements would be 0 and then 1. like in N-Bonacci Series for N=4: 0 0 0 1 1 2 4 8 15 ....
    vector<int> v;
    for (int i = 0; i < n - 1; i++)
    {
        v.push_back(0);
    }
    v.push_back(1);
    int sum(1);
    for (int i = n; i <= m; i++)
    {
        v.push_back(sum);
        sum += v[i];
        sum -= v[i - n];
    }
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}

int main()
{
    IOS;
    int n, m;
    cin >> n >> m;
    // where n is the N in N-Bonacci Series and m is the F(m) means till where we have to output the N-Bonacci Series.
    nBonacciSeries(n, m);

    return 0;
}