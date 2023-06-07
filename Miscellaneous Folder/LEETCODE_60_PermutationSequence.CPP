/*
 * @lc app=leetcode id=60 lang=cpp
 *
 * [60] Permutation Sequence
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    string getPermutation(int n, int k){
        // code here
        int factorial = 1 ;
        vector<int> nums ;  // vector to store the numbers from 1 to n
        for(int i= 1 ; i < n ; i++){
            factorial = factorial * i ; // since we have to find the factorial of (n-1) so i < n is used and n is pushed separately
            nums.push_back(i) ;
        }
        nums.push_back(n) ;

        string ans = "" ; k = k-1 ; // for 0-based indexing
        while(true){
            ans += to_string(nums[k / factorial]) ;
            nums.erase(nums.begin() + k / factorial)  ; // since ye used number waapis repeat nhi hona isilie usko erase hi krdena better hain

            if(nums.size() == 0){break ;} // obvious case hain ye to
            k = k % factorial ; // 
            factorial = factorial / nums.size() ; // when we had "123" then hr cheej 2 baar repeat ho rhi thi jaise 1 ko fix kr do phle spot pr to aise 2 combinations bante "123" and "132" --> usi tarah ab 1 ko erase kr die to bacha "23" then ab hr cheej ek hi baar repeat hogi "23" and "32" so aisa hua to factorial ko bhi to change krna hoga --> factorial phle 2 tha ab 1 krna hoga --> 2 / 2 --> factorial / nums.size() ;
        }
        return ans ;
    }
};
// @lc code=end
