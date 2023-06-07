#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

// Space Complexity : O(V) + O(V)
// Time Complexity : O(V^2) + O(V + 2E)

class Solution {
  public:
    void dfs (int node , vector<int> adj[] , int visited[]) {
        // dfs function
        visited[node] = 1 ;
        for(auto x : adj[node]){
            if(!visited[x]){
                dfs(x , adj , visited) ;
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here

        // so two nodes can be said to belong to one single province if they are directy or indirectly connected to each other through edges --> we have to return the number of province here

        // caution : this problem has adjacency matrix given and not adjacency list
        
        int count = 0 ; int visited[V + 1] = {0}; // since the indexing is 1-based
        
        // we first need to make adjacency list out of this adjacency matrix
        vector<int> adj_list[V + 1] ;
        for(int i =0 ; i < V; i++){
            for(int j = 0 ; j < adj[i].size() ; j++){
                if(adj[i][j] == 1 and i != j){
                    adj_list[i+1].push_back(j + 1) ; // since the graph is 1-based indexing
                    adj_list[j +1].push_back(i +1) ; // since the graph is 1-based indexing
                }
            }
        }

        for(int i=1 ; i <= V; i++){

            if(!visited[i]){
                count++ ;
                dfs(i , adj_list , visited) ;
            }
        }

        return count ;

    }
};