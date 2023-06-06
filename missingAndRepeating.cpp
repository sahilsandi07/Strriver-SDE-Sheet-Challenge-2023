#include <bits/stdc++.h>

using namespace std;

pair<int, int> missingAndRepeating(vector<int>& arr, int n) {
    unordered_map<int, int> countMap;

    int missingNum = 0;
    int repeatingNum = 0;

    // Count the occurrences of each element
    for (int i = 0; i < n; i++) {
        countMap[arr[i]]++;
    }

    // Find the missing and repeating numbers
    for (int i = 1; i <= n; i++) {
        if (countMap.find(i) == countMap.end()) {
            missingNum = i;
        } else if (countMap[i] == 2) {
            repeatingNum = i;
        }
    }

    return make_pair(missingNum, repeatingNum);
}

