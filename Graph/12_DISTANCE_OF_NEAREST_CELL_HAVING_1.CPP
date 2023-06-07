#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

// Time Complexity  :  O(n * m + n*m*4)
// Space Complexity : O(n * m)


class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid){
	    // Code here

        int n = grid.size() , m = grid[0].size() ;
        // we need a queue data str and a visited 2-d arr
        vector<vector<int>> isVisited (n , vector<int> (m, 0)) ;
        queue<pair < pair<int, int>, int>> q;
        
        vector<vector<int>> ans (n, vector<int>(m , 0)) ; // set the cells of ans matrix as 0

        // step 1 : q mein daal do wo cells jha jha pr 1 exist krta hain already
        for(int i =0; i < n ; i++) {
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] ==1){
                    q.push({{i, j} , 0}) ; isVisited[i][j] = 1 ;
                    ans[i][j] = 0 ;
                }
            }
        }


        // given that we have atleast one 1 in the grid
        while(!q.empty()){
            auto cell = q.front() ; q.pop() ;
            int cell_row = cell.first.first , cell_col = cell.first.second , dis = cell.second ;

            int row_changes[] = {-1 , 0 , 1 , 0} , col_changes[] = {0, 1, 0, -1} ;
            for(int k = 0; k < 4 ; k++){
                int i = cell_row + row_changes[k] , j = cell_col + col_changes[k];
                if(i >= 0 and i < n and j >=0 and j < m and grid[i][j] == 0 and !isVisited[i][j]){
                    isVisited[i][j] = 1 ; q.push({{i, j} , dis+1}) ;
                    ans[i][j] = dis + 1 ;
                }
            }
        }

        return ans ;
	}
};