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
    int n;
    cin >> n;

    // method 1 : if the number of set bits in the binary representation of a number is 1 then its a power of 2
    if (__builtin_popcount(n) == 1)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    // method 2 : check log values
    // time complexity : O(1)
    if (ceil(log2(n)) == floor(log2(n)))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}