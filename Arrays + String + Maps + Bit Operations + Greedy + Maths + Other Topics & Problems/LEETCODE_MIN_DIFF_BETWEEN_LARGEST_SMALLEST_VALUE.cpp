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
    // this question does not apply any dsa concepts its purely based on logic thinking.
    int minDifference(vector<int> &nums)
    {
        // clearly ek to case hain ki nums.size() <= 4 then hm sbko change kr skte hain
        int n = nums.size();
        if (n <= 4)
        {
            return 0;
        }

        // second case hain jb size 4 se jyada hain
        // is case mein phle to sort kr dete hain
        // dekho hme pata hain ki hmare paas exactly 3 moves (since n > 4) then we would apply all the 3 moves here. Now just make combinations
        // either we can change the last 3 numbers from last (largest 3 numbers) or we can change the first 3 numbers (smallest 3 numbers) or we can change first 2 numbers and last 1 number or we can change last 2 number and first 1 number
        sort(nums.begin(), nums.end());
        return min({(nums[n - 4] - nums[0]), (nums[n - 1] - nums[3]), (nums[n - 3] - nums[1]), (nums[n - 2] - nums[2])});
    }
};