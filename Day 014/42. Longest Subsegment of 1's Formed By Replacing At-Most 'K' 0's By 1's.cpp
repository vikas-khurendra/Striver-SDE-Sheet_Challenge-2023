// Code :

#include <iostream>
#include <vector>
using namespace std;

int longestSubSeg(vector<int> arr, int n, int k)
{
    int left = 0;
    int right = 0;
    int count0 = 0;
    int maxLength = 0;

    while (right < n)
    {
        if (arr[right] == 0)
        {
            count0++;
        }

        while (count0 > k)
        {
            if (arr[left] == 0)
            {
                count0--;
            }
            left++;
        }

        int currLength = right - left + 1;
        maxLength = max(maxLength, currLength);
        right++;
    }

    return maxLength;
}