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
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> s;
        vector<int> ans;
        for (auto x : nums1)
        {
            s.insert(x);
        }
        for (auto x : nums2)
        {
            if (s.count(x))
            {
                ans.push_back(x);
                s.erase(s.find(x));
            }
        }
        return ans;
    }
};