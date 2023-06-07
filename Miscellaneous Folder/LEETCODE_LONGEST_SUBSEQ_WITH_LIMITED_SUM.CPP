#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries){
        sort(nums.begin(), nums.end()) ; vector<int> ans ;
        for(int i=0; i< queries.size(); i++){
            int count(0); int sum(0); int j(0);
            while(j < nums.size() and sum < queries[i]){
                sum += nums[j] ; j++ ; count++ ;
            }
            if(sum <= queries[i]){ans.push_back(count) ;}
            else{
                ans.push_back(count -1 ) ;
            }
        }
        return ans ;
    }
};