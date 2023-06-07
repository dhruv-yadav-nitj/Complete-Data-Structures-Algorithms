#include <bits/stdc++.h>
#define l long long
#define vl vector<long long>
#define vi vector<int>
#define vp vector<vector<int>>
using namespace std;

int findGCD(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    else
    {
        findGCD(b % a, a);
    }
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << findGCD(a, b) << endl;

    return 0;
}