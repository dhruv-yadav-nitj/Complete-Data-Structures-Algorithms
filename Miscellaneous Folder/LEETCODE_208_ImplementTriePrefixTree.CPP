/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

struct Node{
    Node* links[26] ; bool flag = false ; // a trie node contains these two items by default
    bool containsKey(char key){
        return (links[key - 'a'] != NULL) ; // agar links[key - 'a] == NULL hain yaani ki wo exist nhi krta aur iska not true hain means wo exist krta hain --> to whi likha hain
    }
    void put(char ch , Node* node){
        links[ch -'a'] = node ;
    }
    Node *get(char ch){
        return links[ch - 'a'] ;
    }
    void setEnd(){
        flag = true ;
    }
    bool isEnd(){
        return flag ;
    }
};


// we have to basically implement the following functions

class Trie{
private:
    Node* root ; // whenever a trie is called it would first have a root
public:
    Trie(){
        root = new Node() ;
    }

    void insert(string word){
        Node* node = root ;
        for(int i=0; i < word.length() ; i++){
            if(!node -> containsKey(word[i])){
                // is node does not contains the key
                node -> put(word[i] , new Node()) ;
            }

            // move to the reference trie
            node = node -> get(word[i]) ;
        }
        
        // once the for loop gets completed --> we are standing at the last node of the trie --> so we need to mark the flag for this trie as true --> which means the word is completed
        node -> setEnd() ;
    }

    bool search(string word){
        Node* node = root ;
        for(int i=0 ;i < word.length() ; i++){
            if(node -> containsKey(word[i])){
                // agar to ye char exist krta hain then move to reference trie
                node = node -> get(word[i]) ;
            }
            else{return false ;} // agar ye char exist nhi krta then return false
        }
        // agar pura word hi exist krta hain but ye bhi ho skta hain ki ye jo word hain wo kisi aur word ka subsequence ya prefix bhi ho --> check for it
        return node -> isEnd() ;
    }

    bool startsWith(string prefix){
        // similar to search --> just we have to return true when the for loop ends
        Node* node = root ;
        for(int i=0; i < prefix.length() ; i++){
            if(node -> containsKey(prefix[i])){
                node = node -> get(prefix[i]) ;
            }
            else{return false;}
        }
        return true ;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
