******************** LeetCode : Only Index is returned ********************

// Problem :

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

// Code :

class Solution {
public:
    // vector<int> twoSum(vector<int> & nums, int target)
    // {
    //     map<int, int> myMap;
    //     int n = nums.size();
    //     for (int i = 0; i < n; i++)
    //     {
    //         int a = nums[i];
    //         int moreNeeded = target - a;
    //         if (myMap.find(moreNeeded) != myMap.end())
    //         {
    //             return {myMap[moreNeeded],i};
    //         }
    //         myMap[a] = i;
    //     }
    //     return { -1, -1 };
    // }

    // If we are not allowed to use Hashmap
    
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


******************** Coding Ninjas : Value at Index is returned ********************

// Problem :

You are given an integer array 'ARR' of size 'N' and an integer 'S'. Your task is to return the list of all pairs of elements such that each sum of elements of each pair equals 'S'.
Note:
Each pair should be sorted i.e the first value should be less than or equals to the second value. 

Return the list of pairs sorted in non-decreasing order of their first value. In case if two pairs have the same first value, the pair with a smaller second value should come first.

// Code : 

#include <bits/stdc++.h> 
using namespace std;

vector<vector<int>> pairSum(vector<int> &arr, int S){
    vector<vector<int>> ans;
    unordered_map<int, int> myMap;
    int n = arr.size();

    sort(arr.begin(), arr.end()); // Sort the array in ascending order

    for (int i = 0; i < n; i++) {
        int a = arr[i];
        int moreNeeded = S - a;
        if (myMap[moreNeeded] > 0) {
            for (int j = 0; j < myMap[moreNeeded]; j++) {
                // ans.push_back({a, moreNeeded});
                vector<int> temp;
                temp.push_back(a);
                temp.push_back(moreNeeded);
                sort(temp.begin(), temp.end());
                ans.push_back(temp);
            }
        }
        myMap[a]++;
    }
    sort(ans.begin(), ans.end());
    return ans;
}
