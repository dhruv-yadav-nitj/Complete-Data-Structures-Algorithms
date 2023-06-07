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
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        map<int, vector<int>> m;
        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]].push_back(i);
        }
        for (auto &x : m)
        {
            if (x.second.size() > 1)
            {
                for (int i = 0; i < x.second.size() - 1; i++)
                {
                    if (abs(x.second[i] - x.second[i + 1]) <= k)
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

int main()
{
    IOS;

    return 0;
}