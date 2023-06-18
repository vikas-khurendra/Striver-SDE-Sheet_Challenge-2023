// Problem :

You are given an unsorted array/list 'ARR' of 'N' integers. Your task is to return the length of the longest consecutive sequence.
The consecutive sequence is in the form ['NUM', 'NUM' + 1, 'NUM' + 2, ..., 'NUM' + L] where 'NUM' is the starting integer of the sequence and 'L' + 1 is the length of the sequence.
Note:
If there are any duplicates in the given array we will count only one of them in the consecutive sequence.
For Example-
For the given 'ARR' [9,5,4,9,10,10,6].

Output = 3
The longest consecutive sequence is [4,5,6].

// Code :

#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {

    sort(arr.begin(), arr.end());
    int maxLength = 0;
    int currLength = 1;

    if (n == 0) { // Check if length of array is not null
        return 0;
    }
    
    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1] + 1) {
            currLength++;
        } else if (arr[i] == arr[i - 1]) {
            continue;  // Skip this iteration if the elements are equal
        } else {
            maxLength = max(maxLength, currLength);
            currLength = 1;
        }
    }
    
    // Check if the longest sequence ends at the last element
    maxLength = max(maxLength, currLength); 
    
    return maxLength;
}
