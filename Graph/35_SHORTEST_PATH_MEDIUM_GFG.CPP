#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

// https://practice.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {

        // step 1 : is to make adjacenecy list
        vector<vector<int>> adj[n + 1] ;
        for(auto it : edges){
            int u = it[0] , v= it[1] , wt = it[2] ;
            adj[u].push_back({v , wt}) ; adj[v].push_back({u, wt}) ;
        }

        // initialise the pre-requisited required
        vector<int> distance (n+ 1 , 1e9) ; int source = 1 ;
        priority_queue<pair<int, int> , vector<pair<int, int>> , greater<pair<int, int>>> pq ;
        // plus we need something for memoization --> for a node we need to remember from which node we came from
        vector<int> parent (n+1) ; for(int i =0 ; i< n+1 ; i++){parent[i] = i ;}

        // now start djikstra's algo
        pq.push({0 , source}) ; // pair<distance , node>
        distance[source]= 0 ; // distance of source from source is 0
        while(!pq.empty()){

            int dis = pq.top().first , par = pq.top().second ; pq.pop() ;
            for(auto it : adj[par]){
                int node = it[0] , wt = it[1] ;
                if(dis + wt < distance[node]){
                    distance[node] = dis + wt ; parent[node] = par ;
                    pq.push({distance[node], node}) ;
                    // in djikstra's algo using set hm bs ek extra cheej krenge ki yha pr erase lga denge
                }
            }
        }

        vector<int> ans ;
        if(parent[n] == n){return {-1} ;}
        int node = n ;
        while(parent[n] != n){
            ans.push_back(n) ; n = parent[n] ;
        }ans.push_back(source) ; reverse(ans.begin() , ans.end()) ; return ans ;
        
    }
};