#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

// Approach : use BFS --> phle to queue mein un 1's ka i, j daal do jo boundary pr already hain --> un cells ka visited bhi mark kr do --> phir ek ek kr ke queue k front nikalte jaao aur us front waale se jitne 1's connected hain unko bhi visited mark krte chalo aur queue mein daalte chalo --> last mein kya hoga ki jo 1's aise bache hain jo abhi tk unvisited hain --> wo hi hmare ans hain --> simply count them

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here

        int n = grid.size() , m = grid[0].size() ;
        vector<vector<int>> isVisited (n, vector<int>(m, 0)) ; // start mein saare unvisited hain
        
        queue<pair<int, int>> q ;
        for(int i =0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if( (i==0 or i == n-1 or j ==0  or j == m-1) and grid[i][j] == 1){
                    q.push({i , j}) ; isVisited[i][j] = 1 ;
                }
            }
        }

        while(!q.empty()){
            auto cell = q.front() ; int row = cell.first , col = cell.second ; q.pop() ;

            int row_changes[] = {-1, 0 , 1, 0} , col_changes[] = {0 , 1, 0, -1} ;
            for(int k = 0; k < 4 ; k++){
                int i = row + row_changes[k] , j= col + col_changes[k] ;
                if(i >=0 and i < grid.size()  and j >= 0 and j < grid[0].size() and grid[i][j] == 1 and !isVisited[i][j]){
                    isVisited[i][j] = 1 ; q.push({i, j}) ;
                }
            }
        }

        int count =0 ;
        for(int i =0; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1 and !isVisited[i][j]){count++ ;}
            }
        }return count ;

    }
};