#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

// Time Complexity : O(N)
// Space Complexity: O(N + 2E) + O(N)

class Solution {
public:
    bool dfs_cycle (int node , int parent , vector<int> adj[] , int isVisited[]){
        // function to detect cycle using dfs

        isVisited[node] = 1 ;
        for(auto x : adj[node]){
            if(x != parent){

                // hme is node k usi side aage badhna hain jis side parent node --> checked using if condition
                if(isVisited[x]){return true ;}
                else if(dfs_cycle(x , node , adj, isVisited)){
                    return true ;
                }
            }
        }

        return false ;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here

        int isVisited[V] = {0} ; // array to check whether a node is visited or not

        for(int i =0 ; i < V ; i++){
            
            if(!isVisited[i]){
                // call for dfs
                if(dfs_cycle(i , -1, adj, isVisited)){return true ;}
            }
        }

        return false ;

    }
};