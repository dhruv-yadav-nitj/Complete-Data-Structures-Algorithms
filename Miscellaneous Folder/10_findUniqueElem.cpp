
// https://www.codingninjas.com/codestudio/problems/find-unique_625159

int findUnique(int *arr, int size)
{
    int ans = 0;
    for (int i = 0; i < size; i++)
    {
        ans = ans ^ arr[i] ;
    }
    return ans ;    
}
/*
2nd approach
int findUnique(int *arr, int size)
{
    int count;
    for (int i = 0; i < size; i++)
    {
        count = 0;
        for (int j = 0; j < size; j++)
        {
            if (arr[i]==arr[j])
            {
                count++ ;
            }
        }
        if (count == 1)
        {
            return arr[i] ;
        }
    }
}
*/
