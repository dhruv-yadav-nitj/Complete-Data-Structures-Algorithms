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

class Solution
{
public:
    string makeGood(string s)
    {
        bool flag = true;
        while (flag and (s.length() > 0))
        {
            flag = false;
            for (int i = 1; i < s.length(); i++)
            {
                if (abs(s[i - 1] - s[i]) == 32)
                {
                    s.erase(i - 1, 2);
                    flag = true;
                    break;
                }
            }
        }
        return s;
    }
};