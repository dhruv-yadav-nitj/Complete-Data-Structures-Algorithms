#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here

        int n = matrix.size() ;

            // step 1 : we would convert the given matrix such that it would contain the shortest distance b/w two nodes
        // step 1 :  in the matrix set : if two nodes are unreachable from each other set the shortest distance b/w them as 1e9 and if two nodes are same then the shortest distance b/w them would be 0 obviously

        for(int i=0; i < n; i++){

            for(int j  = 0 ; j < n ; j++){

                if(i == j){
                    matrix[i][j] = 0 ;
                }
                else if(matrix[i][j]== -1){
                    matrix[i][j] = 1e9 ;
                }
            }
        }


        // floyd warshall algo        
        for(int k = 0 ; k < n ; k++){
            // loop for intermediate node

            for(int i=0 ; i < n ; i++){
                for(int j = 0 ; j < n ; j++){
                    // loop which changes the source and destination node from 0 to n-1

                    matrix[i][j] = min(matrix[i][j] , matrix[i][k] + matrix[k][j]);

                }
            }
        }


        // step 3 : if two nodes are unreachable then set the distance b/w them as -1
        for(int i =0 ;i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(matrix[i][j] == 1e9){
                    matrix[i][j] = -1 ;
                }
            }
        }


        // detecting negative cycle
        for(int i =0; i < n; i++){
            for(int j = 0 ; j < n ; j++){
                if(i == j and matrix[i][j] < 0){
                    // negative cycle present
                }
            }
        }

        // return matrix[i][j] ;

	}
};