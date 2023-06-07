// https://leetcode.com/problems/01-matrix/
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        // code here
        int n = mat.size() , m = mat[0].size() ;

        // pre-required
        vector<vector<int>> ans (n, vector<int>(m, 0)) ; queue<pair<pair<int, int> , int>> q ;
        vector<vector<int>> isVisited (n , vector<int>(m , 0)) ;

        // jitne bhi cells mein already 0 hain --> un cells mein dis 0 rhega so aisa kr do
        for(int i =0; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(mat[i][j] == 0){
                    ans[i][j] = 0 ; isVisited[i][j] = 1 ; q.push({{i, j} , 0}) ;
                }
            }
        }

        while(!q.empty()){
            auto cell = q.front() ; int cell_row = cell.first.first , cell_col = cell.first.second , dis= cell.second ; q.pop() ;

            int row_changes[] = {-1, 0, 1, 0} , col_changes[] = {0, 1, 0, -1} ;
            for(int k = 0; k < 4 ; k++){
                int i = cell_row + row_changes[k] , j= cell_col + col_changes[k] ;
                if(i >= 0 and i < n and j >= 0 and j < m and mat[i][j] == 1 and !isVisited[i][j]){
                    isVisited[i][j] = 1 ; ans[i][j] = dis + 1 ; q.push({{i, j} , dis+1}) ;
                }
            }
        }

        return ans ;

    }
};