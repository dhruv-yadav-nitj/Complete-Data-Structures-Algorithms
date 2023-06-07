#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        // Code here

        // step 1 --> we need to create an adjacency list

        vector<pair<int, int>> adj[n] ; // since we have n cities

        for(auto x : flights){

            int from = x[0] , to = x[1] , cost = x[2] ;
            adj[from].push_back({to, cost}) ;

        }

        vector<int> distance (n, 1e9) ; // normal djikstra's algo requirement


        queue<pair<int, pair<int, int>>> q ; // {stops , {node , cost}}

        q.push({0, {src , 0}}) ;

        while(!q.empty()){

            auto temp = q.front() ; q.pop() ;

            int stops = temp.first ; int curr = temp.second.first ; int dist = temp.second.second ;

            if(curr == dst and stops == K + 1){ // why K + 1 --> bcz initial ko bhi hmne count kra hain as a stop

                return dist ;
            }

            for(auto x : adj[curr]){

              int node = x.first , weight = x.second ;

                // we only update the queue if the new calculated distance is less than the prev and the stops are also within reach
                if(dist + weight < distance[node]  and stops <= K){
                    distance[node] = dist + weight ;
                    q.push({stops + 1 , {x.first , dist + x.second}}) ;
                }

            }
        }


        return -1 ;

    }
};