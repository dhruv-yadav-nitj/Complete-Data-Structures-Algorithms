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

int doSolve(int n)
{
    if (n / 10 == 0)
    {
        return n%10;
    }
    return (n % 10) + doSolve(n / 10);
}

// time complexity : O(no. of digits)

int main()
{
    IOS;
    int n;
    cin >> n;
    cout << doSolve(n) << endl;

    return 0;
}