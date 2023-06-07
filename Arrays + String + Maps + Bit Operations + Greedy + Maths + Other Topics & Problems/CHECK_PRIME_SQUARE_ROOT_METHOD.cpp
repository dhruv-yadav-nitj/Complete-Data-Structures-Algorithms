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

// remember this method as the most basic method, because other method which are simpler than this are of no use
// other methods are SIEVE and MODIFIED SIEVE method

bool isPrime(int n)
{
    if (n % 2 == 0)
    {
        return false;
    }
    if (n % 3 == 0)
    {
        return false;
    }
    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 or n % (i + 2) == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    IOS;
    int n;
    cin >> n;
    if (isPrime(n))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}