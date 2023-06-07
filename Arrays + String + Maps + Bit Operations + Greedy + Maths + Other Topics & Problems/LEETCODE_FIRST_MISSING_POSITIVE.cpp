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
    int firstMissingPositive(vector<int> &nums)
    {
        // Solution 1
        /* unordered_map<int, int> m;
        for (auto &&x : nums)
        {
            if (x > 0)
            {
                m[x] = 1;
            }
        }
        for (int i = 1; i <= m.size(); i++)
        {
            if (m[i] == 0)
                return i;
        }
        return m.size() + 1; */

        // Solution 2
        /*
        Put each number in its right place.

For example:

When we find 5, then swap it with A[4].

At last, the first place where its number is not right, return the place + 1.
        */
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            // while mein i++ nhi lga because hme kisi bhi i pr tb tk bane rhna hain jb tk wha aane waale elements apne original jagah pr rkhte jaa rhe hain
            // take the test case [-1, 4, 2, 1, 9, 10] to understand the code
            // it would be sorted as [1, 2, -1, 4, 9, 10]
            while (nums[i] > 0 and nums[i] < n and (nums[nums[i] - 1] != nums[i]))
            {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != i + 1)
            {
                return i + 1;
            }
        }
        return n + 1;
    }
};