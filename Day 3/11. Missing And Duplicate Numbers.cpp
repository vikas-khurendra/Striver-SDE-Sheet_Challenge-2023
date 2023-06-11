//Problem : Coding Ninjas Missing and Duplicate number where Number start from 1 - N

#include <bits/stdc++.h>

pair<int, int> missingAndRepeating(vector<int> &arr, int n)
{
    pair<int, int> ans;

	// cyclic sort
	int i=0;
	while(i<n)
	{
		int correctInd = arr[i]-1;
		if(arr[i] != arr[correctInd])
		{
			swap(arr[i], arr[correctInd]);
		}
		else
		{
			i++;
		}
	}

    // finding missing  and duplicate number
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] != i + 1) // here i + 1 is because array start from 1 not 0
        {
            ans.first = (i + 1);
			ans.second = (arr[i]);
        }
    }
    return ans;
}

***************************************************************************************
//Problem : LeetCode Missing Number where Number start from 0 - N

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        // Applying cyclic sort
        int i = 0;
        while (i < nums.size())
        {
            int correctInd = nums[i];
            if (nums[i] < nums.size() && nums[i] != nums[correctInd])
            {
                swap(nums[i], nums[correctInd]);
            }
            else
            {
                i++;
            }
        }

        // Finding missing number
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != i)
            {
                return i;
            }
        }

        return nums.size();
    }
};

