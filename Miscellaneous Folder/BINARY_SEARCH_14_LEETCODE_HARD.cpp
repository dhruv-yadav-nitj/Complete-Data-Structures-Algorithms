// Median of Two Sorted Arrays
// https://leetcode.com/problems/median-of-two-sorted-arrays/description/
// https://leetcode.com/problems/median-of-two-sorted-arrays/submissions/814038629/
// For Naive Solution open the file MEDIAN_OF_TWO_SORTED_ARRAYS
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
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1.size() > nums2.size())
        {
            return findMedianSortedArrays(nums2, nums1);
        }
        int n1 = nums1.size(), n2 = nums2.size();
        int low(0), high(n1);
        while (low <= high)
        {
            int cut1 = (low + high) / 2; // consider it as mid
            // total elements in the left half would be (n1 + n2 + 1)/2 ;
            // 1 is added to counter the case of odd and evens total number of elements
            int cut2 = (n1 + n2 + 1) / 2 - cut1;
            int left1 = (cut1 == 0) ? (INT_MIN) : (nums1[cut1 - 1]);
            int left2 = (cut2 == 0) ? (INT_MIN) : (nums2[cut2 - 1]);

            int right1 = (cut1 == n1) ? (INT_MAX) : (nums1[cut1]);
            int right2 = (cut2 == n2) ? (INT_MAX) : (nums2[cut2]);

            if (left1 <= right2 and left2 <= right1)
            {
                if (((n1 + n2) & 1) == 1)
                {
                    return max(left1, left2);
                }
                else
                {
                    return (max(left1, left2) + min(right1, right2)) / 2.0;
                }
            }
            else if (left1 > right2)
            {
                high = cut1 - 1;
            }
            else
            {
                low = cut1 + 1;
            }
        }
        return 0.0;
    }
};

int main()
{
    IOS;

    return 0;
}