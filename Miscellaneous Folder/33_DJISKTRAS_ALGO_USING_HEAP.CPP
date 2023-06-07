#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

// https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

// very simple approach
// Time Complexity : O(ElogV)
// djikstra's algo is a popular algorithm used to find the shortest path distance between between nodes in a graph


class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S){
        // Code here

        vector<int> distance (V, 1e9) ; int source = S ;
        priority_queue<pair<int, int> , vector<pair<int, int>> , greater<pair<int, int>> > pq ;

        pq.push({0 , source}) ; // pair <distance , node>
        distance[source] = 0 ;
        while(!pq.empty()){

            int dis = pq.top().first , node = pq.top().second ;  pq.pop() ;

            for(auto x : adj[node]){
                int val = x[0] , weight = x[1] ;
                if(distance[node] + weight < distance[val]){
                    int new_distance = distance[node]+ weight ;
                    distance[val] = new_distance ; pq.push({new_distance , val}) ;

                }
            }
        }   
        return distance ;

    }
};