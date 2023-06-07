#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;

class heap{
public:
    int arr[100] ; int size= 0 ; // implemening heap using an array --> initially the size would be 0

    heap(){
        arr[0] = -1 ; size = 0 ; // constructor
    }

    void insert(int data){

        // time complexity : O(logN)

        size = size +1 ; // new size

        int index = size ; // is index pr hmne new value ghusaani hain --> 0th index hmesa khaali rhega --> in our implementation

        arr[index] = data ;

        // since hmne value to ghusa di ab is value ko shi place pr lgaane ka time hain
        while(index > 1){

            int parent = index /2 ; // parent ka index --> according property of CBT

            if(arr[parent] < arr[index]){
                swap(arr[parent] , arr[index]) ; index = parent ;
            }
            else{return ;} // iska mtlb ki shi place pr aa chuka hain --> break kr do --> return
        }
    }

    void print(){
        for(int i =1 ; i <= size ; i++){
            cout << arr[i] << " " ;
        }
        cout << endl ;
    }

    void deleteFromHeap(){

        // time complexity : O(logN)

        if(size == 0){
            return ; // since we dont have anything to delete
        }

        // deletion in heap always means that we have to delete the root node (atleast max heap mein to aisa hi hota hain --> yrr aditya verma ki heap playlist ki phli vdo dekhna usme wo bataya hain ki heap bhi ekdam stacks jaisa hi hota hain aur bhi bahut kuch bataya hain --> go and revise

        // root node ko hatana hain --> so basically wha k value ko change kr do size decrement kr do by 1
        arr[1] = arr[size] ; size-- ;

        // now take the root to its correct position --> since it is a max heap --> parent node should be greater than the child nodes

        int i = 1 ;
        while(i < size){
            int left = 2*i , right = 2*i + 1 ;
            if(left < size and arr[left] > arr[i]){ // left < size --> aisa isilie likha gya bcz aisa bhi ho skta hain ki left wla exist hi na kre
                swap(arr[i], arr[left]) ;
            }
            else if (right < size and arr[right] > arr[i]){ // same to left wala reason
                swap(arr[i], arr[right]) ;
            }
            else{return ;} // means shi place pr pahuch gya hain sbkuch
        }

    }

};


// heapify algorithm --> very very important

void heapify(int arr[], int n , int i){

        // heapify algo --> time complexity : O(logN)

        /* 
        what does heapify algo do ?
            --> we have an index i --> so basically hme kya krna hain ki ek tree ki tarah imagine kro --> aur assuming i as a parent node of a subtree --> us pure subtree ko ek heap bana dena hain --> ye tbhi hoga jb us tree k hr ek node heap k rules ko follow kre
        */

    //    i is the index jha pr largest element hona chaiye

       int largest = i , left = 2*i , right = 2*i + 1 ;
       if(left < n and arr[largest] < arr[left]){
            largest = left ; // update the largest if the left child is greater than the parent
       }

       if(right < n and arr[largest] < arr[right]){largest = right ;} // update the largest if the right child is greater than the largest

       if(largest != i){
            // agar largest change ho gya --> means largest wo nhi rha jo hmne start mein liaa tha --> tbhi kuch krne ka jroorat hain --> agar whi rh jaata mtlb saare nodes apne shi jagah pr hain

            swap(arr[i] , arr[largest]) ;
            heapify(arr, n , largest) ;
       }
}

int main(int argc, char const *argv[])
{

    heap h1 ; h1.insert(100) ; h1.insert(101) ; h1.print() ;

    h1.deleteFromHeap() ; h1.print() ;

    int arr[] = {-1, 50, 53, 54, 55, 52} ; int n = sizeof(arr) / sizeof(arr[0]) ;


    // yha pr i = n/2 isilie hain bcz leaf nodes ko hm consider krte hain ki wo phle se hi heap hain    
    for(int i = n/2 ; i >0  ; i--){
        heapify(arr, n , i) ;
    }

    for(int i =0 ; i <  n ; i++){
        cout << arr[i] << " " ;
    }
    
    return 0;
}
