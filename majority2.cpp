#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{
    vector<int> result;

    if (arr.empty()) {
        return result;  // If the input array is empty, return an empty result vector
    }

    int candidate1 = arr[0];  // Assume the first element as the first candidate
    int count1 = 0;           // Initialize count of the first candidate as 0

    int candidate2 = arr[0];  // Assume the first element as the second candidate
    int count2 = 0;           // Initialize count of the second candidate as 0

    // Find the potential majority candidates
    for (int num : arr) {
        if (num == candidate1) {
            count1++;  // Increment count if current element is equal to the first candidate
        } else if (num == candidate2) {
            count2++;  // Increment count if current element is equal to the second candidate
        } else if (count1 == 0) {
            candidate1 = num;  // Update the first candidate if count1 becomes 0
            count1 = 1;        // Reset count1 to 1
        } else if (count2 == 0) {
            candidate2 = num;  // Update the second candidate if count2 becomes 0
            count2 = 1;        // Reset count2 to 1
        } else {
            count1--;  // Decrement count1 if the current element is different from both candidates
            count2--;  // Decrement count2 if the current element is different from both candidates
        }
    }

    // Verify if the candidates are indeed the majority elements
    count1 = count2 = 0;
    for (int num : arr) {
        if (num == candidate1) {
            count1++;
        } else if (num == candidate2) {
            count2++;
        }
    }

    if (count1 > arr.size() / 3) {
        result.push_back(candidate1);
    }
    if (count2 > arr.size() / 3) {
        result.push_back(candidate2);
    }

    return result;
}