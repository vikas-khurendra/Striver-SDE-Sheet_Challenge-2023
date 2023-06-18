#include <bits/stdc++.h> 

vector<int> nextPermutation(vector<int> &arr, int n)
{
    // 2 7 6 1 5 9 8 4 3 <----
    // 0 1 2 3 4 5 6 7 8 Indexes

    int min = -1;
    for(int i = n-2; i>=0; i--)
    {
        if(arr[i] < arr[i+1])
        {
            min = i;
            break;
        }
    }

    //if min = -1, i.e. all the elements are sorted
    //wrap around and start from the smallest permutation

    if(min == -1)
    {
        reverse(arr.begin(), arr.end());
        return arr;
    }

    for(int i=n-1; i>=0; i--)
    {
        if(arr[i] > arr[min])
        {
            swap(arr[i], arr[min]);
            break;
        }
    }

    sort(arr.begin() + min + 1, arr.end());
    return arr;
}