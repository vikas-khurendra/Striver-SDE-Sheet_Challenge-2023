********************* Brute Force Approach TC = O(n^2), SC = O(1) ***********************

// Code :

#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    int totalWater = 0;
    for(int i=0; i<n; i++)
    {
        int leftMax = arr[i];
        for(int j=0; j<i; j++)
        {
            if(arr[j] > leftMax)
            {
                leftMax = arr[j];
            }
        }

        int rightMax = arr[i];
        for(int k=i+1; k<n; k++)
        {
            if(arr[k] > rightMax)
            {
                rightMax = arr[k];
            }
        }

        totalWater += min(leftMax, rightMax) - arr[i];
    }
    return totalWater;
}

Time Complexity: O(N2). There are two nested loops traversing the array.
Space Complexity: O(1). No extra space is required.

********************* Better Approach TC = O(n), SC = O(n) ***********************

#include <bits/stdc++.h>
long getTrappedWater(long *arr, int n)
{
    long totalWater = 0;
    long leftMax[n];
    long rightMax[n];

    leftMax[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        leftMax[i] = max(leftMax[i-1], arr[i]);
    }

    rightMax[n-1] = arr[n-1];
    for (int j = n-2; j >= 0; j--)
    {
        rightMax[j] = max(rightMax[j+1], arr[j]);
    }

    for(int k = 1; k<n-1; k++)
    {
        int diff = min(leftMax[k-1], rightMax[k+1]);
        if(diff > arr[k])
        {
            totalWater += diff - arr[k];
        }
    }
    return totalWater;
}

Time Complexity: O(N). Only one traversal of the array is needed, So time Complexity is O(N).
Space Complexity: O(N). Two extra arrays are needed, each of size N.

********************* Optimal Approach TC = O(n), SC = O(1) ***********************

#include <bits/stdc++.h> 

long getTrappedWater(long *height, int n)
{
    long totalWater = 0;
    int left = 0;
    int right = n - 1;
    long maxLeft = 0;
    long maxRight = 0;

    while (left < right)
    {
        if (height[left] <= height[right])
        {
            if (height[left] > maxLeft)
            {
                maxLeft = height[left];
            }
            else
            {
                totalWater += maxLeft - height[left];
            }
            left++;
        }
        else
        {
            if (height[right] > maxRight)
            {
                maxRight = height[right];
            }
            else
            {
                totalWater += maxRight - height[right];
            }
            right--;
        }
    }
    return totalWater;
}

Time Complexity: O(N)
Auxiliary Space: O(1) 
