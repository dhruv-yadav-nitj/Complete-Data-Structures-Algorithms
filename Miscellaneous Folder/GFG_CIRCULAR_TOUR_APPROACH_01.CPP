#include <bits/stdc++.h>
using namespace std ;

struct petrolPump
{
    int petrol;
    int distance;
};

class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
        // approach 1: brute force --> checking each point as starting point
        // first we would find a petrol pump from where we can start i.e., this petrol pump should be having petrol[i] >= distance[i]
        int start ; bool flag=false;
        for(int i=0; i< n; i++){
            if(p[i].petrol >= p[i].distance){
                start = i ; flag = true ; break ;
            }
        }
        if(!flag){return -1 ;} // agar hme ek bhi valid starting point nhi mila to yhi return -1 kr do

        // so we have a potential answer as start
        // so chuki ye ek possible answer ho skta hain . but nhi bhi ho skta hain us case mein hme start ko shift krna pdhega
        while(start < n){
            int curr = p[start].petrol - p[start].distance ; int end = (start+1)%n ;
            while(curr >= 0 and end != start){
                curr = curr + (p[end].petrol - p[end].distance) ;
                end = (end+1)%n ;
            }
            if(end == start){return start ;}
            else{
                // we need to find next valid start
                start = start+1 ;
                if(start < n){
                    return -1 ;
                }
                else{
                    for(int i= start ; i< n; i++){
                        if(p[i].petrol >= p[i].distance){
                            start = i ; break ;
                        }
                    }
                }
            }
        }
        return -1 ;
    }
};

// this code giving wrong answer