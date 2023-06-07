#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // your code here
        int n = image.size() , m = image[0].size() ;
        vector<vector<int>> isVisited (n , vector<int> (m, 0)) ;

        queue<pair<int, int>> q ; q.push({sr, sc}) ; isVisited[sr][sc] = 1 ;
        int old_color = image[sr][sc] ;
        while(!q.empty()){
            auto x  = q.front() ; q.pop() ;
            int cell_row = x.first , cell_col = x.second ;  image[cell_row][cell_col] = newColor ;

            // checking for the neighbours
            int i , j ; 
            // case 1
            i = cell_row -1 , j = cell_col ;
            if(i >=0 and i < n and j >=0 and j < m and image[i][j] == old_color and !isVisited[i][j]){
                isVisited[i][j] = 1 ; q.push(make_pair(i , j));
            }

            // case 2
            i = cell_row, j = cell_col+1 ;
            if(i >=0 and i < n and j >=0 and j < m and image[i][j] == old_color and !isVisited[i][j]){
                isVisited[i][j] = 1 ; q.push(make_pair(i , j));
            }

            // case 3
            i = cell_row +1 , j = cell_col ;
            if(i >=0 and i < n and j >=0 and j < m and image[i][j] == old_color and !isVisited[i][j]){
                isVisited[i][j] = 1 ; q.push(make_pair(i , j));
            }

            // case 4
            i = cell_row  , j = cell_col -1 ;
            if(i >=0 and i < n and j >=0 and j < m and image[i][j] == old_color and !isVisited[i][j]){
                isVisited[i][j] = 1 ; q.push(make_pair(i , j));
            }
        }

        return image ;

    }
};