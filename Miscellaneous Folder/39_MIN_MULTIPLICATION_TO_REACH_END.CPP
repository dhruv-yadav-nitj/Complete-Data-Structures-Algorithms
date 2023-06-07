#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

// very very easy easy problem --> apply simple djisktra's algo --> just think when it should end --> it should end when either the queue is empty or we are not getting any new minimum steps to reach a number (that we would know using the distance array)


// Time Complexity : O(1e5 * arr.size()) <-- worst worst case complexity (not possible though)
// Space Complexity : O(1e5 * arr.size()) almost

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here

        // what we need --> a queue and a distance array
        queue<pair<int, int>> q ; vector<int> distance (1e5 , 1e9) ;
        // <steps, node_value>

        q.push(make_pair(0, start)) ; // initially we would insert start with 0 steps

        distance[start] = 0 ;

        while(!q.empty()){

            int step = q.front().first , curr = q.front().second ; q.pop() ;

            if(curr == end){
                return step ;
            }


            for(int i =0 ; i < arr.size() ; i++){

                int temp = (curr * arr[i])%100000 ;

                if(step + 1 < distance[temp]){

                    distance[temp]= step + 1 ; q.push({step+1 , temp}) ;

                }
            }

        }

        return -1 ;

    }
};