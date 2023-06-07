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

// Take an integer input n and print all the prime numbers smaller than or equal to n.
// This is the most compressed and efficient way of SIEVE_OF_ERATOSTHENES

void sieve(int n)
{
    bool prime[n + 1];
    memset(prime, true, n + 1);
    // memset is used to initialize a block of memory with some predefined values.
    for (int i = 2; i <= n; i++)
    {
        if (prime[i])
        {
            cout << i << " ";
            for (int j = i * i; j <= n; j += i)
            {
                prime[j] = false;
            }
        }
    }
}

int main()
{
    IOS;
    int n;
    cin >> n;
    sieve(n);

    return 0;
}