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
    string s;
    cin >> s;
    map<char, int> m;
    int count(0);
    for (int i = 0; i < s.length(); i++)
    {
        m[s[i]]++;
        if (m[s[i]] % 2 == 0)
        {
            count++;
        }
    }
    int countSingle(0);
    countSingle = s.length()-count;
    if (count == 1)
    {
        cout << 1 << endl;
    }
    else
    {
        int len1(0), len2(0);
        if ((count & 1) == 1)
        {
            int pair1 = count / 2;
            int pair2 = count / 2 + 1;
            if (countSingle > 0)
            {
                len1 = pair1 * 2 + 1;
                countSingle--;
            }
            else
            {
                len1 = pair1 * 2;
            }

            if (countSingle > 0)
            {
                len2 = pair2 * 2 + 1;
            }
            else
            {
                len2 = pair2 * 2;
            }
        }
        else
        {
            int pair1 = count / 2;
            int pair2 = count / 2;
            if (countSingle > 0)
            {
                len1 = pair1 * 2 + 1;
                countSingle--;
            }
            else
            {
                len1 = pair1 * 2;
            }

            if (countSingle > 0)
            {
                len2 = pair2 * 2 + 1;
            }
            else
            {
                len2 = pair2 * 2;
            }
        }
        cout << len1 * len2 << endl;
    }

    return 0;
}