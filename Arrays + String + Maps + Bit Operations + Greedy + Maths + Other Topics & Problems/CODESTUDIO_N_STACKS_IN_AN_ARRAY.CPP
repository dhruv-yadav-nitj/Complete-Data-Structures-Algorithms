#include <bits/stdc++.h>
using namespace std ;

// this code was written by myself without any help
// so this means i was able to understand the logic behind the whole concept

class NStack{
private:
    // what do we need: we need an array to store the elements of n different stacks, we need an array to store the index of top elements of each stack and we need an array next which serves for two different purpose: to store the next free space available in the array or it can be used to store the prev top of the stack, also we need a free variable which tells if there is space available in the array or not
    int n, k ; int *arr, *top, *next ; int free ;
    // n denotes the total size of the array and k denotes the total number of stacks
public:
    NStack(int k, int n){
        // we need to form k stacks in an array having size n
        arr = new int[n] ; top = new int[k]; next = new int[n] ;
        free= 0; // because the first space available in the arr is 0th index
        for(int i=0; i< k; i++){top[i] = -1; }
        for(int i=0; i< n; i++){next[i]= i+1 ;} next[n-1] = -1;
    }

    bool isEmpty(int sn){
        // check if snth stack is empty or not
        return (top[sn] == -1 ) ;
        // if the top of that stack is -1 then it means that the stack is empty
    }

    bool isFull(){
        // the array is full if free == -1
        return (free == -1) ;
    }

    bool push(int data, int sn){
        sn = sn -1 ; // since at codestudio they used 1-based indexing
        if(isFull()){return false;}
        else{
            int i = free ; arr[i] = data ;
            free= next[i] ; next[i] = top[sn] ; top[sn] = i ; return true ;
        }
    }

    int pop(int sn){
        sn = sn -1;
        if(top[sn] == -1){
            // means the stack is empty by itself
            return -1 ;
        }
        else{
            // ab hme panchayat krna pdhega
            int i = top[sn] ;
            top[sn] = next[i] ; next[i] = free ; free = i ;
            return arr[i] ;
        }
    }
};