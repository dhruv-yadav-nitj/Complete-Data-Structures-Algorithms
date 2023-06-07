#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

// Time Complexity : O(n *m)
// Space Complexity : O(n * m)

class Solution{
public:
    void dfs (vector<vector<char>> mat, int row, int col, vector<vector<int>> &isVisited, vector<vector<bool>> &mark){

        // first and foremost mark it visited
        isVisited[row][col] = 1 ;

        int row_changes[] = {-1, 0 , 1, 0} , col_changes[] = {0 , 1, 0, -1} ;
        for(int k = 0; k < 4 ; k++){
            int i = row + row_changes[k] , j= col + col_changes[k] ;
            if(i >=0 and i < mat.size()  and j >= 0 and j < mat[0].size() and mat[i][j] == 'O' and !isVisited[i][j]){
                mark[i][j] = false;
                dfs(mat, i, j, isVisited, mark);
            }
        }
        
    }

    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat){
        // code here
        vector<vector<int>> isVisited (n , vector<int>(m , 0)) ;
        vector<vector<bool>> mark (n , vector<bool>(m, true)) ; // this would tell us whether a particular cell should be changed or not --> initially we assume everything would be changed so we intitialised it with true --> further we would false those cells that are boundary 0's or are connected with any boundary 0's
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j  <  m ; j++){
                if((i ==0 or i == n-1 or j == 0 or j == m-1) and mat[i][j] == 'O' and !isVisited[i][j]){
                    // apply dfs
                    mark[i][j] = false ;
                    dfs(mat, i, j , isVisited, mark) ;
                }
            }
        }

        for(int i =0 ; i < n ; i++){
            for(int j =0 ; j < m ; j++){
                if(mark[i][j]){mat[i][j] = 'X' ;}
            }
        }

        return mat ;

    }
};