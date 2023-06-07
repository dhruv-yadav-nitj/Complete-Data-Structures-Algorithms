#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> ans(prices.size()) ; ans = prices; // we did this taaki hme last mein bache hue elements ka price alag se initialise krne ki jroorat hi na pdhe.. jo prices pr discount mil rha hoga hm bs unko change kr denge baaki as it is rh jaaenge
        stack<pair<int, int>> s ;
        for(int i=0; i< prices.size() ; i++){
            if(s.empty()){
                s.push({prices[i] , i}) ;
            }
            else{
                while(!s.empty()  and s.top().first >= prices[i]){
                    ans[s.top().second] = (s.top().first - prices[i]) ;
                    s.pop() ;
                }
                s.push({prices[i] , i}) ;
            }
        }return ans;

    }
};