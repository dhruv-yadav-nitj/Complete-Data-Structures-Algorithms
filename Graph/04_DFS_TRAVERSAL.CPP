#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

class Solution {
  public:
    void dfs_fn (vector<int> adj[] , int node , int visited[] , vector<int>&dfs){

        // our dfs function

        // hm jaise is function mein enter hue --> waise hi jo node usko visited mark kr do --> and dfs mein ghusa do
        visited[node] = 1 ; dfs.push_back(node) ;
        for(auto x: adj[node]){
            if(!visited[x]){ // isme tbhi jaaega jb wo unvisited hain
                dfs_fn(adj,  x , visited , dfs) ;
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here

        vector<int> dfs ; // this vector would serve as our ans vector
        // since the graph is 0-based indexing we need a visited arr of size V only
        int isVisited[V] =  {0} ; // all the values 0 means it is not visited yet
        dfs_fn(adj , 0 , isVisited , dfs) ; return dfs ; // starting node can be any node , but here we have started from node 0
    }
};