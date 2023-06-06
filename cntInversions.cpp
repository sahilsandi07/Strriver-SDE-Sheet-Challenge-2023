#include <bits/stdc++.h>
using namespace std;
long long merge(long long *arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    long long* L = new long long[n1];
    long long* R = new long long[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    long long inversions = 0;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
            inversions += n1 - i; // Count inversions
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;

    return inversions;
}

long long mergeSort(long long *arr, int left, int right) {
    long long inversions = 0;

    if (left < right) {
        int mid = left + (right - left) / 2;
        inversions += mergeSort(arr, left, mid);
        inversions += mergeSort(arr, mid + 1, right);
        inversions += merge(arr, left, mid, right);
    }

    return inversions;
}

long long getInversions(long long *arr, int n) {
    return mergeSort(arr, 0, n - 1);
}
