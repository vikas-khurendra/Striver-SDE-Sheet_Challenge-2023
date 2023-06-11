#include <bits/stdc++.h>

vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> mergedIntervals;
    mergedIntervals.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); i++) {
        // Get the start and end points of the current interval
        int currStart = intervals[i][0];
        int currEnd = intervals[i][1];

        // Get the end point of the last interval in the mergedIntervals vector
        int mergedEnd = mergedIntervals.back()[1];

        if (currStart <= mergedEnd) {
            mergedIntervals.back()[1] = max(currEnd, mergedEnd);
        } else {
            mergedIntervals.push_back(intervals[i]);
        }
    }

    return mergedIntervals;
}
