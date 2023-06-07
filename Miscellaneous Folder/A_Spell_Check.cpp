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
    int n;
    cin >> n;
    while (n--)
    {
        int s;
        cin >> s;
        string name;
        cin >> name;
        if (s == 5)
        {
            map<char, int> m;
            for (int i = 0; i < 5; i++)
            {
                m[name[i]]++;
            }
            if (m['T'] == 1 and m['i'] == 1 and m['m'] == 1 and m['u'] == 1 and m['r'] == 1)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}