#include <bits/stdc++.h>
using namespace std ;

// iska implementation thoda complex hain, but easy hain logic

class CircularQueue{
int *arr; int front; int rear ; int size ;
public:
    CircularQueue(int n){
        size = n ;
        arr = new int[size] ;
        front = -1 ; rear = -1 ;
    }

    bool enqueue(int value){
        if((front == 0 and rear == size-1) or (rear == (front-1) %(size -1))){
            return false;
            // since the queue is full
        }
        else{
            if(front == -1){
                // means we are going to push the very first element
                front =0; rear= 0;
                arr[rear] = value;
            }
            else if(rear == size-1 and front != 0){
                rear =0 ; arr[rear] = value;
            }
            else{
                rear++ ;
                arr[rear] = value ;
            }
            return true ;
        }
    }

    int dequeue(){
        // queue can be empty
        if(front == -1){
            return -1 ;
        }
        else{
            int ans = arr[front] ;
            if(front == rear){
                // single element is present
                front = rear = -1 ;
            }
            else if(front == size -1){
                front = 0;
            }
            else{
                front++ ;
            }
            return ans ;
        }
    }
};