/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

// Dhruv' Solution

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h){
        int temp ;
        if(piles.size() == 1){temp =  ceil((float)piles[0] / 2) ;}
        int low=1, high = *max_element(piles.begin(), piles.end());
        while(low < high){
            int mid = low + (high-low)/2 ;
            int count(0) ;
            for(auto &&i: piles){
                count += (i + mid -1)/mid ;
            }
            if(count > h){low = mid+1 ;}
            else{
                high = mid ;
            }
        }
        if(piles.size()==1){return min(temp, low) ;}
        return low ;
    }
};

/* I understood the logic behind the ques and solved it on my own.. but i was stucked at TC 119 / 122 but then I accidently replaced 'h' with '2' in line 17 then solution was accepted I dont know why, I suppose there were such limited test cases --> thats why i took help of ChatGPT --> the logic written by chatGPT at the end of solution is correct and I used the same on my own. So better understand the logic. */

// Chat GPT's Solution

class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        // sort the piles in descending order
        sort(piles.rbegin(), piles.rend());

        int low = 1, high = piles[0];
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            int hours = 0;
            for (int pile : piles)
            {
                hours += (pile + mid - 1) / mid;
            }
            if (hours > h)
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
        return low;
    }
};
// @lc code=end


/* Approach written by ChatGPT: */
/* 
This solution uses a binary search approach to find the minimum value of k that allows Koko to eat all the bananas within h hours.

The algorithm first sorts the piles of bananas in descending order. This allows us to use a binary search approach, since we know that the maximum value of k will be the size of the largest pile.

The algorithm then performs a binary search on the range [1, piles[0]], where piles[0] is the size of the largest pile. For each value of mid in the search range, the algorithm calculates the number of hours it would take Koko to eat all the bananas at a rate of mid bananas per hour. This is done by dividing the size of each pile by mid, rounding up to the nearest integer, and summing the results. If the number of hours is greater than h, the search continues in the range [mid+1, high]. If the number of hours is less than or equal to h, the search continues in the range [low, mid].

The algorithm terminates when low becomes greater than or equal to high, and the value of low is returned as the result. */