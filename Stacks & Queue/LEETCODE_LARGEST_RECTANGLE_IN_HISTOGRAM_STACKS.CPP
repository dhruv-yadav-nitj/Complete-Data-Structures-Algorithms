#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights){
        stack<int> s; int area= INT_MIN;
        int i=0;
        while(i < heights.size()){
            if(s.empty() or heights[s.top()] <= heights[i]){
                s.push(i); i++; 
            }
            else{
                int top = heights[s.top()] ; s.pop() ;
                int temp = top * (s.empty() ? i : i-s.top() -1);
                area= max(temp, area) ;
            }
        }
        while(!s.empty()){
            int top = heights[s.top()]; s.pop() ;
            int temp = top * (s.empty() ? i : i - s.top() -1);
            area = max(area, temp);
        }
        return area;
    }
};