#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

// done this ques earlier using dfs and now we would do this ques using bfs

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here

        // step 1 : reverse the directions of the edges --> we would not actually reverse the edges , but observe that no. of outdegree in prev graph would be equal to no. of indegree for a node in the new graph
        int indegree[V] ;
        for(int i = 0 ; i < V ; i++){
            indegree[i] = adj[i].size() ;
        }

        // step 2 : make a queue and insert all the elements with 0 indegree in the queue
        queue<int> q ;
        for(int i = 0; i < V ; i++){if(indegree[i] == 0) {
            q.push(i) ;
        }}

        // step 3: apply the topo sort or kans algo
        vector<int> topo ;
        while(!q.empty()){
            int node = q.front() ; q.pop() ; topo.push_back(node) ;
            for(int i =0; i < V ; i++){
                for(auto x : adj[i]){
                    if(x == node){
                        indegree[i]-- ; if(indegree[i] == 0){
                            q.push(i);
                        }
                    }
                }
            }
        }

        sort(topo.begin() , topo.end()) ; return topo ;
    }

    // we can optimise the time complexity of above program by making a seperate modified adjacency list
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
		vector<int> adjRev[V];
		int indegree[V] = {0};
		for (int i = 0; i < V; i++) {
			// i -> it
			// it -> i
			for (auto it : adj[i]) {
				adjRev[it].push_back(i);
				indegree[i]++;
			}
		}
		queue<int> q;
		vector<int> safeNodes;
		for (int i = 0; i < V; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}

		while (!q.empty()) {
			int node = q.front();
			q.pop();
			safeNodes.push_back(node);
			for (auto it : adjRev[node]) {
				indegree[it]--;
				if (indegree[it] == 0) q.push(it);
			}
		}

		sort(safeNodes.begin(), safeNodes.end());
		return safeNodes;
	}
};