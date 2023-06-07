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
    string removeDuplicates(string s)
    {
        int i(0);
        while (i < s.length() - 1)
        {
            if (s[i] == s[i + 1])
            {
                s.erase(i, 2);
                if (i > 0)
                {
                    i--;
                }
            }
            else
            {
                i++;
            }
        }
        return s;
    }
};