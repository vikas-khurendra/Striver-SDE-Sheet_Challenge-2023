// Coding Ninjas :

#include <bits/stdc++.h>

int getLongestSubarray(std::vector<int> &nums, int k) {
    map<long long, int> prefixSumMap;
    int n = nums.size();
    int maxLength = 0;
    long long sum = 0;

    for (int i = 0; i < n; i++) {
        sum += nums[i];

        if (sum == k) {
            maxLength = max(maxLength, i + 1);
        }

        long long sumNeeded = sum - k;

        if (prefixSumMap.find(sumNeeded) != prefixSumMap.end()) {
            int currLength = i - prefixSumMap[sumNeeded];
            maxLength = std::max(maxLength, currLength);
        }

        if (prefixSumMap.find(sum) == prefixSumMap.end()) {
            prefixSumMap[sum] = i;
        }
    }
    return maxLength;
}


*****************************************************************************************************************

// Leetcode :
 
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

// Code :

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (n == 0)
            return 0;

        unordered_map<int, int> prefixSumMap; // Key = PrefixSUM, ValumaxLength of PrefixSUM.
        int sum = 0;
        int i = 0;
        int maxLength = 0;

        for (int i = 0; i < n; i++)
        {
            sum += nums[i];

            if (sum == k) // We found a new subarray with sum = k
                maxLength += 1;
            
            int moreNeeded = sum - k;

            if (prefixSumMap.find(moreNeeded) != prefixSumMap.end())
                maxLength = maxLength + prefixSumMap[moreNeeded];

            prefixSumMap[sum] += 1;
        }
        return maxLength;
    }
};
