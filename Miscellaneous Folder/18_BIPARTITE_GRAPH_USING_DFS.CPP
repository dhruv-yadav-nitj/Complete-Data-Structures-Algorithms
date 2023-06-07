#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

// Time Complexity: O(V + 2E) <-- thet's the time of dfs traversal
// Sapce Complexity : O(V)

class Solution {
public:
    bool dfs (int node , int node_color , int color[], vector<int> adj[]){

        // apply the node_color to the node
        color[node] = node_color ;

        for(auto x : adj[node]){
            if(color[x] == -1){
                if(dfs(x , !node_color , color, adj) == false){return false ;}
            }
            else{
                if(color[x] == node_color){return false ;}
            }
        }
        return true ;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here

        int color[V] ; for(int i =0; i < V ;i++){color[i] = -1 ;} // initially all the nodes are uncolored and are unvisited --> here color arr would work for isVisited arr as well

        for(int i =0; i < V ; i++){
            if(color[i] == -1 ){
                // apply dfs

                if(dfs(i , 0 , color , adj) ==false){return false ;}

            }
        }return true ;


	}

};