#include <bits/stdc++.h>
using namespace std ;

class Solution{
private:
    static bool checkPalindrome(string s){
        // main-function
        for(int i=0 ; i < s.length() /2 ; i++){
            if(s[i] != s[s.length() -1 - i]){return false; }
        }
        return true ;
    }
public:
    bool isPalindrome(string s){
        // code here
        string temp = "" ;
        for(int i=0; i< s.length() ; i++){
            s[i] = tolower(s[i]) ;
            if(s[i] >= 'a' and s[i] <= 'z'){
                temp += s[i] ;
            }
        }
        cout << temp << endl ;
        return checkPalindrome(temp) ;
    }
};