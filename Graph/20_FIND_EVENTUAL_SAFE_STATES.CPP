#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

// approach : any node which is part of a cycle or leads to a cycle cant be a safe node --> so check for those nodes which are such kind of nodes

// this ques is almost same as the cycle detection in directed graph --> only we requir some small tweaks

class Solution {
  public:
    bool dfs (int node , vector<int> adj[] , int isVisited[] , int isSamePath[] , int check[]){
        // cycle detection + check
        isVisited[node] = 1 , isSamePath[node]= 1 , check[node] = 0 ;
        for(auto x : adj[node]){

            // univisited ones
            if(!isVisited[x]){
                // agar cycle detect hua to 
                if(dfs(x, adj, isVisited, isSamePath, check)){
                    check[node] = 0 ; return true ;
                }
            }
            else if(isVisited[x] and isSamePath[x]){
                // means phle se hi visited hain and same path pr hain --> means cycle detect hua hain
                check[node] = 0 ; return true ;
            }
        }

        check[node]= 1 ; isSamePath[node] = 0 ; return false ; // jaate jaate isSamePath pr 0 kr do 
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int> ans ; int isVisited [V] = {0}, isSamePath[V] = {0}, isCheck[V] = {0}; // we need isCheck xtra which stores whether a node is safe node or not --> initially all of them are 0

        for(int i =0 ; i < V ; i++){
            if(!isVisited[i]){
                // apply dfs
                dfs(i , adj, isVisited, isSamePath, isCheck);

            }
        }

        for(int i =0; i < V ;i++){
            if(isCheck[i] == 1){
                ans.push_back(i) ;
            }
        }
        return ans ;

    }
};