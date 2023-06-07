#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

// time complexity : O(V + E)
// space complexity : O(2N) ~ approx

// approach : instead of using just isVisited arr , we would be using isVisited and isSamePath arr --> isVisited mein 1 store kr denge agar ek baar bhi us element pr visit kr liaa gya hain --> isSamePath ka working thoda different hain --> lectur mein acche smjhaaya tha

class Solution {
  public:
    bool dfs (int node , vector<int> adj[], int isVisited[] , int isSamePath[]){
        // dfs function
        isVisited[node] = 1 ; isSamePath[node] = 1 ;
        for(auto x  : adj[node]){
            if(isVisited[x] and isSamePath[x]){

                return true ; // it would be kind of base case

            }
            else if(!isVisited[x]){
                if(dfs(x, adj, isVisited, isSamePath)){return true ;} // if a node in future returns true --> then return true
            }
        }
        isSamePath[node] = 0 ; return false ;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here

        int isVisited [V] = {0} , isSamePath[V] = {0} ;
        for(int i =0 ; i < V ; i++){
            // apply dfs
            if(!isVisited[i]){
                // apply dfs

                if(dfs(i , adj, isVisited, isSamePath)){return true ;}

            }
        }

        return false ;
    }
};