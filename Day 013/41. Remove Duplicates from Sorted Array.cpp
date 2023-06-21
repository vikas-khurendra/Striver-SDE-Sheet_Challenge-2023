********************* Brute Force Approach TC = O(nlogn + n), SC = O(n) ***********************

// Code : Using Stack

#include<bits/stdc++.h>

int removeDuplicates(vector<int> &arr, int n)
{
    set<int> st;

    for (int i = 0; i < n; i++)
    {
        st.insert(arr[i]);
    }

    int index = 0;
    for (const auto &it : st)
    {
        arr[index] = it;
		index++;
    }
    return index;
}

Time Complexity: O(nlogn + n). Insertion in set + Traversing set.
Space Complexity: O(n). Extra space is required for Set.

********************* Optimal Approach TC = O(n), SC = O(1) ***********************

// Code : Two Pointer Approach

#include<bits/stdc++.h>

int removeDuplicates(vector<int> &arr, int n)
{
    int prevNum = arr[0];
    int index = 1;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] != prevNum)
        {
            arr[index] = arr[i];
			prevNum = arr[i];
            index++;
        }
    }
    return index;
}

Time Complexity: O(n). Traversing array once.
Space Complexity: O(1). Extra space is not required.