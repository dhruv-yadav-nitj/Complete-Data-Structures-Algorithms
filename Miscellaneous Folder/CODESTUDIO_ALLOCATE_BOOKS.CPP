#include <bits/stdc++.h>
#define l long long
#define vl vector<long long> 
#define vi vector<int> 
#define v2 vector<vector<int>> 
#define loop(i, low, high) for(int i= low; i < high;i++) 
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

// function to check if we could either distribute the mid pages to a single person or not
bool isPossible(vector<int> time, l mid , int n){
    // n is the number of day
    l done(0), count(1) ;
    for(int i =0 ; i < time.size() ; i++){
        if(done + time[i] <= mid){
            done = done + time[i] ;
        }
        else{
            count++ ;
            if(count > n or time[i] > mid){
                return false;
            }
            done  = time[i] ;
        }
    }
    return true ;
}

long long ayushGivesNinjatest(int n, int m, vector<int> time){
    
    // so we have to distribute m chapter with time[i] lenghts over n days
    l low(0), high ;
    for (auto &&i : time){high += i ;}
    
    l ans(-1) ;
    while(low <= high){
        l mid = low + (high-low)/2 ;
        if(isPossible(time, mid, n)){
            ans = mid ;
            high = mid-1 ;
        }
        else{
            low = mid+1 ;
        }
    }
    return ans ;
}