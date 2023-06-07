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

bool isPrime(int n)
{
    // sieve
    bool prime[n + 1];
    memset(prime, true, n + 1);
    for (int i = 2; i * i <= n; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                prime[j] = false;
            }
        }
    }
    if (prime[n])
    {
        return true;
    }
    return false;
}

bool isT_Prime(int n)
{
    // first let us check whether its a perfect square or not
    if (ceil(double(sqrt(n))) == floor(double(sqrt(n))))
    {
        int temp = sqrt(n);
        if (isPrime(temp))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

int main()
{
    IOS;
    int n;
    cin >> n;
    // a number is called T-Prime when it has exactly 3 divisors.
    // According to logic, a number can be T-Prime iff it is a perfect square and its square root is a prime number
    // example: 4, 9, 49
    if (isT_Prime(n))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}