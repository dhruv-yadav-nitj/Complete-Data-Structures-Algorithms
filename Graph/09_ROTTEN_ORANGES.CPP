#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

/* Time Complexity: O(NxM + NxMx4) ~ O(N x M), For the worst case, all of the cells will have fresh oranges, so the BFS function will be called for (N x M) nodes and for every node, we are traversing for 4 neighbours, it will take O(N x M x 4) time.

Space Complexity ~ O(N x M) */

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        // ur fucking code here
        int lambaa = grid.size() , chauda = grid[0].size() ;
        // we need a visited matrix
        vector<vector<int>> is_fucked (lambaa, vector<int>(chauda, 0)) ;
        queue<pair<pair<int, int> , int>> holes ; int stamina =0 ; // queue with pair of indexes and the time

        // step 1 --> insert all the cells with rotten elements in the queue with t = 0 
        for(int lund1 =0 ; lund1 < lambaa ; lund1++){
            for(int lund2 = 0 ; lund2 < grid[lund1].size() ; lund2++){
                if(grid[lund1][lund2] == 2){
                    holes.push({{lund1, lund2} , 0}) ; is_fucked[lund1][lund2] = 1 ;
                }
            }
        }

        // step2 --> simply traverse using bfs
        while(!holes.empty()){
            auto vagina = holes.front() ; holes.pop() ;
            int hole_horizontal = vagina.first.first , hole_vertical = vagina.first.second ; int time = vagina.second ; stamina = max(stamina, time) ;

            
            
            // checking for the adjacent virgins
            int condoms1[] = {-1, 0 , 1, 0} , condoms2[] = {0, 1, 0, -1} ;
            for(int i = 0 ; i < 4 ; i++){
                int pos1 = hole_horizontal + condoms1[i] , pos2 = hole_vertical + condoms2[i] ;
                if(pos1 >= 0 and pos1 < lambaa  and pos2 >= 0 and pos2 < chauda  and grid[pos1][pos2] == 1 and !is_fucked[pos1][pos2]){
                    holes.push({{pos1, pos2}, time+1}) ; is_fucked[pos1][pos2] = 1 ; grid[pos1][pos2] = 2 ;
                    // is line mein hme queue mein push krna hain + visited mark krna hain + us orange ko rotten bhi krna hain 
                }
            }
            
        }

        for(int i = 0 ; i < lambaa ; i++){
            for(int j = 0 ; j < chauda ; j++){
                if(grid[i][j] == 1){
                    return -1 ;
                }
            }
        }

        return stamina ;

    }
};