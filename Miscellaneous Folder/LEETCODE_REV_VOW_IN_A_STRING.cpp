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
    string reverseVowels(string s)
    {
        int i(0), j(s.length() - 1);
        while (i < j)
        {
            while (s[i] != 'a' and s[i] != 'e' and s[i] != 'i' and s[i] != 'o' and s[i] != 'u' and s[i] != 'A' and s[i] != 'E' and s[i] != 'I' and s[i] != 'O' and s[i] != 'U' and i < j)
            {
                i++;
            }
            while (s[j] != 'a' and s[j] != 'e' and s[j] != 'i' and s[j] != 'o' and s[j] != 'u' and s[j] != 'A' and s[j] != 'E' and s[j] != 'I' and s[j] != 'O' and s[j] != 'U' and i < j)
            {
                j--;
            }
            swap(s[i], s[j]);
            i++, j--;
        }
        return s;
    }
};