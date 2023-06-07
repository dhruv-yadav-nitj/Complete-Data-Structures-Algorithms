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

int calcGCD_METHOD1(int n, int m)
{
    for (int i = min(n, m); i >= 1; i--)
    {
        if (n % i == 0 and m % i == 0)
        {
            return i;
        }
    }
}

int EuclidAlgo(int n, int m)
{
    // If we subtract a smaller number from a larger one (we reduce a larger number), GCD doesn’t change. So if we keep subtracting repeatedly the larger of two, we end up with GCD.
    // Let a = m*k  and b = n*k where k is the GCD(a, b). then a-b = k*(m-n) from this we conclude that theres no change in GCD when we subtract two numbers.
    while (n != m)
    {
        if (n > m)
        {
            n -= m;
        }
        else
        {
            m -= n;
        }
    }
    return n;
}

int EuclidAlgo_Modified(int n, int m)
{
    // Now instead of subtraction, if we divide the smaller number, the algorithm stops when we find the remainder 0.
    if (m == 0)
    {
        return n;
    }
    return EuclidAlgo_Modified(m, n % m);
}

int main()
{
    IOS;
    // GCD means the Greatest Common Divisor or Highest Common Factor (HCF)
    // example: 5 and 13 have GDC as 1 , 4 and 16 have GCD as 4.

    // there are basically 3 method to find GCD : Bruteforce method , Euclid Algo and Improved Euclid Algo
    int n, m;
    cin >> n >> m;

    // method 1 : using iteration
    cout << calcGCD_METHOD1(n, m) << endl;

    // method 2: Euclid Algo
    cout << EuclidAlgo(n, m) << endl;

    // method 3: using Modified Euclid Algo and Recursion
    cout << EuclidAlgo_Modified(n, m) << endl;

    // BEST_METHOD
    // method 4: using BUILT-IN FUNCTION
    cout << __gcd(n, m) << endl;

    // and LCM can be found using the very basic property
    // (a*b) = gcd(a, b) * lcm(a*b)
    cout << "LCM: " << (n*m)/(__gcd(n, m)) << endl ;

    return 0;
}