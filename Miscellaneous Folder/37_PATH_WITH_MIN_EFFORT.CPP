#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

// Time Complexity : O(4*N*M * log(N*M)) --> we would visit N*M nodes and with every node we would be checking its 4 adjacent neighbours using for loop and log(N*M) for the operation in priority queue
// Space Complexity : O(N*M)

class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        // Code here

        int n = heights.size() , m = heights[0].size() ;
        vector<vector<int>> effort (n , vector<int> (m , 1e9)) ;
        priority_queue <pair<int, pair<int, int>> , vector <pair<int, pair<int, int>>> , greater<pair<int, pair<int, int>>>> pq ;

        pq.push({0 , {0, 0}}) ; effort[0][0] = 0 ;

        int row_change[] = {-1 , 0 , 1 , 0} , col_change[] = {0 , 1 , 0 , -1} ;

        while(!pq.empty()){

          auto x = pq.top() ; pq.pop() ;
          int prev_effort = x.first , row= x.second.first , col = x.second.second ;

          for(int i =0; i < 4 ; i++){

              int new_row = row + row_change[i] , new_col = col + col_change[i] ;
              
              if(new_row >= 0 and new_row < n and new_col >= 0 and new_col < m){

                  int new_effort = abs(heights[new_row][new_col] - heights[row][col]) ;
                  // but new effort uppar wla ho bhi skta hain aur nahi bhi --> since the effort would be max of the difference
                  new_effort = max(prev_effort , new_effort );

                  // ab new_effort ko effort mein tbhi daalenge jb new_effort km hoga
                  if(new_effort < effort[new_row][new_col]){
                      effort[new_row][new_col] = new_effort ;

                      pq.push({new_effort , {new_row, new_col}}) ;
                  }

              }

          }
        }

        return effort[n-1][m-1] ;

    }
};