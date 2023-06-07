#include <bits/stdc++.h>
using namespace std ;

int findMinimumCost(string str) {
    if((str.length()&1) == 1){return -1;}
    else{
        // means str ka length odd nhi hain to kuch kaam kr skte hain
        stack<char> s;
        for(int i=0; i< str.length() ; i++){
            char c= str[i] ;
            if(c == '{'){
                s.push(c);
            }
            else{
                // means we got closing brackets
                if(s.top() == '{' and !s.empty()){
                    s.pop() ; // means we got a pair of valid braces
                }
                else{
                    s.push(c) ;
                }
            }
        }
        int open(0), clos(0);
        while(!s.empty()){
            if(s.top() == '{'){open++ ;}
            else{
                clos++ ;
            }
            s.pop() ;
        }
        return (open+clos)/2 ;
    }
}