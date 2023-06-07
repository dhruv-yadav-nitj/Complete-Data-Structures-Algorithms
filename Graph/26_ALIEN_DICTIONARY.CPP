#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        //code here

        // we need an adjacency list
        vector<int> adj[K] ;

        for(int i =0 ; i < N-1 ; i++){
            string s1 = dict[i] , s2 = dict[i+1];
            int j =0 ;
            while(j < s1.length() and j < s2.length()){
                if(s1[j] != s2[j]){
                    adj[s1[j]- 'a'].push_back(s2[j]- 'a') ; break ;
                }
            }
        }

        // now we have an adjacency list --> time to make up a indegree array
        int indegree[K] = {0} ;
        for(int i =0 ;i < K ; i++){
            for(auto x : adj[i]){
                indegree[x]++ ;
            }
        }

        // now apply topo sort algorithm
        queue<int> q ;
        for(int i=0 ; i < K  ;i++){
            if(indegree[i] == 0){q.push(i) ;}
        }

        string ans = "" ;

        while(!q.empty()){
            int node = q.front() ; q.pop() ; ans += (node + 'a') ;

            for(auto x : adj[node]){
                indegree[x]-- ;
                if(indegree[x] ==0) {q.push(x) ;}
            }
        }return ans ;

    }
};

// follow up questions:

// this ques has some exceptional test cases : (jo maine socha bhi tha aur last mein striver ne apne vdo mein uska explanation bhi de rkha hain) --> suppose we have such a test case : s1 = abcd and s2 = abc <-- aise mein to hmara code work hi nhi krega aur is case mein order possible bhi nahi hain, because we dont have conclusive information
// also order is not possible in cases which form a cyclic type structure like : abc, bat , ade

// in those cases dictionary is wrong