#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

// Time Complexity : O(V*E)
// Space Complexity : O(V)

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        // Code here

        // the basis of this algorithm is that it takes atmost (N-1) edges to travel from first to last node in a graph (with total N nodes)

        vector<int> distance (V , 1e8) ;
        distance[S] =  0;// distance of source from source is always 0

        for(int i =1 ; i <= V ; i++){ // from 1st to Vth iteration

            // we have total V iteration "V-1" iterations for the shortest distance and the next iteration for checking the negative cycle in the graph --> which makes total of "V" iterations

            if(i == V){

                    // means Vth iteration
                // to detect -ve cycle

                for(auto it: edges){

                    int u = it[0], v = it[1] , weight = it[2] ;

                    // if even after V-1 th iteration it is possible to reduce the distance --> this means a negative cycle exist
                    if(distance[u] + weight < distance[v]){
                        return {-1} ;
                    }

                }

            }

            for(auto it : edges){

                int u = it[0] , v = it[1] , weight = it[2] ;
                if(distance[u] + weight < distance[v]){

                    distance[v] = distance[u] + weight ;

                }
            }

        }

        return distance ;

    }
};