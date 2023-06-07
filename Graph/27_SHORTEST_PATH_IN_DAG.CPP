#include <bits/stdc++.h>
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
using namespace std;

// https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1

class Solution{
public:
    void topo(int node , stack<int>&s , vector<pair<int,int>>adj[], int isVisited[]){
        isVisited[node] = 1;
        for(auto x : adj[node]){
            if(!isVisited[x.first]){
                topo(x.first , s , adj, isVisited) ;
            }
        }
        s.push(node) ;
    }
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges){
        // code here

        // step 1 : making an adjacency list
        vector<pair<int, int>> adj[N];
        for (int i = 0; i < M; i++){
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }

        // step 2 : make the isVisited array and apply toposort using DFS
        int isVisited[N] = {0}; stack<int> s ;
        for (int i = 0; i < N; i++){
            if(!isVisited[i]){
                // apply dfs-toposort
                topo(i , s , adj , isVisited) ;
            }
        }

        // step 3 : ab to main kaam rh gya --> distance array ko prepare krna
        int source = 0 ; // is ques mein source ko 0 hi maana gya hain
        vector<int> distance (N, 1e9) ; // har ek node ka distance dekha jaaega from source node --> initially to INT_MAX rkh do distance baad mein reduce kr lenge --> suppose distance[1] hain to ye source node aur graph ka node =1 k beech ka distance hain

        distance[source] = 0 ;
        while(!s.empty()){
            int node = s.top () ; s.pop() ;

            for(auto x : adj[node]){
                int val  = x.first , weight = x.second ;
                if(distance[val] > distance[node] + weight){
                    distance[val] = distance[node]+ weight ;
                }
            }

        }


        for(int i =0 ; i < N ; i++){
            if(distance[i] == 1e9){distance[i] = -1 ;}
        }

        return distance ;

    }
};