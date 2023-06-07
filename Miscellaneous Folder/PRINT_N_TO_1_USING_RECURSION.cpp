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

void printNto1(int n)
{
    // time complexity : O(n)
    // aux space : O(n)
    if (n == 0)
    {
        return;
    }
    cout << n << " ";
    printNto1(--n);
}

int main()
{
    IOS;
    int n;
    cin >> n;
    printNto1(n);

    return 0;
}