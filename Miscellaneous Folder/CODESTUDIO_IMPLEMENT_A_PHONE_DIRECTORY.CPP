#include <bits/stdc++.h>
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
using namespace std;

class TrieNode{
public:
    char data;TrieNode *children[26];bool isTerminal;
    TrieNode(char key){
        data = key ;
        for (int i = 0; i < 26; i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie{
public:
    TrieNode* root ; 
    Trie(){
        root = new TrieNode('\0');
    }


    // word insert mechanism

    void doInsert(TrieNode* root, string word){
        if(word.length() == 0){
            root -> isTerminal = true ; return ;
        }

        TrieNode* child ;
        
        if(root -> children[word[0] - 'a']!= NULL){
            child = root -> children[word[0] - 'a'] ;
        }
        else{
            child = new TrieNode(word[0]) ;
            root -> children[word[0] - 'a'] = child ;
        }
        doInsert(child , word.substr(1)) ;
    }

    void insert(string word){
        doInsert(root, word) ;
    }

    // suggestions-printing-mechanism

    void returnSuggestions(TrieNode* curr, string prefix , vector<string>&temp){

        // agar to word khtm ho gya then isko insert kr do vector mein
        if(curr -> isTerminal){
            temp.push_back(prefix) ;
        }

        for(char ch = 'a' ; ch <= 'z' ; ch++){
            TrieNode* next = curr -> children[ch - 'a'] ;
            if(next != NULL){
                prefix += ch ; returnSuggestions(next, prefix, temp) ;
                prefix.pop_back() ;
            }
        }
    }

    vector<vector<string>> doWork(string word){
        vector<vector<string>> ans ;
        string prefix = "" ;
        TrieNode *prev=  root , *curr ;

        for(int i = 0 ; i < word.length() ; i++){
            prefix += word[i] ; char lastKey  = word[i] ;
            curr = prev -> children[lastKey - 'a'] ;
            if(curr == NULL){
                break ;
            }
            else{
                vector<string> temp ;
                returnSuggestions(curr, prefix, temp) ; ans.push_back(temp);
                prev = curr ;
            }
        }
        return ans ;
    }
};

vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr){
    //  Write your code here.
    Trie trie ;
    for(auto &&x: contactList){
        trie.insert(x) ;
    }
    return trie.doWork(queryStr) ;
}