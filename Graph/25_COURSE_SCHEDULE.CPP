// https://practice.geeksforgeeks.org/problems/course-schedule/1
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) {
        //code here

        // n = number of nodes  and m = the size of prerequisites
        
        // step 1 : create adjacency list
        vector<int> adj [n] ;
        for(auto x : prerequisites){
            adj[x[1]].push_back(x[0]) ;
        }

        // step 2 : create a indegree wala array
        int indegree[n] = {0} ;
        for(int i =0; i < n ; i++){
            for(auto x : adj[i]){
                indegree[x]++ ;
            }
        }

        // step 3: insert those nodes in the queue which have 0 indegree
        queue<int> q ;
        for(int i = 0 ; i < n ; i++){
            if(indegree[i] == 0){q.push(i) ;}
        }

        // step 4: apply kaan's algo
        vector<int> topo ;
        while(!q.empty()){
            int node = q.front() ; q.pop() ; topo.push_back(node) ;
            for(auto x : adj[node]){
                indegree[x]--; if(indegree[x] == 0){q.push(x) ;}
            }
        }

        if(topo.size() == n){return topo ;}
        else{
            return {} ;
        }
    }
};