
// https://www.codingninjas.com/codestudio/problems/pair-sum_697295

#include <iostream>
using namespace std ;

void pairSum (int array[], int N , int S)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (array[i]+array[j] == S)
            {
                if (array[i]< array[j])
                {
                    cout << array[i] << " " << array[j] << endl ;
                }
                
            }
            
        }
        
    }
    
}

int main()
{
    int array[1000] ;
    int N , S ;
    cin >> N >> S ;
    for (int i = 0; i < N; i++)
    {
        cin >> array[i] ;
    }
    
    pairSum (array , N , S) ;

    return 0;
}