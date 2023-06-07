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

// Solution 1: Beats 6% in Speed
/* class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        int temp(0), duplicater(0);
        set<int> s;
        for (int i = 0, j = 1; i < nums.size(), j <= nums.size(); i++, j++)
        {
            s.insert(nums[i]);
            duplicater ^= nums[i];
            temp ^= nums[i];
            temp ^= j;
        }
        int temp2(0);
        for (auto x : s)
        {
            temp2 ^= x;
        }
        temp2 = temp2 ^ duplicater;
        vector<int> ans;
        ans.push_back(temp2);
        ans.push_back(temp2^temp);
        return ans;
    }
}; */

// Solution 2:
class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        map<int, int> m;
        vector<int> ans;
        for (auto x : nums)
        {
            m[x]++;
            if (m[x] > 1)
            {
                ans.push_back(x);
            }
        }
        for (int i = 1; i <= nums.size(); i++)
        {
            if (m[i] == 0)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};