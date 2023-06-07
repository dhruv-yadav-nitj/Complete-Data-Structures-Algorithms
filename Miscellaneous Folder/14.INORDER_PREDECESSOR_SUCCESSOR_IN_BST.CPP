#include <bits/stdc++.h>
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
using namespace std;

// https://www.codingninjas.com/codestudio/problems/predecessor-and-successor_920476

// to understand this problem take the example of the tree : 5 2 7 1 4 6 9 N N 3 N N N 8 10

class binaryTreeNode{
public:
    int data;
    binaryTreeNode *left; binaryTreeNode *right;

    binaryTreeNode(int data){
        this->data = data;this->left = NULL;this->right = NULL;
    }
};

vector<int> findPreSuc(binaryTreeNode *root, int key){
    // Write your code here.
    vector<int> ans ;
    // basically hme kya nikaalna hain ki jaise agar hm given tree ka inorder traversal likhe to kisi number 'key' k just phle aur just baad kaun sa number aaega
    int pre = -1 , suc = -1 ;
    binaryTreeNode* curr = root ;
    while(curr != NULL){
        if(curr -> data > key){
            suc = curr -> data ;
            curr = curr -> left ;
        }
        else{curr = curr -> right ;}
    }

    curr = root ;
    while(curr != NULL){
        if(curr -> data < key){
            pre = curr -> data ;
            curr = curr -> right ;
        }
        else{curr = curr -> left ;}
    }

    ans.push_back(pre) ; ans.push_back(suc) ; return ans ;

}