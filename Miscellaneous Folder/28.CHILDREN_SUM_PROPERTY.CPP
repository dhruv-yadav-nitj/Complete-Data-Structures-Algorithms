#include <bits/stdc++.h>
using namespace std ;

void doWork(BinaryTreeNode<int> *root){

    // base-condition
    if(root == NULL){return ;}

    int childSum(0) ;
    if(root -> left != NULL){childSum += root -> left -> data ;}
    if(root -> right != NULL){childSum += root -> right -> data ;}

    if(childSum < root -> data){ // agar left + right < node then we need to make them >= the node value --> so we can either make left or right equal to the node or we can make both left and right equal to node
        if(root -> left != NULL){root -> left -> data = root -> data ;}
        else if(root -> right != NULL){root -> right -> data = root -> data ;}
    }

    doWork(root -> left) ; doWork(root -> right) ; // call for its children
    
    int currChildrenSum = 0 ;

    if(root -> left != NULL){currChildrenSum += root -> left -> data ;}
    if(root -> right != NULL){currChildrenSum += root -> right -> data ;}

    if(root -> left != NULL or root -> right != NULL){
        root -> data = currChildrenSum ;
    }
}

void changeTree(BinaryTreeNode<int> *root){
    // Write your code here.
    doWork(root) ;
}