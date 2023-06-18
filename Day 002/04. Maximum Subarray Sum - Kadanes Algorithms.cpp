#include <bits/stdc++.h> 

long long maxSubarraySum(int arr[], int n)
{
    long long currentSum = 0;
    long long maxSum = 0;

    for(int i=0; i<n; i++)
    {
        currentSum = currentSum + (long long)arr[i];
        currentSum = max(currentSum, (long long)arr[i]);
        maxSum = max(maxSum, currentSum);
    }
    return maxSum;
}

