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

int BrianKerningamsMethod(int n)
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
    int count(0);
    while (n > 0)
    {
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
    cout << BrianKerningamsMethod(n) << endl;

    return 0;
}