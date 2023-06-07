#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

// https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1

class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    // code here
        
        // step 1 : create a adjacency list

        vector<int> adj [N] ;
        for(auto x  : prerequisites){
            adj[x.second].push_back(x.first) ;
        }

        // step 2: create indegree wala array
        int indegree [N] = {0};
        for(int i =0 ; i < N ; i++){
            for(auto x : adj[i]){
                indegree[x]++ ;
            }
        }

        // step 3 : push those nodes with 0 indegree in the queue
        queue<int> q ;
        for(int i = 0 ; i < N ; i++){
            if(indegree[i] == 0){q.push(i) ;}
        }

        // step 4: apply kaan's algo
        vector<int> topo ;
        while(!q.empty()){
            int node = q.front() ; q.pop() ; topo.push_back(node) ;
            for(auto x : adj[node]){indegree[x] -- ; if(indegree[x] ==0){q.push(x) ;}}
        }

        return (topo.size() == N) ;

	}
};