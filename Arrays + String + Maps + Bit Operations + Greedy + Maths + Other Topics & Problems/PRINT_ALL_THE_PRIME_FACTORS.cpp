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

void printUsingSquareRootMethod(int n)
{
    bool flag = false;
    while (n % 2 == 0)
    {
        cout << 2 << " ";
        n /= 2;
        flag = true;
    }
    while (n % 3 == 0)
    {
        cout << 3 << " ";
        n /= 3;
        flag = true;
    }
    for (int i = 5; i <= n; i += 6)
    {
        while (n % i == 0)
        {
            cout << i << " ";
            n /= i;
            flag = true;
        }
        while (n % (i + 2) == 0)
        {
            cout << i + 2 << " ";
            n /= (i + 2);
            flag = true;
        }
    }
}

int main()
{
    IOS;
    int n;
    cin >> n;
    printUsingSquareRootMethod(n);

    return 0;
}