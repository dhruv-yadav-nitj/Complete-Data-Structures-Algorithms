#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

class Solution {
  public:
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here

        int inDegree [V] = {0};
        for(int i =0;  i < V ;i++){
            for(auto x : adj[i]){
                inDegree[x]++ ;
            }
        }

        // now we have indegree wla array
        vector<int> topo ; queue<int> q ;
        for(int i =0; i < V ; i++){
            if(inDegree[i] == 0){q.push(i) ;}
        } // q mein hmare paas wo elements aa gye hain jinki indegree 0 rha hoga

        while(!q.empty()){
            int node = q.front() ; q.pop() ; topo.push_back(node) ;
            for(auto x : adj[node]){
                inDegree[x]-- ;
                if(inDegree[x] == 0){q.push(x) ;}
            }
        }

        // agar topo ka size V k equal hain means graph is a DAG but if not then graph mein cycle present hain 
        return (topo.size() != V) ;

    }
};