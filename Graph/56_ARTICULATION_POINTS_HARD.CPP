#include <bits/stdc++.h>
using namespace std ;

// https://takeuforward.org/data-structure/articulation-point-in-graph-g-56/

class Solution {
  public:

    void dfs (vector<int> adj[] , int node , int parent , int time[] , int low[] , vector<int>&mark , vector<int>&isVisited, int &timer){
        
        isVisited[node] = 1 ;
        time[node] = low[node] = timer++ ;

        int child = 0 ;
        for(auto it : adj[node]){

            if(it != parent){

                if(!isVisited[it]){
                    dfs(adj , it , node , time, low , mark , isVisited , timer) ;

                    low[node]= min(low[node] , low[it]) ;
                    if(low[it] >= time[node] and parent != -1){
                        mark[node] = 1 ;
                    }

                    child++ ;
                }
                else{
                    low[node] = min(low[node] , time[it]) ;
                }
            }
        }

        // special case for starting node
        if(child > 1 and parent == -1){
            mark[node] = 1 ;
        }

    }

    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here

        // given adjacency list --> a delight to eyes (since adjacency list is not given generally directly)

        vector<int> isVisited (V ,0) ; vector<int> isArticulationPoint (V , 0) ; int timer = 1 ;
        int time[V] , low[V] ;

        for(int i = 0 ; i < V ; i++){
            if(!isVisited[i]){

                // perform dfs if the node is unvisited
                dfs(adj , i , -1 , time, low , isArticulationPoint, isVisited , timer) ;

            }

        }

        vector<int> ans;
        for(int i=0; i < V ; i++){
            if(isArticulationPoint[i]){
                ans.push_back(i) ;
            }
        }

        if(ans.size() ==0){return {-1} ;} // Given : If there are no such vertices then return a list containing -1.
        return ans;

    }
};