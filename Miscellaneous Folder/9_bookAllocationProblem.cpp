// https://www.geeksforgeeks.org/allocate-minimum-number-pages/

/*
Given number of pages in n different books and m students. The books are arranged in ascending order of number of pages. Every student is assigned to read some consecutive books. The task is to
1. Assign books in such a way that the maximum number of pages assigned to a student is minimum.
2. Every book is assigned to some student.
3. Each student has atleast one book assigned.

Input : pages[] = {12, 34, 67, 90}
		m = 2
Output : 113
Explanation:
There are 2 number of students. Books can be distributed
in following fashion :
  1) [12] and [34, 67, 90]
	  Max number of pages is allocated to student
	  2 with 34 + 67 + 90 = 191 pages
  2) [12, 34] and [67, 90]
	  Max number of pages is allocated to student
	  2 with 67 + 90 = 157 pages
  3) [12, 34, 67] and [90]
	  Max number of pages is allocated to student
	  1 with 12 + 34 + 67 = 113 pages

Of the 3 cases, Option 3 has the minimum pages = 113.
*/

/*
The idea is to use Binary Search. We fix a value for the number of pages as mid of current minimum and maximum. We initialize minimum and maximum as 0 and sum-of-all-pages respectively. If a current mid can be a solution, then we search on the lower half, else we search in higher half.
Now the question arises, how to check if a mid value is feasible or not? Basically, we need to check if we can assign pages to all students in a way that the maximum number doesn’t exceed current value. To do this, we sequentially assign pages to every student while the current number of assigned pages doesn’t exceed the value. In this process, if the number of students becomes more than m, then the solution is not feasible. Else feasible.
*/

#include <bits/stdc++.h>
#define l long long
#define vl vector<long long>
#define vi vector<int>
#define v2 vector<vector<int>>
#define IOS                       \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);                   \
	cout.tie(0)
using namespace std;

bool isPossible(vi arr, int n, int m, int currentMin)
{
	int studentsReq = 1;
	int curr_Sum = 0;

	for (int i = 0; i < n; i++)
	{

		if (arr[i] > currentMin)
		{
			return false;
		}

		if (curr_Sum + arr[i] > currentMin)
		{
			studentsReq++;

			curr_Sum = arr[i];

			if (studentsReq > m)
			{
				return false;
			}
		}
		else
		{
			curr_Sum += arr[i];
		}
	}
	return true;
}

int findPages(vi array, int n, int m)
{
	// return -1 if no.of books is less than no. of students as there would be no solution in that case
	if (n < m)
	{
		return -1;
	}

	// else

	// count total no. of pages
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += array[i];
	}
	// assign 0 to start and sum of all the pages to end element
	int s = 0, e = sum, result = INT_MAX;
	while (s <= e)
	{
		int mid = s + (e - s) / 2;
		if (isPossible(array, n, m, mid))
		{
			result = mid;
			e = mid - 1;
		}
		else
		{
			s = mid + 1;
		}
	}

	return result;
}

int main()
{
	IOS;
	// enter some input with unique elements
	int n;
	cin >> n;
	vi arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	int m;
	cin >> m;

	cout << "Ans: " << findPages(arr, n, m) << endl;

	return 0;
}