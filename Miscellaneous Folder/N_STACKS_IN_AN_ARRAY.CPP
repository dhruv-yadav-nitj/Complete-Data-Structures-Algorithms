// this code was written with the help of gfg article.. please handle carefully
#include <bits/stdc++.h>
using namespace std ;

class kStacks{
private:
    int *arr ; // primary array
    int *top ; int *next ; // arrays we have talked about in notes
    int n, k ; // n is the size of arr and k is the total number of stacks
    int free ; // to store beginning index of free list

public:
    kStacks(int k, int n){
        // constructor
        arr = new int[n] ; top = new int[k] ; next = new int[n] ;
        free =0 ;

        // initialise all the values of top with -1 which shows the top of stacks, since initially we keep the top of stacks as -1 so here also the same convention
        for(int i=0; i< k; i++){top[i] = -1 ;}

        for(int i=0; i< n; i++){next[i] = i+1 ;}
        next[n-1] = -1; // -1 is used to indicate the end of free list
    }

    bool isFull(){
        return (free == -1) ;
        // array mein koi space free hain ya nhi iska pata free se hi pata chalega
    }

    bool isEmpty(int sn){
        return (top[sn] == -1) ;
        // agar kisi stack ka top -1 hain iska mtlb ki wo empty hi hoga
    }

    void push(int data, int sn){
        // to push the data in stack number 'sn' where 0 <= sn <= k-1
        if(isFull()){cout << "Stack Overflow" << endl ;}
        else{
            int i = free ; free = next[i] ; arr[i] = data;

            // update next of top and then top for stack number 'sn'
            next[i] = top[sn]; top[sn] = i ;
        }
    }

    int pop(int sn){
        if(isEmpty(sn)){
            cout << "Stack Underflow" << endl ;
        }
        else{
            // find the index of top item in stack number sn
            int i= top[sn] ;
            // change the top to store next of prev top
            top[sn] = next[i] ;
            // attach the previous top to the beginning of free list
            next[i] = free ; free= i ;

            return arr[i] ;
        }
    }
};

int main(int argc, char const *argv[])
{
    int k= 3; int n=10 ;
    kStacks ks(k, n) ;
    ks.push(15, 2) ; ks.push(16, 2) ; ks.push(10, 1) ; ks.push(11, 1) ;
    ks.push(99, 0); ks.push(98, 0) ; ks.push(97, 0);

    cout << "Top Element and Popped Element of Stack 2: " << ks.pop(2) << endl;
    cout << "Top Element and Popper Element of Stack 0: " << ks.pop(0) << endl;
    return 0;
}