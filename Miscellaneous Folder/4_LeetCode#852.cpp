
// https://leetcode.com/problems/peak-index-in-a-mountain-array/submissions/
// lecture#13 - Luv Babbar

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        
        int s = 0 , e = arr.size()-1 ;
        while (s < e)  // not used s <= e bcz we have to return the s when s = e ;
        {
            int mid = s + (e-s)/2 ;
            if (arr[mid]<arr[mid+1])
            {
                s = mid+1 ;
            }
            else
            {
                e = mid ; // e= mid and not e= mid-1 bcz if we used the first case then are not going to get the ans any how.
            }
        }
        return s ;
        
    }
};