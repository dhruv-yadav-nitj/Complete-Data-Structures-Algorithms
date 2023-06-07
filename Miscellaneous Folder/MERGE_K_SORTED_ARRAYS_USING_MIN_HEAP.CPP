#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;


// building special node --> it would store data as well as keep track of row and col numbers of an element

class Node{
public:
    // consist of data , row , col
    int data , row , col ;

    // constructor
    Node(int data,  int row , int col){

        this -> data = data ; this -> row = row ; this -> col = col ;
    }

};

// speacial function --> for min Heap comparison
class comparator{
public:
    bool operator()(Node* a,  Node* b){ // operator() is something special --> do some research ?
        return a -> data > b -> data ;

        // yha pr a- > data > b -> data kyu hua hain ?? agar common sense lgaya jaae to a -> data < b->data hoan chaiye tha
        // when we create traditional priority queue --> tb hm greater<int> likhte hain --> isase kya hota hain ki numbers increasing order mein sort hote hain --> thoda ulta lg rha hoga --> bs isilie yha bhi ulta likh die
    }
} ;

class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K){

        //code here
        
        // step 1: prepare a special node and a special comparator function
        vector<int> ans ;
        priority_queue<Node* , vector<Node*> , comparator> pq ;

        // step 2: insert all the first elements of each row in the pq
        for(int i =0 ; i < K ; i++){

            Node* temp = new Node(arr[i][0] , i , 0) ;
            pq.push(temp) ;

        }

        // now we have the minimum element on the top of heap

        // step 3: ab dekho jo min heap k top pr node hain us arr k har ek element ko usme daalte jaao --> basically aisa krne se pure matrix ka har ek element min Heap mein se ho kr jaaega but ek baar mein sirf max K elements hi  honge min Heap mein --> hence it optimizes time as well as space complexity
        while(pq.size() > 0){

            auto x = pq.top() ; pq.pop() ; ans.push_back(x -> data) ;
            int i= x -> row , j = x -> col ;
            if(j + 1 < arr[i].size()){

                Node *temp2 = new Node(arr[i][j+1] , i , j+1) ;
                pq.push(temp2) ;

            }
        }

        return ans ;

    }
};