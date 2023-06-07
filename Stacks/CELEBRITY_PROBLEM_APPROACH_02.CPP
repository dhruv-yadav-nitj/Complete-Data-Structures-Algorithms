#include <bits/stdc++.h>
using namespace std ;

class Solution 
{
private:
    bool knows(vector<vector<int>> M,int A, int B){
        if(M[A][B] == 1){return true;}
        return false;
    }
public:
    int celebrity(vector<vector<int> >& M, int n){
        stack<int> s ; 
        for(int i=0; i< n; i++){s.push(i);}
        while(s.size() > 1){
            int A = s.top() ; s.pop() ;
            int B = s.top() ; s.pop() ;
            if(knows(M, A, B)){s.push(B) ;}
            else{
                s.push(A) ;
            }
        }

        int doubt = s.top() ; bool cnf= true ;
        for(int col = 0; col < n; col++){
            if(M[doubt][col] == 1){cnf = false ; break ;}
        }

        if(cnf){
            for(int i=0; i< n; i++){
                if(M[i][doubt] == 0 and i!=doubt){cnf = false; break ;}
            }
        }

        if(cnf){return doubt ;}
        else{return -1 ;}
    }
};