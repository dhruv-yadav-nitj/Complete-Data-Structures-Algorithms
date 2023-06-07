// https://leetcode.com/problems/check-if-it-is-a-straight-line/description/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {

        int x1= coordinates[0][0] , y1 = coordinates[0][1] ; int x2 = coordinates[1][0] , y2 = coordinates[1][1] ;
        // assume the first two points as reference points --> baaki saarien points ka slope in do points k saath nikaal kr compare kr denge --> aise hme sort krne ka bhi jroorat nhi pdhega points ko

        for(int i=2 ; i < coordinates.size() ; i++){

            int x3=  coordinates[i][0], y3 = coordinates[i][1] ;

            // instead of division we can actually cross multiply the comparing equations
            if((y3-y2)*(x3-x1) != (y3-y1)*(x3-x2)){return false ;}
        }

        return true ;
        
    }
};