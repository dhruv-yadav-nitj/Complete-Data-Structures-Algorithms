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
    int maxArea(vector<int> &height)
    {
        // method 1: Naive Solution --> TLE --> O(n^2)
        /* int ans(0), curr(0);
        for (int i = 0; i < height.size() - 1; i++)
        {
            for (int j = i + 1; j < height.size(); j++)
            {
                ans = max(ans, (j - i) * (min(height[i], height[j])));
            }
        }
        return ans; */

        // https://leetcode.com/problems/container-with-most-water/submissions/831922728/
        // method 2: Efficient Solution O(n)
        int i(0), j(height.size() - 1);
        int ans(INT_MIN);
        while (i < j)
        {
            int h = min(height[i], height[j]);
            ans = max(ans, (j - i) * h);
            while (height[i] <= h and i < j)
            {
                i++;
            }
            while (height[j] <= h and i < j)
            {
                j--;
            }
        }
        return ans;
    }
};
