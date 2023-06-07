#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std ;


// coding begins here

// this special node contains int data , int row , int col
class Node{
public:
    int data , row, col ;
    Node(int data , int i , int j){
        this -> data = data ; row = i ; col = j ;
    }
};

class comparator{
public:
    bool operator()(Node* a , Node* b){
        return a -> data > b -> data ;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {

        // code here


            // step 1
            // prioritu queue bnaya and then usme hr ek list ka phla element daal dia
        priority_queue<Node* , vector<Node*>  , comparator> pq ;
        int i =0 ;  int maxi = INT_MIN ; // since hme max ka track rkhna hain --> usme to kuch changes nhi krne --> bcz agar hmne upperbound mein changes kr die and hme pata hain ki list increasing sorted way mein hain --> then wo list hmare range mein aayi hi nahi paaega jo upperbound se start ho rha hain
        for(auto &&x: nums)        {
            maxi = max (maxi , x[0]) ;
            Node* temp = new Node(x[0] , i++, 0) ; pq.push(temp) ;
        }

            // step 2
        int mini = INT_MAX , ansMin = -100000 , ansMAX = 100000 ;
        while(!pq.empty()){
            auto temp  = pq.top() ; pq.pop() ;
            int val = temp -> data , row = temp -> row , col = temp -> col ;
            mini = val ; // updating the min element
            
            // updating ans
            if(maxi - mini < ansMAX - ansMin){
                ansMin = mini , ansMAX= maxi ;
            }

            // updating maxi 
            if(col + 1 < nums[row].size()){
                maxi = max (maxi , nums[row][col+1]) ;
                Node* temp2 = new Node(nums[row][col+1] , row , col+1) ; pq.push(temp2) ;
            }
            else{
                // means one of the list is completed
                break ; // now we need to exit the loop since aage range change kaise kroge
            }
        }

        vector<int> ans ; ans.push_back(ansMin) ; ans.push_back(ansMAX) ; return ans ;

    }
};