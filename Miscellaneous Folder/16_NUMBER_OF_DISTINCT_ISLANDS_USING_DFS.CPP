#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

class Solution {
  public:
    void dfs (int row_base, int col_base , int row, int col , vector<vector<int>> grid , vector<vector<int>> &isVisited, vector<pair<int, int>>&store){
        int n = grid.size() , m = grid[0].size() ;
        // apply dfs here

        // mark the cell as visited
        isVisited[row][col] = 1 ;

        store.push_back({
            row - row_base , col - col_base
        });

        int row_changes[] = {-1 , 0 , 1, 0} , col_changes[] = {0 , 1, 0, -1} ;
        for(int k = 0 ; k < 4; k++){
            int i = row + row_changes[k] , j = col + col_changes[k] ;
            if(i >= 0 and i < n and j >= 0 and j < m and grid[i][j] == 1 and !isVisited[i][j]){
                dfs(row_base, col_base , i , j , grid, isVisited, store) ;
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size() , m = grid[0].size() ;
        vector<vector<int>> isVisited (n , vector<int>(m, 0)) ; set<vector<pair<int, int>>> s ;

        for(int i =0; i<  n; i++){
            for(int j = 0 ; j < m ; j++){
                if(!isVisited[i][j] and grid[i][j] == 1){
                    // go to dfs
                    vector<pair<int, int>> store ;
                    dfs(i , j , i, j, grid, isVisited, store) ; s.insert(store) ;
                }
            }
        }return s.size() ;

    }
};