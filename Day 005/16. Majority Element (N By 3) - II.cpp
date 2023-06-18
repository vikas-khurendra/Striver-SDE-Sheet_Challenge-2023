#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{
    unordered_map<int, int> freq;
    vector<int> majorityList;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }

    for (const auto &pair : freq)
    {
        if (pair.second > floor(n / 3))
        {
            majorityList.push_back(pair.first);
        }
    }
    return majorityList;
}