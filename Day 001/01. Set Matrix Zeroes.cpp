// Key Point : Here we store the index of row and column in a set, so that they are unique
// because if we get two zeroes in the same row (or col) then set will store the row or col number only once.

#include <bits/stdc++.h>

void setZeros(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
	set<int> row, col;

	for(int i=0; i<m; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            if(matrix[i][j] == 0)
            {
                row.insert(i);
                col.insert(j);
            }
        }
    }

    for(auto i : row)
    {
        for(int j=0; j<n; ++j)
        {
            matrix[i][j] = 0;
        }
    }

    for(auto j : col)
    {
        for(int k=0; k<m; ++k)
        {
            matrix[k][j] = 0;
        }
    }
}