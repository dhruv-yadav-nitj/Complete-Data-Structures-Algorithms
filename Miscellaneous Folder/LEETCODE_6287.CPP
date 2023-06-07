#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass){
        unordered_map<string, bool> m ;
        long long vol = length; vol= vol*width ; vol = vol*height ;
        if(vol >= 1000000000 or length >= 10000 or width >= 10000 or height >= 10000 or mass >= 10000){m["Bulky"] = true ;}
        if(mass >= 100){m["Heavy"] = true ;}
        if(m["Bulky"] and m["Heavy"]){return "Both" ;}
        if(!m["Bulky"] and !m["Heavy"]){return "Neither" ;}
        if(m["Bulky"] and !m["Heavy"]){return "Bulky" ;}
        if(!m["Bulky"] and m["Heavy"]){return "Heavy" ;}
        return "Neither" ;
    }
};