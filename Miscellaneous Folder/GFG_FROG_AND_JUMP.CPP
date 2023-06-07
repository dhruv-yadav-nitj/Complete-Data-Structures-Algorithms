#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

class Solution {
  public:
    int unvisitedLeaves(int N, int leaves, int frogs[]) {
        // Code here
        bool isVisited[100001] ;
        memset(isVisited , false ,sizeof(isVisited));

        for(int i =0 ; i< N ; i++){

            int num = frogs[i] ; if(num == 1){return 0 ;}
            if(!isVisited[num]){
                for(int j = num ; j <= leaves ; j = j + num){
                   isVisited[j] = true ;
                }
            }
        }
int count(0) ;
        for(int i =1 ; i <= leaves ; i++){
            if(!isVisited[i]){count++ ;}
        }
        return count ;

    }
};