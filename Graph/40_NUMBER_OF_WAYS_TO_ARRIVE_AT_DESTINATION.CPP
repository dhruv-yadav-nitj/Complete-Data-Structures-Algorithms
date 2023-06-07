#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

// Good Question --> slight change in djikstra's algorithm

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

            // code here

        // input is generated in such a way that atleast one answer always exist

        int src = 0 , dest = n - 1 ;
        vector<long long> distance (n , 1e9) , ways(n , 0) ; // distance would store the time(minimum) to reach a node and ways would store the number of ways in which we can reach a node following the path with shortest time


        // making an adjacency list
        vector<pair<int, long long>> adj[n] ;
        for(auto x : roads){    

            int u= x[0] , v = x[1] , time = x[2] ;
            adj[u].push_back({v, time}); adj[v].push_back({u, time}) ;

        }

        

        // {distance, node}
        priority_queue<pair<long long, int> , vector<pair<long long, int>> , greater<pair<long long, int>>> pq ;

        pq.push({0, src}) ; ways[src]= 1 ; distance[0] = 0;

        while(!pq.empty()){

            auto x = pq.top() ; pq.pop() ;
            int curr= x.second , dist = x.first ;

            for(auto it : adj[curr]){

                int node = it.first , weight = it.second ;

                if(dist+ weight < distance[node]){

                    distance[node] = dist + weight ; ways[node]= ways[curr] ;

                    pq.push({dist + weight , node}) ;

                }
                else if(dist + weight == distance[node]){

                    ways[node] = (ways[node]+ ways[curr]) %((int)(1e9+ 7)) ;

                }
            }
        }

        return ways[n-1]%((int)1e9 + 7) ;
    }
};