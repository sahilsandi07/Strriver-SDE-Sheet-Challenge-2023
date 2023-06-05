#include <bits/stdc++.h>
using namespace std;

void setZeros(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    // Use two arrays to keep track of rows and columns to be zeroed
    vector<int> zeroRows(rows, 0);
    vector<int> zeroCols(cols, 0);

    // Find the cells with value zero and mark their rows and columns
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0) {
                zeroRows[i] = 1;
                zeroCols[j] = 1;
            }
        }
    }

    // Set the corresponding rows to zero
    for (int i = 0; i < rows; i++) {
        if (zeroRows[i] == 1) {
            fill(matrix[i].begin(), matrix[i].end(), 0);
        }
    }

    // Set the corresponding columns to zero
    for (int j = 0; j < cols; j++) {
        if (zeroCols[j] == 1) {
            for (int i = 0; i < rows; i++) {
                matrix[i][j] = 0;
            }
        }
    }
}
