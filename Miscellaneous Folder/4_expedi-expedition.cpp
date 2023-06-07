#include <bits/stdc++.h>
#define l long long
#define vl vector<long long>
#define vi vector<int>
#define vp vector<vector<int>>
using namespace std;

bool custom (vi &a, vi &b)
{
    return a[0] > b[0] ;
}

int main()
{
    l t;
    cin >> t;
    while (t--)
    {
        l n;
        cin >> n;
        vector<vector<l>> v;
        for (l i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            v.push_back({a, b});
        }
        sort(v.begin(), v.end(), custom) ;
        l L, P;
        cin >> L >> P;

        int sum = P;
        for (l i = 0; i < n; i++)
        {
            sum += v[i][1] ;
        }
        if (sum < L)
        {
            cout << -1 << endl ;
            return 0 ;
        }
        
        // rest will try after studying Heap as it is needed in this question.
    }

    return 0;
}