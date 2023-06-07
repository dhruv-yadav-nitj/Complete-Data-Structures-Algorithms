#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int captureForts(vector<int>& forts){
        int ans(0) ;
        for(int i=0; i< forts.size() -1 ;i++){
            if(forts[i] == 1 or forts[i] == -1){
                int count(0); int j = i+1 ;
                while(j < forts.size() and forts[j] == 0){
                    count++ ; j++ ;
                }
                if(j < forts.size() and forts[i]*forts[j] < 0){ans = max(ans, count) ;}
            }
        }
        return ans ;
    }
};