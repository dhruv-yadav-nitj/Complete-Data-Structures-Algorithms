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

int factos(int n)
{
    if (n == 0 or n == 1)
    {
        return 1;
    }
    return n * factos(n - 1);
}

int main()
{
    IOS;
    int n;
    cin >> n;
    cout << factos(n) << endl;

    return 0;
}