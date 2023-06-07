#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

// Time Complexity : O((V+E)logV)

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    
    int spanningTree(int V, vector<vector<int>> adj[]){
        // code here
        
        int sum =0 ; 
        // weight, node , parent --> our data package : pair<int, pair<int, int>>

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>> , greater<pair<int, pair<int, int>>>> pq ;
        vector<bool> isVisited (V, false) ; // mark all of them initially as un-visited

        pq.push({0 , {0, -1}}) ;
        while(!pq.empty()){
            auto it = pq.top() ; pq.pop() ;

            int node = it.second.first , parent = it.second.second , weight = it.first ;
            if(!isVisited[node]){
                // if the node is unvisited then go ahead
                isVisited[node]= true ; sum += weight ;

                for(auto x : adj[node]){

                    int connected_node = x[0] , wt = x[1] ;
                    if(!isVisited[connected_node]){
                        pq.push({wt , {connected_node , node}}) ; // node would act as parent for connected_node
                    }
                }
            }
        }

        return sum ;
    }
};