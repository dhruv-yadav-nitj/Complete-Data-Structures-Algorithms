// If we are able to colour a graph with two colours such that no adjacent nodes have the same colour, it is called a bipartite graph.
// https://practice.geeksforgeeks.org/problems/bipartite-graph/1
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

// very simple ques
// approach : bfs traversal kro --> phla node ko color '0' de do baaki adjacent nodes jo abhi tk visit nhi hue hain unko 1 de do --> but agar koi node hain jo already visited hain uska color check kr lo --> agar uska color , node k color s same hain then return false
// here isColored arr would do the work for isVisited as well

class Solution {
public:
	bool isBipartite(int V, vector<int>adj[]){
        // Code here
        
        int isColored[V] ;
        for(int i=0; i < V ;i++){isColored[i] = -1 ;} // isColored[V] = {-1} ; did not worked
        // we would be using 0 and 1 for colors

        for(int i =0 ;i  < V ;i++){

            // if not colored then do bfs --> for loop because the given graph may exist in various sub graphs
            if(isColored[i] == -1){
                
                // lets try bfs
                queue<int> q ; q.push(i) ; isColored[i] = 0 ;
                while(!q.empty()){
                    int node_val = q.front() ; q.pop() ; int node_color = isColored[node_val] ;
                    // cout << "color " << node_color << endl ;
                    for(auto x : adj[node_val]){
                        if(isColored[x] == -1){
                            isColored[x] = !node_color ; q.push(x) ;
                        }
                        else{
                            if(isColored[x] == node_color){return false ;}
                        }
                    }
                }

            }
        }

        return true ;

	}

};