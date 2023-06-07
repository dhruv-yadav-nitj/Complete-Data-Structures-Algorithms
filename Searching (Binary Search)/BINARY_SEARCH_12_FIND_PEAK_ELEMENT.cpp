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

int findPeak(vi nums, int n)
{
    int low(0), high(n);
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if ((nums[mid - 1] <= nums[mid] and nums[mid + 1] <= nums[mid]) or (mid == 0 and nums[mid + 1] <= nums[mid]) or (mid == n - 1 and nums[mid - 1] <= nums[mid]))
        {
            return mid;
        }
        else
        {
            // if the left indexed element is greater than the current element then the peak element lies in the left half else the peak element lies in the right half
            if (mid > 0 and nums[mid - 1] > nums[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
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
    cout << "Peak Element: " << nums[findPeak(nums, n)] << endl;

    return 0;
}