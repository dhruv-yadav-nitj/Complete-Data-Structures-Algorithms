#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

// https://leetcode.com/problems/word-ladder/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> s ; for(auto x : wordList){s.insert(x) ;}

        queue<pair<string, int>> q ; q.push({beginWord, 1}) ; s.erase(beginWord) ;

        while(!q.empty()){

            string word = q.front().first ; int level = q.front().second ; q.pop() ;

            if(word == endWord){return level;}
            for(int i =0 ; i < word.length() ; i++){
                string temp = word ;
                for(char c = 'a' ; c <= 'z' ; c++){
                    temp[i]= c ;
                    if(s.find(temp) != s.end()){
                        q.push({temp , level + 1}) ; s.erase(temp) ;
                    }
                }
            }
        }

        return 0 ;
        
    }
};