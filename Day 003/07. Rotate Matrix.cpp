Problem: Rotate Matrix By 90 Degree (Leetcode)

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();

        for(int i=0; i<size-1; i++)
        {
            for(int j=i+1; j<size; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int i=0; i<size; i++)
        {
            for(int j=0; j<size/2; j++)
            {
                swap(matrix[i][j], matrix[i][size-j-1]);
            }
            // reverse(matrix[i].begin(), matrix[i].end());
        }

    }
};

***********************************************************************
Problem: Rotate Matrix Clockwise (Coding Ninjas)

#include <bits/stdc++.h>

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    int top = 0, bot = n-1, left = 0, right = m-1;
    
    while(top < bot && left < right)
    {
        int temp = mat[top][left];
        
        for(int i=top; i<bot; i++)
        {
            mat[i][left] = mat[i+1][left];
        }

        for(int i=left; i<right; i++)
        {
            mat[bot][i] = mat[bot][i+1];
        }

        for(int i=bot; i>top; i--)
        {
            mat[i][right] = mat[i-1][right];
        }
        
        for(int i=right; i>left; i--)
        {
            mat[top][i] = mat[top][i-1];
        }
        
        mat[top][left+1] = temp;
        top++, bot--, left++, right--;
    }

}