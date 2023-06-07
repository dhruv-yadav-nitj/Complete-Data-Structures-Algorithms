
// https://www.geeksforgeeks.org/multiplicative-inverse-under-modulo-m/

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

int main()
{
    IOS;
    int a, m;
    cin >> a >> m;

    // a number x would be called modular multiplicative inverse of a under m iff (a*x) % m == 1 also the range of x should be [1, m).
    /* The multiplicative inverse of “a modulo m” exists if and only if a and m are relatively prime (i.e., if gcd(a, m) = 1). */

    // method 1 : BRUTEFORCE METHOD
    // since inverse may also not exist
    bool flag = false;
    for (int i = 1; i < m; i++)
    {
        if ((a * i) % m == 1)
        {
            cout << i << endl;
            break;
        }
    }

    // method 2 : Using Euclid's Algo
    // Go to the link and study completely

    return 0;
}