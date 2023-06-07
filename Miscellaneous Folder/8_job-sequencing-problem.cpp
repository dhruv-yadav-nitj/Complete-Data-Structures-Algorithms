
// https://www.geeksforgeeks.org/job-sequencing-problem/
/*
Given an array of jobs where every job has a deadline and associated profit if the job is finished before the deadline. It is also given that every job takes a single unit of time, so the minimum possible deadline for any job is 1. How to maximize total profit if only one job can be scheduled at a time.
*/
#include <bits/stdc++.h>
#define l long long
#define vl vector<long long>
#define vi vector<int>
#define vp vector<vector<int>>
using namespace std;

struct jobs
{
    char id;
    int deadline;
    int profit;
};

bool custom(jobs a, jobs b)
{
    return (a.profit > b.profit);
}

void printJobs(jobs arr[], int n)
{
    sort(arr, arr + n, custom);
    vi ans;
    bool slot[n];

    // assign false to all the bool slot elements which denotes that initially all the slots are free
    for (int i = 0; i < n; i++)
    {
        slot[i] = false;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = min(n, arr[i].deadline) - 1; j >= 0; j--)
        {
            if (slot[j] == false)
            {
                ans.push_back(i);
                slot[j] = true;
                break;
            }
        }
    }
    for (int i = 0; i < ans.size(); i++)
    {
        if (slot[i])
        {
            cout << arr[ans[i]].id << " ";
        }
    }
    cout << endl;
}

int main()
{
    jobs arr[] = {{'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27}, {'d', 1, 25}, {'e', 3, 15}};
    int n = sizeof(arr) / sizeof(arr[0]);

    printJobs(arr, n);

    return 0;
}