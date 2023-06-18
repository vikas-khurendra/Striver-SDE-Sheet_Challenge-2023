// Code :

#include <bits/stdc++.h> 

// int uniqueSubstrings(string input)
// {
//     unordered_map<string, int> mp;
//     int currLength = 0;
//     int maxLength = 0;
//     int n = input.length();

//     for(int i=0; i<n; i++)
//     {
//         // string s = string(1, input[i]);
//         string s;
//         s.push_back(input[i]);

//         if(mp.find(s) != mp.end())
//         {
//             maxLength = max(maxLength, currLength);
//             currLength = 1;
//             mp.clear();
//         }
//         else
//         {
//             currLength++;
//         }
//         mp[s]++;
//     }
//     return maxLength;
// }

int uniqueSubstrings(string input)
{
    // a b c a a b c d b a
    // 0 1 2 3 4 5 6 7 8 9

    unordered_map<char, int> mp;
    int maxLength = 0;
    int left = 0;
    int right = 0;
    int n = input.size();

    while(right < n)
    {
        char c = input[right];

        if(mp.find(c) != mp.end())
        {
            left = max(left, mp[c]+1);
        }
        mp[c] = right;
        maxLength = max(maxLength, right - left + 1);
        right++;
    }
    return maxLength;
}