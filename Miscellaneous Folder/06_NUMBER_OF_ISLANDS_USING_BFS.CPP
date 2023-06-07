#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

// https://leetcode.com/problems/number-of-islands/

// follow up :- do the same problem using dfs

// ques dekh kr lgega ki ek graoh bana lete hain given matrix k according --> believe me wrong ans aaega
// thoda sa tricky ques hain

// Aux Space : O(n * m) <-- for storing the visited
// Time Complexity : approx. O(n * m)

class Solution {
public:
    void bfs (int row , int col , vector<vector<int>> &visited , vector<vector<char>> grid){
        // bfs
        visited[row][col]= 1;  int n = grid.size()  , m = grid[0].size() ;
        queue<pair<int, int>> q ; q.push(make_pair(row, col)) ;

        while(!q.empty()){
            int node_row = q.front().first , node_col = q.front().second ; q.pop() ;

            // traverse in the neighbours and make them 1
            // leetcode pr neighbours means --> sirf horizontally and vertically hain
            
            // we have to check for grid[node_row -1][node_col] , grid[node_row][node_col +1] , grid[node_row+1][node_col] , grid[node_row][node_col-1]
            


            int i , j ; 
            // case 1
            i = node_row -1 , j = node_col ;
            if(i >=0 and i < n and j >=0 and j < m and grid[i][j] == '1' and !visited[i][j]){
                visited[i][j] = 1 ; q.push(make_pair(i , j));
            }

            // case 2
            i = node_row, j = node_col+1 ;
            if(i >=0 and i < n and j >=0 and j < m and grid[i][j] == '1' and !visited[i][j]){
                visited[i][j] = 1 ; q.push(make_pair(i , j));
            }

            // case 3
            i = node_row +1 , j = node_col ;
            if(i >=0 and i < n and j >=0 and j < m and grid[i][j] == '1' and !visited[i][j]){
                visited[i][j] = 1 ; q.push(make_pair(i , j));
            }

            // case 4
            i = node_row  , j = node_col -1 ;
            if(i >=0 and i < n and j >=0 and j < m and grid[i][j] == '1' and !visited[i][j]){
                visited[i][j] = 1 ; q.push(make_pair(i , j));
            }

        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size() , m = grid[0].size() ;
        // then we have something k/a visited array
        vector<vector<int>> visited (n , vector<int>(m, 0)) ; // visited array k jagah pr vector jisme sbkuch phle to 0 hai --> with n rows and m columns
        int count (0) ;
        for(int i = 0 ; i < n ; i++){
            for(int j= 0 ; j < m ; j++){

                if(!visited[i][j] and grid[i][j] == '1'){
                    count++ ;
                    bfs(i , j , visited , grid) ;
                }

            }
        }

        return count ;

    }
};