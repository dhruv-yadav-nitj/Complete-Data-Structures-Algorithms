// we have not used the queue directly but we have used the concepts of queue

// this is the most improved solution of this problem : one another solution is to check consider each point as starting point and travel the whole array which would make the solution in time complexity: O(n2)

#include <bits/stdc++.h>
using namespace std ;

struct petrolPump
{
    int petrol;
    int distance;
};

/*You are required to complete this method*/
class Solution{
public:
    int tour(petrolPump p[],int n){
        int deficit=0, capacity = 0 , start =0 ;
        for(int i=0 ; i< n; i++){
            capacity = capacity + (p[i].petrol - p[i].distance) ;
            if(capacity < 0){
                deficit += capacity ; capacity = 0 ;
                start = i+1 ;
            }
        }
        if(deficit + capacity >= 0 and start < n){
            return start ;
        }
        else{return -1 ;}
    }
};