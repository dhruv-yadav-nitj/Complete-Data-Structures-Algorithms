#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // two maps we would make one would store a particular person knows which which person and other one would store that a particular persone is known by how many person
        map<int, bool> m1; map<int, int> m2 ;
        for(int i=1; i<= n; i++){m1[i] = true ;}
        for(int i=0; i< trust.size() ; i++){
            m1[trust[i][0]] = false;
            m2[trust[i][1]]++ ;
        }
        for (auto &&i : m1){
            if(i.second == true){
                if(m2[i.first] == n-1){
                    return i.first ;
                }
            }
        }
        return -1 ;
        
    }
};