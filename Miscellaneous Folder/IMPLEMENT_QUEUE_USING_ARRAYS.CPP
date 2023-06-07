#include <bits/stdc++.h>
#define size 1000
using namespace std ;

class Queue{
int *arr; int front ; int rear ;
public:
    // constructor
    Queue(){
        arr = new int [size] ;
        front = 0; rear =0 ;
    }

    void push(int data){
        // lets check if the queue has some space or not
        if(rear == size){
            // queue overflow
        }
        else{
            arr[rear] = data ;
            rear++ ;
        }
    }

    int pop(){
        if(front == rear){
            // means the queue is empty
            return -1 ;
        }
        else{
            int temp= arr[front] ;
            arr[front] =-1 ; front++ ; return temp ;
            if(front == rear){
                front =0; rear =0 ;
            }
        }
    }

    bool isEmpty(){
        return (front == rear) ;
    }

    int qfront(){
        if(front == rear){return -1 ;} // queue empty
        else{
            return arr[front] ;
        }
    }

    int back(){
        if(front == rear){return -1 ;} // queue empty
        else{
            return arr[rear-1] ;
        }
    }
};

int main(int argc, char const *argv[])
{
    Queue q; q.push(1) ; q.push(2) ;
    cout << q.qfront() << " " << q.back() << endl ;
    q.pop() ; q.pop() ;
    if(q.isEmpty()) {cout << "YES" << endl ;}
    else{
        cout << "NO" << endl ;
    }
    return 0;
}
