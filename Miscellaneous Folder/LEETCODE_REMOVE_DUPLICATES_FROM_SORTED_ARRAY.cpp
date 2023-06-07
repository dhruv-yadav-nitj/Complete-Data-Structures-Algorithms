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
    int removeDuplicates(vector<int> &nums)
    {
        // using 2-pointer approach
        int i(1), j(1);
        while (i < nums.size())
        {
            if (nums[i] != nums[i - 1])
            {
                nums[j] = nums[i];
                j++;
            }
            i++;
        }
        return j;
    }
};

int main()
{
    IOS;
    return 0;
}