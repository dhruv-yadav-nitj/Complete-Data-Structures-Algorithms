#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

// dfs se to TLE maar gya --> lets try using BFS

class Solution {
  public:
    void dfs (vector<vector<int>> grid, int row, int col , vector<vector<int>>&isVisited){
        // dfs

        isVisited[row][col] = 1 ;
        int row_changes[] = {-1, 0 , 1, 0} , col_changes[] = {0 , 1, 0, -1} ;
        for(int k = 0; k < 4 ; k++){
            int i = row + row_changes[k] , j= col + col_changes[k] ;
            if(i >=0 and i < grid.size()  and j >= 0 and j < grid[0].size() and grid[i][j] == 1 and !isVisited[i][j]){
                dfs(grid, i, j, isVisited);
            }
        }
    }

    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n = grid.size() , m = grid[0].size() ;
        // we would be using dfs technique

        vector<vector<int>> isVisited (n , vector<int> (m, 0)) ;

        for(int i =0; i < n ; i++){
            for(int j = 0 ; j < m  ; j++){
                if((i ==0 or i == n-1 or j ==0 or j == m-1) and grid[i][j] == 1 and !isVisited[i][j]){
                    // means un 1's ko pakdo jo boundary pr hain and unvisited hain --> visited ko waapis visit krne ka kya faayda
                    // apply dfs on those 1's and mark the connected 1's

                    dfs(grid, i, j, isVisited) ;
                }
            }
        }
        
        // last mein hmare paas wo 1's hi visited pdhe honge jo --> boundary pr honge ya kisi aise 1 se connected honge jo boundary pr honge

        int count=0 ;
        for(int i =0; i < n ; i++){
            for(int j = 0 ; j< m ; j++){
                if(grid[i][j] == 1 and !isVisited[i][j]){count++ ;}
            }
        }
        return count ;

    }
};