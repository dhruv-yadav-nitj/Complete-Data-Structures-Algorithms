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

int dothisforme(vi nums, int n, int target)
{
    int s = 0, e = n;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        // Case 1
        if (nums[mid] == target)
        {
            return mid;
        }
        // Case 2 : when left half is sorted
        if (nums[s] < nums[mid])
        {
            if (target >= nums[s] and target < nums[mid])
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        // Case 3: when right half is sorted
        else
        {
            if (target > nums[mid] and target <= nums[e])
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    IOS;
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int target;
    cin >> target;
    cout << dothisforme(nums, n, target) << endl;

    return 0;
}