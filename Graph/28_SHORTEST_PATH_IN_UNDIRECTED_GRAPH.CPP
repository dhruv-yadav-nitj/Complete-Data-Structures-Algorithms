
// https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1

#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here

        // step 1: convert the given 2d matrix to adjacency list
        vector<int> adj[N] ;
        for(auto x : edges){
            int u = x[0] , v = x[1] ;
            adj[u].push_back(v) ; adj[v].push_back(u) ;
        }

        // step 2 : now we need a queue to breeze through our bfs solution and a distance array of course
        queue<int> q ; int distance[N] ; for(int i =0 ; i < N ; i++){distance[i] = 1e9 ;}
        q.push(src) ; distance[src] = 0;  // well it is clear that the distance of src from src is 0
        while(!q.empty()){
            int node = q.front() ; q.pop() ;
            for(auto x : adj[node]){
                // now we would see for the adjacent nodes of the current node
                if(distance[node] + 1 < distance[x]){ // why 1 ? -- > because the weight of each edge given is 1 and also we are travelling bfs (means level wise)
                    distance[x] = distance[node] + 1 ; q.push(x) ;
                }
            }
        }

        // step 3: since we have to return the ans in vector form --> well we could have taken vector initially instead of distance array but its ok
        vector<int> ans ;
        for(int i =0 ; i < N ; i++){
            if(distance[i] == 1e9){ans.push_back(-1) ;}
            else{
                ans.push_back(distance[i]) ;
            }
        }return ans ;

        // if the given graph is given in the form of different sub graphs --> then we can say simply that we cant traverse to the other sub graph nodes from the source node so in that case there would be -1 in the distance array

    }
};