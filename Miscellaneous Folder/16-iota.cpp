#include <bits/stdc++.h>
#define l long long
#define vl vector<long long>
#define vi vector<int>
#define vp vector<vector<int>>
using namespace std;

int main()
{
    vi v(10);
    iota(v.begin(), v.begin() + 10, 100);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}