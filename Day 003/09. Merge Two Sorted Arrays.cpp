#include <bits/stdc++.h>

vector<int> ninjaAndSortedArrays(vector<int> &arr1, vector<int> &arr2, int m, int n)
{
    vector<int> ans;
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (arr1[i] < arr2[j])
        {
            ans.push_back(arr1[i]);
            i++;
        }
        else
        {
            ans.push_back(arr2[j]);
            j++;
        }
    }

    while (i < m)
    {
        ans.push_back(arr1[i]);
        i++;
    }
    while (j < n)
    {
        ans.push_back(arr2[j]);
        j++;
    }

    for (int i = 0; i < m + n; i++)
    {
        arr1[i] = ans[i];
    }

    return arr1;
}