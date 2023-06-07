// this question is a variation of the question with same name
#include <bits/stdc++.h>
using namespace std ;

int main(){
    int arr[] = {-12, 11, -13, -5, 6, -7, 5, -3, -6} ;
    // we have to rearrange all the elements such that all negative elements are at the beginning and all the positive elements are at end, relative order can be changed but you have to use constant extra space
    

    // Naive Approach: Sort the array --> by doing this all negative elements would lie before the positive elements

    // Efficient Approach :
    int n = sizeof(arr)/sizeof(arr[0]) ;
    int j=0 ;
    for(int i=0; i < n ; i++){
        if(arr[i] < 0){
            if(i != j){swap(arr[i], arr[j]) ;} j++ ;
        }
    }

    // output : -12 -13 -5 -7 -3 -6 5 6 11 
    for(int i=0 ; i < n ; i++){ cout << arr[i] << " " ;} cout << endl ;
    return 0 ;
}