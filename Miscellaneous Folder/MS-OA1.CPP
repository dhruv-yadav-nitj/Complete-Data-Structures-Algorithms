#include <bits/stdc++.h>
using namespace std;

int solution(string &row1, string &row2) {
    // Implement your solution here


    int n = row1.length() ;

    int cnt = 0 ;

    // first balance each column

    for(int i =0 ; i < n ; i++) {
        if((row1[i] == 'R' and row2[i] == 'W') or (row1[i] == 'W' and row2[i] == 'R') or (row1[i]=='?' and row2[i] == '?')) {
            continue;
        }
        else if (row1[i] == row2[i]) {
            return -1 ;
        }
        else{
            cnt++ ;
            if(row1[i] == '?') {
                if(row2[i] == 'R') {row1[i] = 'W' ;}
                else if(row2[i] == 'W') {row1[i] = 'R' ;}
            }
            else{
                if(row1[i] == 'R') {row2[i] = 'W' ;}
                else if(row1[i] == 'W') {row2[i] = 'R' ;}
            }
        }
    }

    // now balance each row
    int cntR1 (0), cntW1(0) , cntR2(0) , cntW2(0), cntq1(0), cntq2(0) ;
    for(int i =0 ; i < n ; i++) {
        if(row1[i]=='R'){cntR1++ ;} else if(row1[i]=='W'){cntW1++ ;} else if(row1[i]=='?'){cntq1++ ;}
        
        if(row2[i]=='R'){cntR2++ ;} else if(row2[i]=='W'){cntW2++ ;} else if(row2[i]=='?'){cntq2++ ;}
    }

    // cout << cntq1 << " " << cntq2 << endl ;

    if(cntR1 == cntW1 and cntR2 == cntW2) {return cnt ;}
    else {

        if(abs(cntR1 - cntW1) > cntq1) {return -1 ;}
        if(abs(cntR2 - cntW2) > cntq2) {return -1 ;}

        cnt += (abs(cntR1 - cntW1)) + (abs(cntR2 - cntW2));

    }    
    return cnt ; 
}
