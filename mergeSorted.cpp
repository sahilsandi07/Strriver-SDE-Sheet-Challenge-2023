#include <bits/stdc++.h>

using namespace std;

vector<int> ninjaAndSortedArrays(const vector<int>& arr1, const vector<int>& arr2, int m, int n) {
    vector<int> merged(m + n); // Resulting merged array
    int i = 0; // Pointer for arr1
    int j = 0; // Pointer for arr2
    int k = 0; // Pointer for merged array

    // Merge the two arrays
    while (i < m && j < n) {
        if (arr1[i] <= arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }

    // Copy remaining elements from arr1, if any
    while (i < m) {
        merged[k++] = arr1[i++];
    }

    // Copy remaining elements from arr2, if any
    while (j < n) {
        merged[k++] = arr2[j++];
    }

    return merged;
}