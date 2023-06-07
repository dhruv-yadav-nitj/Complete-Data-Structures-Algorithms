#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

// Topological Sort presents the nodes of graph in such a way that if there's a directed edge from 'u' to 'v' then 'u' must always come before 'v' in such an order

// Time Complexity : O(V + E)
// Space Complexity : O(V) <-- for indegree array and queue

class Solution
{
	public:
	vector<int> topoSort(int V, vector<int> adj[]) {
	    // code here

        // step 1 : we would be using an array to store the indegree of all the nodes
        int indegree [V] = {0} ;
        for(int i  = 0 ; i < V ; i++){
            for(auto x : adj[i]){
                indegree[x]++ ;
            }
        }

        // step 2 : make a queue and push all the nodes which are having an indegree as zero
        queue<int> q ;
        for(int i =0; i < V ; i++){
            if(indegree[i] == 0){
                q.push(i) ;
            }
        }

        // step 3 : someone would always be there with indegree 0 --> bcz its a DAG --> directed acyclic graph
        vector<int> topo ;
        while(!q.empty()){
            int node = q.front() ; q.pop() ; topo.push_back(node) ;

            for(auto x : adj[node]){
                indegree[x]-- ;
                if(indegree[x] == 0){
                    q.push(x) ;
                }
            }

        }return topo ;

	}
};