#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

class TrieNode{
public:
    char data ; TrieNode* children[26] ; bool isTerminal ;
    int childCount ;

    TrieNode(char key){
        data = key ;
        for(int i = 0 ; i < 26; i++){
            children[i] = NULL ;
        }
        isTerminal= false ; childCount = 0 ;
    }
};

class Trie{
public:
    TrieNode* root ;
    Trie(){
        root = new TrieNode('\0') ;
    }

    void doInsert(TrieNode* root , string word){
        // base condition
        if(word.length() == 0){
            root ->isTerminal = true ;
            return ;
        }

        TrieNode* child ;

        if(root -> children[word[0] - 'a'] != NULL){
            // means ye letter phle se tha 
            child = root -> children[word[0] - 'a'] ;
        }
        else{
            root -> childCount++ ;
            child = new TrieNode(word[0]) ;
            root -> children[word[0] - 'a'] = child ;
        }

        doInsert(child , word.substr(1)) ;
    }

    void insert(string word){
        doInsert(root, word) ;
    }

    // main-function
    string findLCP(string word){
        // main-function-for-this-problem

        string ans = "" ; TrieNode* curr = root ;

        for(int i =0 ; i < word.length() ; i++){
            char ch = word[i] ;

            if(curr -> childCount > 1 or curr -> isTerminal){
                break ;
            }
            else{
                ans += ch ; curr = curr -> children[ch - 'a'] ;
            }
        }

        return ans ;

    }
};

class Solution{
public:
    string longestCommonPrefix(vector<string>& strs){
        // code here

        Trie trie ;
        for(auto &&i: strs){
            trie.insert(i) ;
        }

        return trie.findLCP(strs[0]) ;
    }
};