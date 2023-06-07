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
    bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
    {
        string temp1 = "", temp2 = "";
        for (auto x : word1)
        {
            temp1 += x;
        }
        for (auto x : word2)
        {
            temp2 += x;
        }
        if (temp1 == temp2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};