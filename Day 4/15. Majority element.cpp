#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {

	unordered_map<int, int> freq;

	for(int i=0; i<n; i++)
	{
		freq[arr[i]]++;
	}

	for(const auto& pair : freq)
	{
		if(pair.second > floor(n/2))
		{
			return pair.first;
		}
	}
	return -1;
}