#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

// approach #1 --> brute force
// time complexity: O(N**2) * O(logk) --> nested loops + insertion in Set , where k is the size of set
int countDistinctSubstrings(string &s)
{
    //    Write your code here.
    set<string> st ;
    for(int i=0 ; i < s.length(); i++){
        string temp = "" ;
        for(int j = i; j < s.length(); j++){
            temp += s[j] ;
            st.insert(temp) ;
        }
    }
    return st.size() + 1 ;
}

// approach #2 --> using recursion 

// approach #3 --> using tries
/* Time Complexity: O(n2), because we have to go through the entire string for all possible different starting points in order to generate all the substrings.

Space Complexity: O(n2), because in the worst case, all the substrings can be distinct and there will be a node for every substring. Number of substrings of a string of length n is (n * (n + 1) / 2). Hence in the worst case, space complexity will be O(n2). */

struct Node{
    Node* links[26]; bool flag = false ;

    bool containsKey(char key){
        return (links[key - 'a'] != NULL) ;
    }

    void put(char key, Node* node){
        links[key - 'a'] = node ;
    }

    Node* get(char key){
        return links[key - 'a'] ;
    }
};

// have a visualization on pen and paper --> very good understanding
// https://takeuforward.org/data-structure/number-of-distinct-substrings-in-a-string-using-trie/

int countDistinctSubstrings(string &s){
    //    Write your code here.
    Node* root = new Node() ; int count(0) ;
    for(int i =0 ; i < s.length() ; i++){
        Node* node = root ;
        for(int j = i ; j < s.length() ; j++){
            if(!node -> containsKey(s[j])){
                count++ ;
                node -> put(s[j], new Node()) ;
            }
            node = node -> get(s[j]) ;
        }
    }
    return count+1 ;
}