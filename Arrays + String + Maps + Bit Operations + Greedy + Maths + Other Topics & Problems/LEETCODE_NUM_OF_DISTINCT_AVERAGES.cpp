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
    int distinctAverages(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size() - 1;
        unordered_set<float> s;
        while (i < j)
        {
            float avg;
            avg = (nums[j] + nums[i]) / (2.0);
            s.insert(avg);
            i++, j--;
        }
        return s.size();
    }
};