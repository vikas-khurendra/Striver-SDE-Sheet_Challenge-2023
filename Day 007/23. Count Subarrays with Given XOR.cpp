// Problem :
Given an array of integers ‘ARR’ and an integer ‘X’, you are supposed to find the number of subarrays of 'ARR' which have bitwise XOR of the elements equal to 'X'.
Note:
An array ‘B’ is a subarray of an array ‘A’ if ‘B’ that can be obtained by deletion of, several elements(possibly none) from the start of ‘A’ and several elements(possibly none) from the end of ‘A’. 

// Code :

#include <bits/stdc++.h>

// int subarraysXor(vector<int> &arr, int x)
// {
//     int n = arr.size();
//     int count = 0;

//     for (int i = 0; i < n; i++)
//     {
//         int xorSum = 0;
//         for (int j = i; j < n; j++)
//         {
//             xorSum = xorSum ^ arr[j];

//             if (xorSum == x)
//             {
//                 count++;
//             }
//         }
//     }
//     return count;
// }

int subarraysXor(vector<int> &arr, int x)
{
    unordered_map<int, int> prefixXorCount;
    int n = arr.size();
    int count = 0;
    int xorSum = 0;

    for (int i = 0; i < n; i++)
    {
        xorSum = xorSum ^ arr[i];

        if (xorSum == x)
        {
            count++;
        }

        int reqXor = xorSum ^ x;

        if (prefixXorCount.find(reqXor) != prefixXorCount.end())
        {
            count = count + prefixXorCount[reqXor];
        }

        prefixXorCount[xorSum]++;
    }

    return count;
}