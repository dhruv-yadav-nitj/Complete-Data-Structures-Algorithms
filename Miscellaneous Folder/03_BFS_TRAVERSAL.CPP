#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

// } Driver Code Ends
class Solution {
public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        // we are given the number of nodes 'V' and the adjacency list --> in which the neighbouring nodes of each and every node is given

        // pre-requisites : we need an ans vector, a queue, and isVisited arr
        vector<int> ans ; int isVisited[V] = {0}; queue<int> q ;
        q.push(0) ; // since the graph is 0-based indexing, so we pushed 0 first --> that's the reason we have taken isVisited[]  of V size
        isVisited[0] = 1 ; // means we have already visited 0 node
        while(!q.empty()){

            int node = q.front() ; q.pop() ; // 1 means that the node is Visited
            ans.push_back(node) ;

            for(auto x : adj[node]){
                if(!isVisited[x]){
                    q.push(x) ; isVisited[x] = 1 ; // dekh lena ye line bahut important hain
                    // isVisited[x] = 1 yhi pr hona chaie bcz agar isko is for loop se bahar likhoge to ek hi number baar baar queue mein aa jaaega --> consider the example with adj list :
                    // 1 --> {2, 3} , 2 --> {1, 4}, 3 --> {1, 4} and 4 --> {2, 3}
                }
            }
        }

        // Time Complexity : O(Nodes) + O(total Degree) and total degree = 2 * no. of edges
        // Aux Space : O(3 * nodes) approx. O(nodes)

        return ans ;
    }
};