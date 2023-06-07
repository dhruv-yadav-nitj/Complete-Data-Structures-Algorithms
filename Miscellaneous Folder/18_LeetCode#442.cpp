
// Find all duplicate in Array
// https://leetcode.com/problems/find-all-duplicates-in-an-array/submissions/
// Limited TC : O(n)

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums)
    {
        vector <int> ans ;
        if (nums.empty())
        {
            return {} ;
        }
        sort (nums.begin() , nums.end()) ;
        int s = nums[0] ;
        for (int i = 1; i< nums.size() ; i++)
        {
            if (!(s^nums[i]))
            {
                ans.push_back(nums[i]);
                i++ ;
                if (i < nums.size())
                {
                    s = nums[i] ;
                }
            }
            else
            {
                s = nums[i] ;
            }
        }
        return ans ;
        
    }
};