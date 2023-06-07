#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

int main  ()  {
    
    // lists -representation

    int n , m ; cin >> n  >> m ;
    vector<int> adj [n+1] ; // we would be having an array with each element of data type vector<int> and the size would be obviously n +1 (1-based indexing) --> where we would be storing the neighbours of each node wrt the node value

    for(int i =0; i < m ; i++){

        int u , v ; cin >> u >> v ;
        // undirected graph
        adj[u].push_back(v) ; adj[v].push_back(u) ;
    }

    for(int i =0; i < n +1 ; i++){
        cout << i << " --> " ;
        for(int j=0 ; j < adj[i].size() ; j++){
            cout << adj[i][j] << " " ;
        }cout << endl ;
    }
}

// this method is more space efficient than the matrix representation --> bcz in matrix we would have to make n*m matrix --> bcz we have to store 0 or 1 (based on a node is neighbour to other node or not)
// but here we have to store only those nodes which are connected (neighbour) to a particular node

// in this representation : space complexity: O(2 * edges) <-- in undirected graph and O(edges) <-- in directed graph

// for weighted graph : we would be creating something vector<pair<int, int>> adj[n+1] 