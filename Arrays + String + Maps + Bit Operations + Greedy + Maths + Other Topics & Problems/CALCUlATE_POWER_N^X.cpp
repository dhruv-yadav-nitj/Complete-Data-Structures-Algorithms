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

// method 1: recursion
long long calcPower(int n, int x)
{
    if (x == 0)
    {
        return 1;
    }
    long long temp = calcPower(n, x / 2);
    temp = temp * temp;
    if (x % 2 == 0)
    {
        return temp;
    }
    return temp * n;
}

// method 2: using iteration
long long calPower(int n, int x)
{
    long long ans(1);
    while (x > 0)
    {
        // if n is an odd number then (n&1)==1
        // n >> x = n/pow(2, x) ; Right Shift
        // n << x = n * pow(2, x) ; Left Shift
        if ((x & 1))
        {
            ans = ans * n;
        }
        n = n * n;
        x = x >> 1;
    }
    return ans;
}

int main()
{
    IOS;
    int n, x;
    cin >> n >> x;
    cout << "Using Recursion: " << calcPower(n, x) << endl;
    cout << "Using Iteration: " << calPower(n, x) << endl;

    // method 3 : using built-in function
    cout << "Using Built-in Function: " << pow(n, x) << endl;

    return 0;
}