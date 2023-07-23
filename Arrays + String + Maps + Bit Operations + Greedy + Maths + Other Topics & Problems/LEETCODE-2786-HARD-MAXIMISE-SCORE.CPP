#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/contest/biweekly-contest-109/problems/visit-array-positions-to-maximize-score/
// https://youtu.be/pvz4qKwBySc

// GREEDY SOLUTION
// DP SOLUTION ALSO EXIST (BUT I WAS STUCK THERE)

class Solution
{
public:
    long long maxScore(vector<int> &nums, int x) {
        // CODE HERE

        long long oddEnd = 0 , evenEnd= 0 , n = nums.size(), ans=0 ;

        // intialise the values according to the first element
        if(nums[0]%2==0) {
            evenEnd = nums[0] ;
            oddEnd = nums[0] - x ;
        }
        else{
            oddEnd = nums[0] ;
            evenEnd = nums[0] -x ;
        }

        // traversing from 1st index to last index and taking the max at each step (at each step bcz our aim is not to reach the last index but to take the max of all possible ans)
        for(int i =1 ;i < n ; i++) {
            if(nums[i] %2 ==0) {
                // means current elemenet is even
                evenEnd = max(evenEnd+nums[i] , oddEnd + nums[i]-x) ;
            }
            else{
                // means current element is odd
                oddEnd = max(oddEnd + nums[i], evenEnd + nums[i] - x) ;
            }
            ans = max(evenEnd, oddEnd);
        }

        return ans ;

    }
};