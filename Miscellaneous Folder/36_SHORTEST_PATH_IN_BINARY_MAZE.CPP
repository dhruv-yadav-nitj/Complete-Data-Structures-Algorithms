// https://practice.geeksforgeeks.org/problems/shortest-path-in-a-binary-maze-1655453161/1
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination) {
        // code here

        // we need a distance matrix to store the distance of cells from source cell
        int n = grid.size() , m = grid[0].size() ;
        vector<vector<int>> distance (n , vector<int> (m ,1e9)) ; // assume that the initial distance of all the cells from source cell is 1e9 (very large)

        // we need to move horizontal and vertical cells
        int move_horiz[] = {-1 , 0 , 1 , 0} , move_vertical[] = {0 , 1, 0 , -1} ;

        // since we can also perform this ques using queue instead of using priority_queue , which infact would save our logN time
        queue<pair<int, pair<int, int>>> q ;
        q.push({0 , {source.first , source.second}}); // q mein push kr diaa source
        distance[source.first][source.second] = 0 ; // distance of source from source is 0
        while(!q.empty()){

          auto x = q.front() ; q.pop() ;
          int dis = x.first ; int curr_row = x.second.first , curr_col = x.second.second ;

          for(int i =0 ;i < 4 ; i++){
            int next_cell_row = curr_row + move_horiz[i] , next_cell_col = curr_col + move_vertical[i] ;
            if(next_cell_row >= 0 and next_cell_row < n and next_cell_col >= 0 and next_cell_col < m and
                  grid[next_cell_row][next_cell_col] == 1 and distance[next_cell_row][next_cell_col] > dis + 1){
                    distance[next_cell_row][next_cell_col] = dis + 1 ;
                    q.push({dis + 1 , {next_cell_row , next_cell_col}}) ;
                  }
          }

        }

        if(distance[destination.first][destination.second] == 1e9){return -1 ;}
        else{
          return distance[destination.first][destination.second] ;
        }

    }
};