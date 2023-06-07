#include <bits/stdc++.h>
using namespace std ;

class Queue{
    int *arr ; // primary array
    int *front ; int *rear ; int *next ; // extra requirements
    int free ; // variable to store the next free index

public:
    Queue(int n, int k){
        arr = new int[n] ;
        front = new int[k] ; rear= new int[k]; next = new int[n] ;
        for(int i=0; i< n; i++){
            next[i] = i+1 ;
        }
        next[n-1]= -1 ; // referencing that there is no extra space available after next[n-1]
        free = 0; // referencing that the next free space avaiable is arr[0]
        for(int i=0; i< n; i++){
            front[i] = -1 ; rear[i] = -1 ;
        }
    }

    bool isFull(){
        // check if there is more space available in array or not
        return (free == -1) ;
    }

    bool isEmpty(int qk){
        // since we have made this code as 0th - based indexing
        qk = qk -1 ; // and the query would be asked in the form of 1-based indexing --> obviously because let say we have been asked for 1st queue then for our code it would be 0th queue

        // check if qkth queue is empty or not
        return (front[qk] == -1) ;
    }

    // function to push the element in the queue--> when it is able to push --> return true else --> return false
    bool push(int qk, int data){
        // push data to the rear of qkth queue
        // due to 0-based indexing
        qk = qk -1 ;

        // check if there is space available in the array or not
        if(isFull()){
            return false;
        }

        // since space is available --> target the next free space available and push the element there
        int index =free ; arr[index] = data ;
        // ab agla free kha pr hoga --> wha pr hoga jha pr next[index] point kr rha hoga
        // --> jaise maan lo index = 0 aagya to next free spot kha hain 1 pr jo ki kya hain next[0]
        free = next[index] ;
        
        // ab baari hain ki hm baaki values ko change
        // to ho skta hain ye qkth queue ka phla element ho mtlb ki front[qk] == -1 hain abhi tk
        if(front[qk] == -1){
            front[qk] = index ;
        }
        else{
            // iska logic accha hain --> noted in notebook and babbar ne apne lec#61 mein batayi thi during 1:35:00 minutes
            next[rear[qk]] = index ; // this line of code is meant to connect the prev element of queue to current element of queue --> so isilie ye isEmpty() k else mein hain because agar queue abhi tk empty tha to peechla element kuch tha hi nahi iska mtlb

            // jaise maan lo hme abhi 1st queue mein phla index fill krna hain 
            /* 
            so, according to given code we would have
            free = 0 ; front[0]= -1; rear[0] = -1 ;
            --> index = 0 --> arr[index] = arr[0] = 1 (suppose 1 hi push kr dia) --> since front[0]==-1 --> front[0] = index = 0 --> rear[0] = 0 --> next[0] = -1 (ye aisa hain kyuki abhi tk hmne iske aage kuch push nhi kia hain)

            jaise hi hm 1st queue mein agla element (let say 2 is baar) push krne chalenge tb dekho kya hota hain
            index = free = 1 --> arr[index] = arr[1] = 2 --> since is baar front[0] != -1 --> else condtion mein ghusega --> next[rear[0]] = next[0] = index = 1 (bs ye dekho link kr dia na peechle element ko is element se) --> rear[0] = index = 1 --> since phir se ye last element ho skta hain queue ka so iska next -1 ko point krna chaiye --> next[index]=  next[1] = -1 
            */
        }
        
        // also we need to change the rear of queue to the new index
        rear[qk] = index ;
        next[index] = -1 ; // uppar hmne already next[index] free mein store kr lia tha , so ab iska koikaam nhi hain + ye slot ab free nhi hain to isilie -1 kr die

        return true ;
    }

    int pop(int qk){
        // pop the front of qkth queue
        qk = qk -1 ;

        // agar queue empty hi hain to kya hi pop kroge
        if(isEmpty(qk)){return -1 ;}
        else{
            // and agar empty nhi hain to kuch krna pdhega
            int index = front[qk] ; // ye wo hogya jisko hatana hain

            // ab naya front hoga jo queue mein next element hoga
            front[qk] = next[index] ;
            
            // ab ye jagah free ho chuki hain so iska next abhi tk ke free ko point krna chaiye aur isko naya free bana dena chaiye
            next[index] = free ; free = index ;

            return arr[index] ;
        }
    }
};