#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights){
        // brute force method
        int area(INT_MIN) ;
        for(int i=0; i< heights.size(); i++){
            int count(1);
            int left = i-1, right = i+1;
            while(left >= 0 and heights[left] >= heights[i]){
                count++ ; left-- ;
            }
            while(right < heights.size() and heights[right] >= heights[i]){
                count++; right++; 
            }
            area= max(area, count*heights[i]);
        }return area;
    }
};