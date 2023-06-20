// Code :

#include <bits/stdc++.h>
vector<vector<int>> findTriplets(vector<int> arr, int n, int K)
{
    vector<vector<int>> ans;
    set<vector<int>> st;
	sort(arr.begin(), arr.end());

    for (int i = 0; i < n-2; i++)
    {
        int j = i + 1, k = n - 1;
        while (j < k)
        {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum == K)
            {
                vector<int> triplet = {arr[i], arr[j], arr[k]};
                sort(triplet.begin(), triplet.end());

                if (st.find(triplet) == st.end())
                {
                    ans.push_back(triplet);
                    st.insert(triplet);
                }
				j++;
            	k--;
            }
			else if(sum < K)
			{
				j++;
			}
			else
			{
				k--;
			}
        }
    }
	return ans;
}