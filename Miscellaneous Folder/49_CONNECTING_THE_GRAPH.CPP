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
    int Solve(int n, vector<vector<int>>& edge) {
        // code here

        // step 1 : make a disjoint set and apply union b/w all the nodes given in the edges and if we are trying to connect two nodes having same ultimate parent then we dont connect them instead we would increase the count (which is denoting how many extra edges do we have)
        DisjointSet ds (n) ; int count = 0 ;
        for(auto it : edge){
            int u = it[0] , v= it[1] ;
            if(ds.findPar(u) == ds.findPar(v)){
              count++ ;
            }else{
              ds.union_by_size(u, v) ;
            }
        }

        // step 2 : count those nodes whose parent are the nodes itself
        int temp=0;
        for(int i =0 ; i < n ; i++){
          if(ds.findPar(i) == i){
            temp++ ;
          }
        }

        --temp ; // because in process of counting the independent nodes , it would also count that node which we are trying to make the ultimate parent of all the other nodes --> for ex. if we are tring to connect all the nodes to 0 --> it would also count 0 as in temp --> so we need to subtract that

        if(temp <= count){
          return temp ;
        }else{
          return -1 ;
        }

        return -1 ;

    }
};