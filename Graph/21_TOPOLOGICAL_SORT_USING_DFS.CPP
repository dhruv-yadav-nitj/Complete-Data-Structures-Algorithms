#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

// The main motive behind topological sorting is to find a valid order of tasks that need to be performed in a project or a process, where certain tasks must be completed before others can begin.

// Topological Sort can be done in number of ways having different order of elements --> below method presents one of those ways

class Solution
{
	public:
    void dfs (int node , vector<int> adj[] , stack<int> &s, int isVisited[]){
        isVisited[node] = 1 ;

        for(auto x : adj[node]){
            if(!isVisited[x]){
                // apply dfs for unvisited adjacencies nodes of the curr node
                dfs(x, adj, s , isVisited) ;
            }
        }
        s.push(node) ;
    }
	
	vector<int> topoSort(int V, vector<int> adj[]) {
	    // code here

        // we need a vector(bcz ans in that format only)  and a stack and a isVisited array
        vector<int> ans ; stack<int> s ; int isVisited[V] = {0} ;

        for(int i =0; i < V ; i++){
            if(!isVisited[i]){
                // apply dfs
                dfs(i , adj , s , isVisited) ;
            }
        }

        while(!s.empty()){
            ans.push_back(s.top()) ; s.pop() ;
        }return ans ;

	}
};