#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

class DisjointSet {

    vector<int> rank , parent , size ;
public:
    DisjointSet (int n) {

        rank.resize(n +1 ,0 );  // size the vector and initialise all the value with 0 --> why n+1 and not n ?? --> because 1-based indexing in the problem
        parent.resize(n +1) ;
        for(int i =0 ; i  < n+1 ; i++){
            parent[i]= i ; // initially every node's parent is the node itself
        }

        // and the size of each node would initially be 1
        size.resize(n +1 , 1) ;
    }

    // find parent function and path compressing
    int findPar (int node){
        if(parent[node] == node){
            return node ;

            // base condition : if the parent of node is the node itself it means that it is the ultimate boss or the ultimate parent --> so in this case we need to return this only

        }

        // since hme ultimate parent se hi matlab hain ye pata krne k lie ki two given nodes are the part of the same component or not then we can do path compressing --> means instead of storing the immediate parent we can store the ultimate parent of a node in the parent array
        parent[node] = findPar(parent[node]) ; // path compressing
        
        return parent[node];
    }

    void union_by_rank (int u , int v ) // arguments of the function union is two nodes which needs to be joined
    {
        int pu = findPar(u) , pv = findPar(v) ;

        // case 1 : if the ultimate parents are same then we need not to do anything
        if(pu == pv){
            return ;
        }

        // case 2 : if the pu is the smaller ranked node
        if(rank[pu] < rank[pv]){
            // connect pu to pv (smaller one gets connected to larger one)
            parent[pu]= pv ;

        }
        else if(rank[pv] < rank[pu]){
            parent[pv]= pu ;
        }
        else{
            // if rank[pu] = rank[pv]
            // in this case we can connect either u to v or v to u
            parent[pu]= pv ; rank[pv] ++ ; // how does rank increase by 1 --> take two example 1->2->3 and 4->5->6 and union them u will understand
        }
    }

    // why do we need disjoint set ? --> to perform this function in constant time
    bool same_component (int u , int v){
        return (findPar(u) == findPar(v)) ;

        // if both have the same ultimate parent then they belong to the same component of the graph else no

    }

    void union_by_size (int u , int v){

        int pu = findPar(u) , pv = findPar(v) ;
        if(size[pu] < size[pv]){
            parent[pu] = pv ; size[pv] += size[pu] ; // would connect the node with smaller size with the node with greater size and would add the sizes
        }

        else{

            // two cases : either size[pv] < size[pu] or size[pv] = size[pu] --> in both the cases we can do the same thing because when equal we can add any node to other one, so why not club both the cases into one condition

            parent[pv]= pu ; size[pu] += size[pv] ;
        }

    }
};

class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here

        vector<int> isVisited (n*m , 0) ; // initially mark all the nodes as unvisited
        
        // formula to convert the matrix cells into single number addresses --> (curr row)*(total col) + (curr col) --> this formula would be used to convert the matrix cells into disjoint set
        DisjointSet ds (n *m -1) ; // total cells --> n *m but due to 0-based indexing --> n*m - 1

        int count =0 ; vector<int> ans ;

        int k = operators.size() ;

        for(auto it : operators){
            int i = it[0] , j = it[1] ; int address = i*m + j ; // address defines the single number addresses used to represent the cells of the matrix
            if(!isVisited[address]) {

                // if the cell is unvisited

                isVisited[address] = 1 ; // firstly mark it as visited
                count++ ; // initially increment in the count --> baad mein dekh lenge
                int row_changes[] = {-1 , 0 , 1, 0} , col_changes[] = {0 , 1 , 0, -1} ;
                for(int k = 0; k < 4 ; k++){
                    int new_address = (i + row_changes[k])*(m) + (j + col_changes[k]) ;

                    if(isValid(n , m , i+row_changes[k] , j + col_changes[k]) and isVisited[new_address]){
                        // if the address to be checked lies under the matrix and is also visited

                        // then check if the current node and the node which is checked have the same parent or not --> if they have same parent then no need to worry but if they have different parents --> then decrease count and also do union

                        if(ds.findPar(address) != ds.findPar(new_address)){

                            count-- ; ds.union_by_size(address, new_address) ;
                        }
                    }
                }
            }
            else{
                // just push the current count into the answer array again
            }

            ans.push_back(count) ;
        }

        return ans ;

    }
    
    bool isValid (int n , int m, int row , int col){
        return (row >= 0 and row < n  and col >= 0 and col < m) ;

    }

};