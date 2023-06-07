#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

class DisjointSet {

public:
    vector<int> rank , parent , size ;
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

    int node_size(int u){
        return size[findPar(u)] ;
    }
};

// proud to remind you that this ques was done by myself without any help --> though at last I did a small mistake so took some help from striver's article

class Solution {
  public:
    bool isValid (int n , int  m , int i , int j){
        return (i >= 0 and i < n and j >= 0 and j < m) ;
    }

    int MaxConnection(vector<vector<int>>& grid) {
        // code here

        int maxi = 0 ;
        int n = grid.size(), m = n ; DisjointSet ds(n*m) ;

        // single_parameter_address = (curr row * total col) + curr col

        // visiting neighbours
        int row_changes[] = {-1 , 0 , 1, 0} , col_changes[] = {0 ,1, 0, -1} ;

        // step 1: connect existing islands using union_by_size

        for(int i =0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1){
                    int address = i*m + j ;
                    for(int k =0 ; k < 4 ; k++){
                        int new_row = i + row_changes[k] , new_col = j + col_changes[k] ;
                        int new_address = (new_row * m) + new_col ;
                        if(isValid(n , m , new_row , new_col) and grid[new_row][new_col] ==1 and ds.findPar(address) != ds.findPar(new_address)){
                            ds.union_by_size(address , new_address) ;
                        }
                    }

                }
            }
        }

        // step 2 : 

        for(int i=0; i < n ; i++){
            for(int j = 0 ; j < m; j++){

                if(grid[i][j] == 0) {

                    int count =0 ;
                    unordered_set <int> s ;
                    for(int k = 0 ; k< 4 ; k++){
                        int new_row = i + row_changes[k] , new_col = j + col_changes[k] ;
                        if(isValid(n , m , new_row , new_col) and grid[new_row][new_col] == 1){

                            int new_cell_address = (new_row * m) + new_col ;
                            s.insert(ds.findPar(new_cell_address)) ;

                        }
                    }
                    
                    for(auto it: s){
                        count += ds.size[it] ;
                    }

                    maxi = max(maxi, count + 1) ;
                }
            }
        }

        for(int i=0 ; i < n*m ; i++){
            maxi= max(maxi , ds.size[ds.findPar(i)]) ;
        }

        return maxi ;

    }
};