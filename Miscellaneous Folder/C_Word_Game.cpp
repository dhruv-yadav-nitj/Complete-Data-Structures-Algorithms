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
        vector<string> v(n * 3);
        map<string, int> m;
        for (int i = 0; i < n * 3; i++)
        {
            cin >> v[i];
            m[v[i]]++;
        }
        int p1(0), p2(0), p3(0);
        for (int i = 0; i < n; i++)
        {
            if (m[v[i]] == 1)
            {
                p1 += 3;
            }
            else if (m[v[i]] == 2)
            {
                p1 += 1;
            }
            else
            {
                p1 = p1;
            }
        }

        for (int i = n; i < n * 2; i++)
        {
            if (m[v[i]] == 1)
            {
                p2 += 3;
            }
            else if (m[v[i]] == 2)
            {
                p2 += 1;
            }
            else
            {
                p2 = p2;
            }
        }

        for (int i = n * 2; i < n * 3; i++)
        {
            if (m[v[i]] == 1)
            {
                p3 += 3;
            }
            else if (m[v[i]] == 2)
            {
                p3 += 1;
            }
            else
            {
                p3 = p3;
            }
        }

        cout << p1 << " " << p2 << " " << p3 << endl;
    }

    return 0;
}