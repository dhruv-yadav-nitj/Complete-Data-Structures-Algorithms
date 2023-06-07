#include <bits/stdc++.h>
#define MAX 1000
using namespace std ;

class Solution{
private:
// this code belongs to the Problem 84. Largest Rectangle in Histogram
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
public:

// this problem is directly a modified problem of the Largest Rectangle in Histogram.
// here we have to just take the heights of each columns in each row and calculate the area using the above function , assuem we have to make the histogram using the 1's in each column
    int maxArea(int M[MAX][MAX], int n, int m){
        // first compute the results for the first row
        vector<int> heights; 
        for(int j=0; j< m; j++){
            heights.push_back(M[0][j]) ;
        }
        int area = largestRectangleArea(heights) ;

        // now we would add the heights accordingly of each row 
        for(int i=1; i< n; i++){
            vector<int> heightsTemp ;
            for(int j=0; j< m ; j++){
                if(M[i][j] == 0){
                    M[i][j] =0 ;
                }
                else{
                    M[i][j] = M[i][j] + M[i-1][j] ;
                }
                heightsTemp.push_back(M[i][j]) ;
            }
            area = max(area, largestRectangleArea(heightsTemp)) ;
            heightsTemp.clear() ;
        }
        return area ;
    }
};