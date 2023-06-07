#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

class TrieNode{
public:
    char data ; TrieNode* children[26] ; bool isEndofWord ;

    TrieNode(char key){
        data = key ;
        for(int i = 0 ; i < 26 ; i++){
            children[i] = NULL ;
        }
        isEndofWord = false ;
    }
};

class Trie{
public:
    TrieNode* root ;
    Trie(){
        root = new TrieNode('\0') ; // initialising the root node with NULL
    }

    void doInsert(TrieNode* root , string word){

        // base case
        if(word.length() == 0){
            root -> isEndofWord = true ; return ;
        }

        int index = word[0] - 'a' ;
        TrieNode* child ;

        // agar phle se present hain then move child to that node
        if(root -> children[index] != NULL){
            child = root -> children[index] ;
        }
        else{ // agar nhi hain then hme create krna hoga
            child = new TrieNode(word[0]) ;
            root -> children[index] = child ;
        }

        // recursion
        doInsert(child, word.substr(1)) ;
    }

    void insert(string word){
        doInsert(root, word) ;
    }

    void printSugg(TrieNode* curr, vector<string> &temp , string prefix){

        if(curr -> isEndofWord){
            temp.push_back(prefix) ;
        }

        for(char key = 'a' ; key <= 'z' ; key++){
            TrieNode* next = curr -> children[key - 'a'] ;

            if(next != NULL){
                prefix += key ;
                printSugg(next, temp, prefix) ;
                prefix.pop_back() ;
            }
        }
    }

    vector<vector<string>> doMyWork(string str){
        TrieNode* prev = root ; vector<vector<string>> ans ;
        string prefix = "";

        for(int i=0 ; i < str.length() ; i++){
            char lastKey = str[i] ; prefix.push_back(lastKey) ;

            // check if the lastKey exist or not
            TrieNode* curr = prev -> children[lastKey - 'a'] ;

            // if not found --> curr == NULL
            if(curr == NULL){break ;}
            else{
                vector<string> temp ;
                printSugg(curr, temp , prefix);

                ans.push_back(temp) ; temp.clear() ; prev = curr ;
            }
        }

        return ans ;
    }
};

vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr){
    //    Write your code here.
    Trie* trieNode = new Trie() ;

    // insert all the words in the contactList
    for(auto &&i : contactList){
        trieNode->insert(i) ;
    }


    return trieNode -> doMyWork(queryStr) ;
}