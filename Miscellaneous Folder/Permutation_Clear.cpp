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
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi v, vv;
        map<int, int> m;
        for (int i = 0; i < n; ++i)
        {
            int a;
            cin >> a;
            v.push_back(a);
            m[v[i]]++;
        }
        int k;
        cin >> k;
        for (int i = 0; i < k; i++)
        {
            int b;
            cin >> b;
            vv.push_back(b);
            m[vv[i]]++;
        }
        for (int i = 0; i < n; i++)
        {
            if (m[v[i]] == 1)
            {
                cout << v[i] << " ";
            }
        }

        cout << endl;
    }

    return 0;
}