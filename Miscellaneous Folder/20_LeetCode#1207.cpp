
// https://leetcode.com/problems/unique-number-of-occurrences/
// Unique Number of Occurrences

class Solution {
public:
    bool uniqueOccurrences(vector<int>&arr) {
        vector <int> ans;
        //counting number of occurences
        for (int i = 0; i < arr.size(); i++)
        {
            int x = arr[i] ;
            int count = 0;
            if(x != INT_MIN)
            {
                for (int j = 0; j<arr.size(); j++)
            {
                if(x == arr[j])
                {
                    count++ ;
                    arr[j] = INT_MIN ;
                }
            }
            if(count > 0)
            {
                ans.push_back (count) ;
            }
            }
        }
        
        //counting frequency
        for (int i = 0; i < ans.size() ; i++)
        {
            int count1 = 0;
            for (int j = 0 ; j < ans.size() ; j++)
            {
                if (ans[i]==ans[j])
                {
                    count1++ ;
                }
            }
            if(count1 > 1)
            {
                return false ;
            }
        }
        return true ;
    }
};