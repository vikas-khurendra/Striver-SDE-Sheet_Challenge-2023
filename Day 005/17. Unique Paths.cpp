// Problem : 
You are present at point ‘A’ which is the top-left cell of an M X N matrix, your destination is point ‘B’, which is the bottom-right cell of the same matrix. Your task is to find the total number of unique paths from point ‘A’ to point ‘B’.In other words, you will be given the dimensions of the matrix as integers ‘M’ and ‘N’, your task is to find the total number of unique paths from the cell MATRIX[0][0] to MATRIX['M' - 1]['N' - 1].
To traverse in the matrix, you can either move Right or Down at each step. For example in a given point MATRIX[i] [j], you can move to either MATRIX[i + 1][j] or MATRIX[i][j + 1].

// Code
#include <bits/stdc++.h> 
int helper(int i, int j, int m, int n, vector<vector<int>> &dp)
{
	if(i == m-1 && j == n-1)
		return 1;

	if(i >= m || j >= n)
		return 0;

	if(dp[i][j] != -1)
		return dp[i][j];
	else 
		return dp[i][j] = helper(i+1, j, m, n, dp) + helper(i, j+1, m, n, dp);

}

int uniquePaths(int m, int n) {
	vector<vector<int>> dp(m, vector<int>(n, -1));
	return helper(0, 0, m, n, dp);
}