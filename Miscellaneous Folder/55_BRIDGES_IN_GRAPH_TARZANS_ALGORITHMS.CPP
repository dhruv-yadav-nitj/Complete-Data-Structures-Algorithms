#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;


// https://leetcode.com/problems/critical-connections-in-a-network/
// Critical Connections in a network : Leetcode [HARD]

class Solution {
public:
    int timer = 1 ; // can start from 0 or 1 --> but lets start from 1

    void dfs (vector<int> adj[] , int node , int parent, int isVisited[] , int time[] , int low[] , vector<vector<int>>&bridges){

        isVisited[node] = 1 ; time[node] = low[node]= timer; timer++ ;

        for(auto it: adj[node]) {

            if(it != parent){

                // never take parent into account --> because parent would always lie before you so parent's time is of no use to current node

                // case 1: if the adjacent node is unvisited
                if(!isVisited[it]){
                    dfs(adj , it , node , isVisited, time , low , bridges) ;
                    
                    low[node] = min(low[it] , low[node]) ;

                    if(low[it] > time[node]){
                        bridges.push_back({node, it}) ;
                    }
                }
                // case 2 : if it is already visited --> then we would compare the lowest insertion times
                else{
                    low[node] = min(low[node] , low[it]) ;
                }
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // code here

        // step 1 : creating an adjacency list
        vector<int> adj[n] ; // since the problem is 1-based indexing
        for(auto it: connections){

            int u = it[0],  v = it[1] ;
            adj[u].push_back(v) ; adj[v].push_back(u) ; // undirected graph
        }

        // need three arrays --> isVisited , time , low --> low would be storing the minimum lowest time of insertion into account
        int isVisited[n] , time[n] , low[n] ;
        for(int i=0 ;i < n ; i++){
            isVisited[i] = 0 ;
        }
        // we also need a timer variable which would store the current time helping in the insertion of time of insertion

        vector<vector<int>> ans ; // woudl be storing the bridge edges in the form of [u, v]

        dfs(adj , 0 , -1 , isVisited , time , low , ans) ;        
        
        return ans ;

    }
};