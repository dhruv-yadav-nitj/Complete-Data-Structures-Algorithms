#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        
        // code here

        // we would be using bfs traversal for this one
        
        // step 1: insert the words of word list in the set to optimise the searching operation which would be used multiple times
        unordered_set<string> s ; for(auto x : wordList){s.insert(x) ;}

        // step 2: insert the startWord in the queue with level as 1 and delete it from set as non-deletion may result in re-occuration in the queue which is useless as it would only increase the time and space
        queue<pair<string, int>> q ; q.push({startWord, 1}) ; s.erase(startWord) ;
        while(!q.empty()){
            string word = q.front().first ; int level = q.front().second ; q.pop() ;
            if(word == targetWord){return level ;}

            // step 3 : change every character of word from a to z and check which one exists in the wordList and insert them in the queue with level + 1 and also delete them from the wordList to avoid re-occurence of the same word further
            for(int i= 0 ; i < word.length() ; i++){
                string temp = word ;
                for(char j = 'a' ; j <= 'z' ; j++){
                    temp[i] = j ;
                    if(s.count(temp)== 1){
                            // agar hme phle hi mil gya hain targetWord then why to insert it in queue yhi se return krwa do uska level
                        if(temp == targetWord){return level + 1 ;}
                        q.push({temp , level+1}) ; s.erase(temp) ;
                    }
                }
            }

        }

        return 0 ;

    }
};