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
    vector<vector<int>> threeSum(vector<int> &nums)
    {

        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]] = i;
        }
        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (m.find(-(nums[i] + nums[j])) != m.end() and j < m[-(nums[i] + nums[j])])
                {
                    ans.push_back(vector<int>{nums[i], nums[j], nums[m[0 - (nums[i] + nums[j])]]});
                }
                // gets to the last index when that element occured, since the vector may contain duplicate elements
                j = m[nums[j]];
            }
            // gets to the last index when that element occured, since the vector may contain duplicate elements
            i = m[nums[i]];
        }
        return ans;
    }
};

int main()
{
    IOS;

    return 0;
}