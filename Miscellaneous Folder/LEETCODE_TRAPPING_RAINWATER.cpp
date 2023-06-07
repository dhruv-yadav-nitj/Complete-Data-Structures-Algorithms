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
    int trap(vector<int> &height)
    {

        // Time Complexity: O(n)
        // can be more efficient using Stacks

        int water(0), maxiL(INT_MIN), maxiR(INT_MIN);
        vector<int> left, right;
        for (int i = 0; i < height.size(); i++)
        {
            left.push_back(max(maxiL, height[i]));
            maxiL = max(maxiL, height[i]);
        }
        for (int i = height.size() - 1; i >= 0; i--)
        {
            right.push_back(max(maxiR, height[i]));
            maxiR = max(maxiR, height[i]);
        }
        reverse(right.begin(), right.end());
        for (int i = 1; i < height.size() - 1; i++)
        {
            water += min(left[i], right[i]) - height[i];
        }
        return water;
    }
};