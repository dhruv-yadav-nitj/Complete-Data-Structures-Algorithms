#include <bits/stdc++.h>
using namespace std ;

// dequeue is a type of queue which does not follow the basic rule of being a queue i.e., LIFO ... basically in dequeue we can perform pushFront, pushRear, popFront, popRear .... i.e., we can push the elements at front and at rear as well and we can pop the elements from front and from rear as well.

class Deque{
int *arr; int front, rear , size ; // these are the things we need to build a queue using an array

public:
    Deque(int n){
        size = n ;
        arr= new int[n] ;
        front = rear = -1 ;
    }

    // when the queue is empty --> when front == -1
    bool isEmpty(){
        return (front == -1) ;
    }

    // when the queue is full --> when rear is at last index and front at 0 or (when rear is just before front)
    bool isFull(){
        if((rear == size-1 and front == 0) or (front !=0  and rear== (front-1) % (size-1))){
            return true ;
        }
        else{
            return false; 
        }
    }

    int getFront(){
        if(isEmpty()){return -1 ;}
        else{
            return arr[front] ;
        }
    }

    int getRear(){
        if(isEmpty()){return -1 ;}
        else{
            return arr[rear] ;
        }
    }

    bool pushFront(int data){
        if(isFull()){
            // we can do nothing
            return false ;
        }
        else{
            if(isEmpty()){
                front = rear =0 ;
            }
            else if(front ==0 and rear != size-1){
                front = size-1 ;
            }
            else{
                front-- ;
            }
            arr[front] = data ;

            return true ;
        }
    }

    bool pushRear(int data){
        if(isFull()){
            // we can do nothing
            return false;
        }
        else{
            if(isEmpty()){
                front = rear = 0 ;
            }
            else if(rear == size-1 and front != 0){
                rear =0 ;
            }
            else{
                rear++ ;
            }
            arr[rear] = data ;
            return true ;
        }
    }

    int popFront(){
        if(isEmpty()){return -1 ;}
        else{
            int temp = arr[front] ; arr[front] = -1 ;

            // single element can be present
            if(front == rear){
                front = rear =-1 ;
            }
            else if(front == size-1){ // front can be at the last index and then after popping we need to make the front at 0
                front = 0 ;
            }
            else{
                front++ ;
            }
            return temp;
        }
    }

    int popRear(){
            if(isEmpty()){
                return -1 ;
            }
            else{
                int temp = arr[rear] ; arr[rear] = -1 ;
                if(front == rear){
                    // means single element is present
                    front = rear = -1;
                }
                else if(rear == 0){
                    rear = size-1 ;
                }
                else{
                    rear-- ;
                }
                return temp ;
            }
        }
};