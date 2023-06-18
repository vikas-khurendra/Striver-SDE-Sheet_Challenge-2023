// Problem :

Ninja loves playing with numbers. So his friend gives him an array on his birthday. The array consists of positive and negative integers. Now Ninja is interested in finding the length of the longest subarray whose sum is zero.

// Code :

#include <bits/stdc++.h>

// int LongestSubsetWithZeroSum(vector<int> arr)
// {
//     int maxLength = 0;
//     for (int i = 0; i < arr.size(); i++)
//     {
//         int sum = 0;
//         for (int j = i; j < arr.size(); j++)
//         {
//             sum = sum + arr[j];
//             if (sum == 0)
//             {
//                 maxLength = max(maxLength, j - i + 1);
//             }
//         }
//     }
//     return maxLength;
// }


int LongestSubsetWithZeroSum(vector<int> arr)
{
    unordered_map<int, int> prefixSumMap;
    int n = arr.size();
    int sum = 0;
    int maxLength = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == 0)
        {
            maxLength = max(maxLength, i + 1);
        }
        
        if (prefixSumMap.find(sum) != prefixSumMap.end())
        {
            maxLength = max(maxLength, i - prefixSumMap[sum]);
        }
        if (prefixSumMap.find(sum) == prefixSumMap.end())
        {
            prefixSumMap[sum] = i;
        }
    }
    return maxLength;
}