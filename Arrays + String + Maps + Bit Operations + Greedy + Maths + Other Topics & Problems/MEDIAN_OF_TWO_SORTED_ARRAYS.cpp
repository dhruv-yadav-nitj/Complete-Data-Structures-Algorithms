
// This problem is a spin off of a problem in Binary Search, see the Binary Search 14 file
// This would be naive solution
// https://www.geeksforgeeks.org/median-of-two-sorted-arrays-of-different-sizes/
// https://leetcode.com/problems/median-of-two-sorted-arrays/
// Despite being out of Time Complexity, this solution got accepted on LeetCode
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
        vector<int> temp;
        for (int i = 0; i < nums1.size(); i++)
        {
            temp.push_back(nums1[i]);
        }
        for (int i = 0; i < nums2.size(); i++)
        {
            temp.push_back(nums2[i]);
        }
        sort(temp.begin(), temp.end());
        if (temp.size() & 1 == 1)
        {
            return temp[temp.size()/2.0];
        }
        else
        {
            return (temp[temp.size()/2]+temp[temp.size()/2-1])/2.0;
        }
    }
};

int main()
{
    IOS;

    return 0;
}