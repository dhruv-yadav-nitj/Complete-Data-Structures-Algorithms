#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        // code here
        
        unordered_set<string> s ; for(auto x : wordList){s.insert(x) ;}

        vector<vector<string>> ans ; vector<string> usedOnLevel ;

        queue<vector<string>> q ;int level = 0 ;
        q.push({beginWord}) ; usedOnLevel.push_back(beginWord) ;

        while(!q.empty()){

            vector<string> curr= q.front() ; q.pop() ;
            
            if(curr.size() > level){
                level++ ;
                for(auto x : usedOnLevel){
                    s.erase(x) ;
                }
            }

            string recentWord = curr.back() ;

            if(recentWord == endWord){
                if(ans.size() == 0){
                    ans.push_back(curr) ;
                }
                else if(curr.size() == ans[0].size()){
                    ans.push_back(curr) ;
                }
                else{
                    return ans ;
                }
            }

            for(int i =0 ; i < recentWord.length() ; i++){
                string temp = recentWord ;
                for(char j = 'a' ; j <= 'z' ; j++){
                    temp[i] = j ;
                    if(s.count(temp)== 1){
                        curr.push_back(temp) ; 
                        q.push(curr) ; usedOnLevel.push_back(temp) ;curr.pop_back() ;
                    }
                }
            }

        }

        return ans ;


    }
};