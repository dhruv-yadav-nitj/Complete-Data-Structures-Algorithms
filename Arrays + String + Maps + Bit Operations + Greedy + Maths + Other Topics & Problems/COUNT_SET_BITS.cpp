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

// builtin-functions for GCC Compiler
// https://www.geeksforgeeks.org/builtin-functions-gcc-compiler/

// method 2 : Brian-Kerningams-Method
int countSetBits(int n)
{
    int count(0);
    while (n > 0)
    {
        // what happens when we do (n & (n-1)):
        // let suppost n = 40
        /*
        40 = 101000
        n-1 = 39 = 100111
        (n & (n-1)) = 100000
        Note: when we do (n & (n-1)) then the right most set bit in n becomes 0.
        */

        // Time Complexity : O(count of set bits in N)
        n = (n & (n - 1));
        count++;
    }
    return count;
}

int main()
{
    IOS;
    int n;
    cin >> n;
    // SET BITS means the total number of 1's in the binary representation of a decimal number.
    // so we have other naive methods as well to do the same work but we would be using a builtin function provided in C++ to do this
    cout << __builtin_popcount(n) << endl;
    /* Similarly you can use __builtin_popcountl(x) & __builtin_popcountll(x) for long and long long data types. */

    cout << countSetBits(n) << endl;

    return 0;
}