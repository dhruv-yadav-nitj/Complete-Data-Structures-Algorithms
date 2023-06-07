#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

int main () {

    // code here

    int n , m ; cin >> n >> m ;
    // n is the number of nodes u can say (or the largest value to be stored) and m is the number of edges
    int adj [n+1][m+1] ; // here we are taking 1-indexed based graph --> so we need n+1 and m+1 since the matrix would start from 0
    // n is the max possible value of node and m is the edges (matrix is n+1 x m+1 bcz a single node can be connected to max of m nodes)
    for(int i =0; i < m ; i++){

        // we would be taking inputs that many times as the number of edges
        int u , v ; cin >> u >> v ; // u and v are two nodes

        adj[u][v] = 1 ; adj[v][u] = 1 ;
        // since the graph is undirected --> both the sides would be accessible
    }
}

// for weighted graphs --> what are we doing here adj[u][v] = 1 , we would be doing adj[u][v] = weight of edge b/w u and v