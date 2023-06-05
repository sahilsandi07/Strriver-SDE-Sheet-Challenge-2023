#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n) {
    long long maxSoFar = LLONG_MIN;
    long long maxEndingHere = 0;

    for (int i = 0; i < n; ++i) {
        maxEndingHere += arr[i];

        if (maxSoFar < maxEndingHere)
            maxSoFar = maxEndingHere;

        if (maxEndingHere < 0)
            maxEndingHere = 0;
    }

    if (maxSoFar < 0)
        return 0;

    return maxSoFar;
}