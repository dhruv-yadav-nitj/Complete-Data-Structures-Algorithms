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
    int n, m;
    cin >> n >> m;
    // since we know how to calculate GCD or HCF of n and m and also we have a relation
    // a * b = HCF(a, b) * GCD(a, b)
    cout << n * m / (__gcd(n, m)) << endl;

    return 0;
}