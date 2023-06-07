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

long long factorial(int n)
{
    // base condition would be this since we know the value of 0! and 1! which is 1
    if (n == 0 or n == 1)
    {
        return 1;
    }
    return n * factorial(--n);
}

int main()
{
    IOS;
    int n;
    cin >> n;
    // factorial(n) = n! = 1*2*3......*n
    // method 1
    int temp(1);
    for (int i = 1; i <= n; i++)
    {
        temp *= i;
        // same as temp = temp * i ;
    }
    cout << "Using Iteration: " << temp << endl;

    // method 2
    cout << "Using Recursion: " << factorial(n) << endl;

    return 0;
}