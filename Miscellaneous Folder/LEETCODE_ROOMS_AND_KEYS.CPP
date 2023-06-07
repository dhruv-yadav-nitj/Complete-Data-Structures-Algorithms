#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms){
        map<int, bool> m ; bool unlocked = true;
        m[0] = true; // since room 0th is unlocked
        while(unlocked){
            unlocked = false;
            for(int i =0; i< rooms.size(); i++){
                // if room is unlocked get into it
                if(m[i]){
                    for(int j = 0; j< rooms[i].size() ; j++){
                        if(m[rooms[i][j]] == false){ // if we found key to a room which is locked, then make unlocked true so that we can again get into the loop
                            m[rooms[i][j]] = true;
                            unlocked = true;
                        }
                    }
                }
            }
        }
        for(int i=0; i< rooms.size() ; i++){
            if(m[i] == false){return false;}
        }
        return true;
    }
};