#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    bool isValid(string s) {

        // jb bhi closing bracket aa gya tb stack k top mein us closing bracket k corresponding open bracket hona chaiye aur last mein stack empty hona chaie after traversing the whole string
        stack<char> temp ;
        for(int i = 0 ; i < s.length(); i++){
            if(s[i] == '(' or s[i] == '{' or s[i] == '['){
                temp.push(s[i]) ;
            }
            else{
                if(s[i] == ')'){
                    if(!temp.empty()  and temp.top() == '('){temp.pop() ;}
                    else{
                        return false; 
                    }
                }

                else if(s[i] == '}'){
                    if(!temp.empty()  and temp.top() == '{'){temp.pop() ;}
                    else{
                        return false; 
                    }
                }

                else if(s[i] == ']'){
                    if(!temp.empty()  and temp.top() == '['){temp.pop() ;}
                    else{
                        return false; 
                    }
                }
            }
        }

        if(temp.empty()){return true ;} else{return false;}
    }
};