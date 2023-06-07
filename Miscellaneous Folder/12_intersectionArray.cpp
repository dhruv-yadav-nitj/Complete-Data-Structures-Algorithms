

// https://www.codingninjas.com/codestudio/problems/intersection-of-2-arrays_1082149

// this is known as 2 pointer method

vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
	int i = 0, j = 0 ;
	vector<int> ans; 
	while (i<n && j<m)
	{
		if(arr1[i]==arr2[j])
		{
			ans.push_back(arr1[i]);
			i++;
			j++;
		}
		else if (arr1[i] < arr2[j])
		{
			i++ ;
		}
		else
		{
			j++ ;
		}
	}
	return ans ;
}