// https://www.codingninjas.com/codestudio/problems/complete-string_2687860
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

struct Node{
    Node* links[26] ; bool flag = false ;

    bool containsKey(char key){
        return links[key - 'a'] != NULL ; // agar NULL k equal nhi hain to hi mtlb hain ki haan wo cheej exist krta hain
    }

    Node* get(char key){
        return links[key - 'a'] ;
    }

    void put(char key, Node* node){
        links[key - 'a'] = node ;
    }

    void setEnd(){flag = true ;}

    bool isEnd(){return flag ;}

    // above things are what a standard trie contains --> now below things are specific for this problem
};

class Trie{
    Node* root ;
public:
    Trie(){
        root = new Node() ;
    }

    void insert(string word){
        Node* node = root ;
        for(int i= 0; i < word.length() ; i++){
            if(!node -> containsKey(word[i])){
                node -> put(word[i], new Node());
            }
            node = node -> get(word[i]) ;
        }

        node -> setEnd() ; // this marks the end of a word
    }

    bool isComplete(string word){
        Node* node = root ;
        for(int i=0; i < word.length() ; i++){
            if(node -> containsKey(word[i])){
                node = node -> get(word[i]) ;
                if(!node -> isEnd()){return false ;}
            }
            else{return false ;}
        }
        return true ;
    }
};

string completeString(int n, vector<string> &a){
    // Write your code here.
    Trie trie ; // creating a trie
    for(auto &&i : a){ // inserting all the word in the trie
        trie.insert(i) ;
    }

    // so now we have inserted all the words in the trie
    string ans = "";
    for(auto &&i : a){

        // function to check if all the prefix exist --> if all the prefix exists in the trie then it is one of the possible answers

        if(trie.isComplete(i)){

            // now we can check if i is longer than existing ans
            if(i.length() > ans.length()){
                ans = i ;
            }
            else if(i.length() == ans.length() and i < ans){
                ans = i ;
                // this condition counters the possibility that two strings can have same length but the curr is lexcographically smaller
            }
        }
    }
    if(ans == ""){return "None" ;}
    return ans ;
}