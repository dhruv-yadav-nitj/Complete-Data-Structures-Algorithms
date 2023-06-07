#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

struct Node{
    Node* links[26] ;
    bool flag = false ; // ye start mein false hoga --> ye true hain iska mtlb ye ek word k end ko show kr rha

    bool containsKey(char key){
        return (links[key - 'a'] != NULL) ; // agar hme ye check krna hain ki koi char is word mein exist krta hain ya nahi to hm uska links check krenge ki kahi wo NULL k equal to nhi
    }

    void put(char ch, Node* node){
        links[ch - 'a'] = node ;
    }

    Node* get(char ch){
        return links[ch - 'a'] ;
    }

    void setEnd(){ // marks this node as the end of the word
        flag= true ;
    }

    bool isEnd(){ // checks whether this particular node is the end of the word or not
        return flag ;
    }
};

class Trie{
private:
    Node* root ; // since trie bhi ek tree hain so start to hmesa root se hoga
public:
    Trie(){ // constructor
        root = new Node() ;
    }

    void insert(string word){
        Node* node = root ;
        for(int i=0; i < word.length() ; i++){
            if(!node -> containsKey(word[i])){
                // agar ye key exist nhi krta then isko daal do
                node -> put(word[i], new Node()) ;
            }

            // move to the next reference in trie
            node = node -> get(word[i]) ;
        }

        // word khtm ho gya then mark the end
        node -> setEnd();
    }

    bool search(string word){
        Node* node = root ;
        for(int i=0 ; i < word.length() ; i++){
            if(node -> containsKey(word[i])){
                node = node -> get(word[i]) ;
            }
            else{return false ;}
        }
        // mtlb pura word exist krta hain --> but aisa bhi ho skta hain ki ye prefix ho kisi aur word ka
        return node -> isEnd() ;
    }

    bool startsWith(string prefix){
        Node* node = root ;
        for(int i=0 ; i < prefix.length() ; i++){
            if(node -> containsKey(prefix[i])){
                node = node -> get(prefix[i]) ;
            }
            else{return false ;}
        }
        // mtlb pura word exist krta hain --> but aisa bhi ho skta hain ki ye prefix ho kisi aur word ka
        return true ;
    }
};