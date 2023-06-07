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
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(intervals.begin(), intervals.end());
        int maxi(INT_MIN);
        temp.push_back(intervals[0][0]);
        maxi = max(maxi, intervals[0][1]);
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] > maxi)
            {
                temp.push_back(maxi);
                ans.push_back(temp);
                temp.clear();
                temp.push_back(intervals[i][0]);
                maxi = intervals[i][1];
            }
            else
            {
                maxi = max(maxi, intervals[i][1]);
            }
        }
        temp.push_back(maxi);
        ans.push_back(temp);
        return ans;
    }
};