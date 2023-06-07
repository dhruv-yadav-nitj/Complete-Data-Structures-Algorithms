
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

// Note: We are given a rope of length n and we are given 3 different lengths a, b and c. We have to return the maximum number of pieces which can be cut out of the rope of these 3 different pieces.

// recursive approach
// time complexity : Since we are making 3 function calls for each step so O(pow(3, n))
// this problem has bettet solution with DP, that will be discussed later

int maxmCutP(int n, int a, int b, int c)
{
    if (n == 0)
    {
        return 0;
    }
    if (n < 0)
    {
        return -1;
    }
    int ans = max({maxmCutP(n - a, a, b, c), maxmCutP(n - b, a, b, c), maxmCutP(n - c, a, b, c)});

    if (ans == -1)
    {
        return -1;
    }
    return ans + 1;
}

int main()
{
    IOS;
    int n;
    cin >> n;
    int a, b, c;
    cin >> a >> b >> c;

    cout << maxmCutP(n, a, b, c) << endl;

    return 0;
}