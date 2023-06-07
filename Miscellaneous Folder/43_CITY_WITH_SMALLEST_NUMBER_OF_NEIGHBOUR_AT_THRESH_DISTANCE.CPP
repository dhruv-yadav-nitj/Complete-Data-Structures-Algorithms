#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

// this problem can also be done using Djikstra's algo --> but did it using Floyd's Algo bcz of ease

class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {

        // code here
        
        // step 1
            // create an adjacency matrix using the given edges that also stores the shortest distance from a node to other node
        vector<vector<int>> matrix (n , vector<int> (n , 1e9));

        for(int i =0 ; i < m ; i++){

            int u = edges[i][0] , v = edges[i][1] , weight = edges[i][2] ;
            matrix[u][v] = weight ; matrix[v][u]= weight ;
        }

        // shortest distance from a node to itself is 0, set that
        for(int i=0; i < n ; i++){
            for(int j=0; j < n ; j++){if(i ==j){matrix[i][j]= 0; }}
        }

        // step 2
            // apply floyd's algo
        for(int k =0 ; k < n ; k++){
            for(int i=0 ;i < n ; i++){
                for(int j  =0 ; j < n ; j++){
                    matrix[i][j] = min (matrix[i][j] , matrix[i][k] + matrix[k][j]) ;
                }
            }
        }

        int ans = INT_MIN, maxiCount=INT_MIN ;
        for(int i =0 ; i < n ; i++){

            int count=0; 
            for(int j =0; j < n ; j++){
                if(matrix[i][j] <= distanceThreshold){
                    count++ ;
                }
            }

            if(maxiCount <= count){
                ans = i ; maxiCount = count ;
            }
        }

        return ans ;

    }
};