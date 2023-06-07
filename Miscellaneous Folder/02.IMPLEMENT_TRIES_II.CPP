#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

// https://takeuforward.org/data-structure/implement-trie-ii/
// see this article for better understanding and visualization of the tries

struct Node{
    Node* links[26] ;
    int countEndsWith = 0 , countPrefix = 0 ;

    bool containsKey(char key){
        return (links[key - 'a'] != NULL) ;
    }

    Node* get(char key){return links[key - 'a'] ;}

    void put(char ch, Node* node){
        links[ch - 'a'] = node ;
    }

    void increaseEndsWith(){countEndsWith++ ;}

    void increasePrefix(){countPrefix++ ;}

    void deletePref(){countPrefix-- ;}

    void deleteEnd(){
        countEndsWith-- ;
    }

    int getEnd(){
        return countEndsWith ;
    }

    int getPrefix(){
        return countPrefix ;
    }
};

class Trie{
    
    Node* root ;

    public:

    Trie(){
        // Write your code here.
        root = new Node() ;
    }

    void insert(string &word){
        // Write your code here.
        Node* node = root ;
        for(int i=0; i < word.length() ; i++){
            if(!node -> containsKey(word[i])){
                // agar nhi hain to daalna pdhega
                node -> put(word[i], new Node()) ;
            }
            node = node -> get(word[i]) ; // and ye line aage bdhane k lie hain

            node -> increasePrefix() ;
        }

        // since the word is completed
        node -> increaseEndsWith() ;
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        Node* node = root ;
        for(int i=0; i< word.length() ; i++){
            if(node -> containsKey(word[i])){
                node = node -> get(word[i]) ;
            }
            else{return 0 ;}
        }
        return node -> getEnd() ;
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        Node* node = root ;
        for(int i=0; i< word.length() ; i++){
            if(node -> containsKey(word[i])){
                node = node -> get(word[i]) ;
            }
            else{return 0 ;}
        }
        return node -> getPrefix() ;
    }

    void erase(string &word){
        // Write your code here.

        Node* node = root ;
        for(int i= 0; i< word.length() ; i++){
            if(node -> containsKey(word[i])){
                node =node -> get(word[i]) ;
                node -> deletePref() ;
            }
            else{return ;}
        }

        node -> deleteEnd() ;
    }
};
