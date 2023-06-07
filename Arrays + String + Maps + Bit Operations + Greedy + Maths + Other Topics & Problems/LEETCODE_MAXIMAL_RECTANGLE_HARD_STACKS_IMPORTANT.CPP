#include <bits/stdc++.h>
using namespace std ;

// if you are again at this place then first go to the problem gfg max rectangle hard level file and leetcode largest rectangle in histogram files

class Solution{
private:
    int largestRectangleArea(vector<int> heights){
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
    int maximalRectangle(vector<vector<char>>& matrix){
        vector<int> heights ;
        vector<vector<int>> newMatrix (matrix.size()) ;
        newMatrix[0] = vector<int>(matrix[0].size()) ;
        for(int j=0; j< matrix[0].size() ; j++){
            if(matrix[0][j] == '0'){
                newMatrix[0][j] = 0 ;
                heights.push_back(0) ;
            }
            else{
                newMatrix[0][j] = 1;
                heights.push_back(1) ;
            }
        }
        int area = largestRectangleArea(heights) ;

        for(int i =1 ; i< matrix.size() ; i++){
            heights.clear() ;
            newMatrix[i] = vector<int>(matrix[i].size()) ;
            for(int j= 0; j< matrix[i].size() ; j++){
                if(matrix[i][j] == '0'){
                    newMatrix[i][j] = 0 ;
                    heights.push_back(0) ;
                }
                else{
                    newMatrix[i][j] = newMatrix[i-1][j] + 1 ;
                    heights.push_back(newMatrix[i][j]) ;
                }
            }
            area = max(area, largestRectangleArea(heights)) ;
        }
        return area ;
    }
};