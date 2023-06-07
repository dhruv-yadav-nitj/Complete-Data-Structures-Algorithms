#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // based on Next Smaller Element see Vs Code
        vector<int> ans(temperatures.size(), 0) ;
        stack<pair<int, int>> s;
        for(int i=0; i< temperatures.size(); i++){
            if(s.empty()){
                s.push(make_pair(temperatures[i], i)) ;
            }
            else{
                while(!s.empty() and s.top().first < temperatures[i]){
                    ans[s.top().second] = i - s.top().second ;
                    s.pop() ;
                }
                s.push(make_pair(temperatures[i] , i)) ;
            }
        }return ans;
    }
};