#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        unordered_map<int, int> m;
        vector<int> ans;
        for (auto &&i : nums)
        {
            m[i]++;
        }
        for (auto &&i : m)
        {
            if (i.second == 1)
            {
                ans.push_back(i.first);
                if (ans.size() == 2)
                {
                    return ans;
                }
            }
        }
        return ans;
    }
};