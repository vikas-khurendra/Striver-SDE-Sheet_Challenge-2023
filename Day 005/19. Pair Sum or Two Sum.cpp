// Coding Ninjas Pair Sum :

You are given an integer array 'ARR' of size 'N' and an integer 'S'. Your task is to return the list of all pairs of elements such that each sum of elements of each pair equals 'S'.
Note:
Each pair should be sorted i.e the first value should be less than or equals to the second value. 

Return the list of pairs sorted in non-decreasing order of their first value. In case if two pairs have the same first value, the pair with a smaller second value should come first.

// Code :

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> pairSum(vector<int> &arr, int s)
{
    sort(arr.begin(), arr.end());
    int i = 0;
    int j = arr.size() - 1;
    vector<vector<int>> ans;

    while (i < arr.size())
    {
        if (j == i)
        {
            j = arr.size() - 1;
            i++;
        }

        if (arr[i] + arr[j] == s)
        {
            vector<int> temp;
            temp.push_back(arr[i]);
            temp.push_back(arr[j]);
            ans.push_back(temp);
            j--;
        }
        else
        {
            if (j == i)
            {
                j = arr.size() - 1;
                i++;
            }
            else
            {
                j--;
            }
        }
    }

    return ans;
}


*********************************************************************************************************

// LeetCode :

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

// Code :

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int>> vp;
        for (int i = 0; i < n; i++) {
            vp.push_back({nums[i], i});
        }

        sort(vp.begin(), vp.end());
        int i = 0, j = n - 1;
        vector<int> result; // Separate vector to store the first return value
        while (i < j) {
            int sum = vp[i].first + vp[j].first;
            if (sum == target) {
                result = {vp[i].second, vp[j].second};
                // result.push_back(vp[i].second);
                // result.push_back(vp[j].second);
                break; // Found the result, exit the loop
            }
            if (sum < target) {
                i++;
            } else {
                j--;
            }
        }
        return result; // Return the stored result
    }
};
