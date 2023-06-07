#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

// Kosarajus' Algorithm


class Solution
{
	public:

    void dfs (vector<int>adj[] , int isVisited[] , int node , stack<int> &s){
        isVisited[node] = 1 ;
        for(auto x : adj[node]){
            if(!isVisited[x]){
                dfs(adj , isVisited , x , s) ;
            }
        }

        s.push(node) ;
    }

    void dfs_step3 (vector<int>adj[] , int isVisited[] , int node){
        isVisited[node] = 1 ;
        for(auto x : adj[node]){
            if(!isVisited[x]){
                dfs_step3(adj , isVisited , x) ;
            }
        }
    }

	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj){
        //code here

        // step 1 : make dfs traversal and sort the nodes according to finishing time (nodes which finished earlier would be at last , use stack here)
        // step 2 : reverse the graph
        // step 3 : perform dfs again but this time use reversed graph
        // step 4 : count the no. of different DFS calls to get the no. of SCC


        vector<int> adj_list[V] ;
        for(int i =0 ; i< V ; i++){
            for(auto it: adj[i]){
                adj_list[i].push_back(it) ;
            }
        }


        stack <int> s ; // to store nodes according to finishing time
        int isVisited[V] = {0}; // initially all the nodes are unvisited

        // store nodes according to finishing time
        for(int i =0; i < V ; i++){
            if(!isVisited[i]){

                dfs(adj_list , isVisited , i , s) ;
            }
        }

        // reversing the graph --> what we need to do ? --> if in the given list u -> v then do v -> u in new adj_list
        vector<int> adj_list2[V] ;
        for(int i=0 ; i < V ; i++){
            for(auto x: adj_list[i]){
                adj_list2[x].push_back(i) ;
            }
        }

        // perform dfs on new graph (reversed graph) using the stack and count the number of times dfs has been called
        int isVisited2[V] = {0} ; int count =0 ;

        while(!s.empty()){
            int node = s.top() ; s.pop() ;
            if(!isVisited2[node]){
                count++ ;
                dfs_step3(adj_list2 , isVisited2 , node) ;
            }
        }

        return count ;       

    }
};