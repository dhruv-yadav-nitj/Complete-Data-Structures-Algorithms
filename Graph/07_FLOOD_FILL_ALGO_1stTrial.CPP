#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

// since we are traversing all the cell of the matrix --> Time Complexity: O(n * m) and Space Complexity: O(n *m) <-- for isVisited and Queue

class Solution {
public:
    void bfs (int row , int col , vector<vector<int>> &visited, vector<vector<int>> &image, int new_color){
        queue<pair<int, int>> q ; q.push({row , col}) ;
        visited[row][col] = 1 ;
        int old_color = image[row][col] ;
        int n = image.size() , m = image[0].size() ;
        while(!q.empty()){

            // bfs
            auto cell = q.front() ; int node_row = cell.first , node_col = cell.second ; q.pop() ;
            image[node_row][node_col] = new_color ;


            // checking for the neighbours
            int i , j ; 
            // case 1
            i = node_row -1 , j = node_col ;
            if(i >=0 and i < n and j >=0 and j < m and image[i][j] == old_color and !visited[i][j]){
                visited[i][j] = 1 ; q.push(make_pair(i , j));
            }

            // case 2
            i = node_row, j = node_col+1 ;
            if(i >=0 and i < n and j >=0 and j < m and image[i][j] == old_color and !visited[i][j]){
                visited[i][j] = 1 ; q.push(make_pair(i , j));
            }

            // case 3
            i = node_row +1 , j = node_col ;
            if(i >=0 and i < n and j >=0 and j < m and image[i][j] == old_color and !visited[i][j]){
                visited[i][j] = 1 ; q.push(make_pair(i , j));
            }

            // case 4
            i = node_row  , j = node_col -1 ;
            if(i >=0 and i < n and j >=0 and j < m and image[i][j] == old_color and !visited[i][j]){
                visited[i][j] = 1 ; q.push(make_pair(i , j));
            }

        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    // your code here

        int row = image.size() , col = image[0].size() ;
        vector<vector<int>> isVisited(row, vector<int>(col, 0)) ;

        bfs(sr, sc, isVisited, image, newColor) ;

        return image ;
    }
};