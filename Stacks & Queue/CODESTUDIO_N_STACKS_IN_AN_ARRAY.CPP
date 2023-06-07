#include <bits/stdc++.h>
using namespace std ;

// ye code likhte waqt mujhe smjh aa gya tha ye kaise hua tha... see the notebook (properly written by me)

class NStack{
private:
    int *arr ;int *top ; int *next ; int free ; int n, k ;
    // next is used to store the next free index in the array or it can also be used to store the prev store index of a particular stack

public:
    NStack(int N, int S){
        int n = S, k =  N;
        // n is the total size of array and k is the total number of stacks

        arr = new int[n] ;
        top = new int[k] ; next= new int[n] ;
        free = 0 ;

        // we need to initialise the top array with all values as -1
        for(int i = 0; i< k; i++){top[i] = -1;}
        for(int i=0; i< n; i++){
            next[i] = i+1 ;
        }

        next[n-1] = -1 ;
    }

    bool isEmpty(int sn){return top[sn] == -1 ;} // koi bhi stack empty tb hoga jb uska top -1 ko point krega obviously

    bool isFull(){return free == -1;} // array full hain mtlb ab jo hain ki n-1th index pr pahuch gya hain to wha pr free ki value -1 hogi iska mtlb array full hain

    bool push(int x, int m){
        int sn = m-1; // because in codestudio they have taken 1-based indexing
        if(isFull()){// stack overflow
            return false;
        } 
        else{
            int i = free ; free = next[i] ; arr[i] = x ;
            next[i]= top[sn]; top[sn]= i ; return true ;
        }
    }

    int pop(int m){
        int sn = m-1;
        if(top[sn] == -1){return -1 ;}
        else{
            int i= top[sn] ;
            top[sn] = next[i] ;
            next[i]= free; free=i ;
            return arr[i] ;
        }
    }
};