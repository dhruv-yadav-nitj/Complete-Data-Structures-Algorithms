#include <bits/stdc++.h>
using namespace std ;
bool findRedundantBrackets(string &s){
    stack<char> temp ;
    for(int i=0; i< s.length(); i++){
        if(s[i] == '(' or s[i] == '+' or s[i] == '-' or s[i] == '*' or s[i] == '/'){
            temp.push(s[i]) ;
        }
        else if(s[i] == ')'){
            bool flag=  true ;
            while(temp.top() != '('){
                if(temp.top() == '+' or temp.top() == '-' or temp.top() == '*' or temp.top() == '/'){
                    flag = false;
                }
                temp.pop() ;
            }
            if(flag){return true ;}
            temp.pop() ;
        }
    }
    return false;
}

/* 
Approach:
suppose hme open bracket mila ya hme koi operator mila to hmne usko stack mein daal dia
jb hme koi closing bracket mila to hmne stack ko traverse krna start kra kisi opening bracket k lie aur raaste mein hme koi operator mila to iska mtlb ye pair koi rebundant bracket nhi hain lekin agar koi operator nhi milta iska mtlb yhi pair useless hain
*/