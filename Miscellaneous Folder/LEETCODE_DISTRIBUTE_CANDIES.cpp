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
    int distributeCandies(vector<int> &candyType)
    {
        unordered_set<int> s;
        for (auto &&i : candyType)
        {
            s.insert(i);
        }
        if (s.size() <= candyType.size() / 2)
        {
            return s.size();
        }
        else
        {
            return candyType.size() / 2;
        }
    }
};