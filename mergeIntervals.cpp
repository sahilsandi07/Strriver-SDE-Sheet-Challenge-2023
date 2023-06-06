#include <bits/stdc++.h> 

using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
    // Sort the intervals based on the start points
    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    });
    
    vector<vector<int>> mergedIntervals;
    
    // Initialize the mergedIntervals with the first interval
    mergedIntervals.push_back(intervals[0]);
    
    for (int i = 1; i < intervals.size(); i++) {
        vector<int>& prev = mergedIntervals.back();
        vector<int>& curr = intervals[i];
        
        // If the current interval overlaps with the previous interval, merge them
        if (curr[0] <= prev[1]) {
            prev[1] = max(prev[1], curr[1]);
        } else {
            // If there is no overlap, add the current interval to the mergedIntervals
            mergedIntervals.push_back(curr);
        }
    }
    
    return mergedIntervals;
}
