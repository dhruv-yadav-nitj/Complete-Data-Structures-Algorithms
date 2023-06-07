#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        unordered_map<int, int> m;
        int ans(0);
        for (auto &&i : nums)
        {
            m[i]++;
        }
        for (auto &&i : m)
        {
            if (i.second == 1)
            {
                ans = i.first;
                return ans;
            }
        }
        return -1;
    }
};