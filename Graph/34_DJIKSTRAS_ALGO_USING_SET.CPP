#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

// Time Complexity : O(Elog(V))
// Space Complexity : O(E + V)

class Solution{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S){
        // Code here
        vector<int> distance (V , 1e9) ;
        set <pair<int, int>> ss ; ss.insert({0 , S}) ; distance[S] = 0 ;
        vector<int> ans ;

        while(!ss.empty()){
            
            auto it  = *(ss.begin()) ; // aisa bhi hota hain 
            int curr = it.second , dis = it.first ; ss.erase({dis,  curr}) ;
            for(auto x : adj[curr]){
                int node = x[0] , wt = x[1] ;
                if(distance[node] > dis + wt){
                    ss.erase({distance[node] , node});
                    distance[node] = dis + wt ; ss.insert({distance[node] , node}) ;
                }
            }
        }

        // since the graph is connected so we can assume that every node is reachable from other
        for(auto x : distance){
            ans.push_back(x) ;
        }return ans ;
    }
};