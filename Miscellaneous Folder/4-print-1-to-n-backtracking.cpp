#include <bits/stdc++.h>
#define l long long
#define vl vector<long long>
#define vi vector<int>
#define vp vector<vector<int>>
using namespace std;

void print(int i, int n)
{
    if (i < 1)
    {
        return;
    }
    print(i - 1, n);
    cout << i << " ";
}

int main()
{
    int n;
    cin >> n;
    print(n, n);

    return 0;
}