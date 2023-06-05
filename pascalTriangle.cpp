#include <bits/stdc++.h>
using namespace std;

vector<vector<long long int>> printPascal(int n)
{
    vector<vector<long long int>> pascal(n, vector<long long int>());

    for (int i = 0; i < n; i++)
    {
        pascal[i].resize(i + 1); // Resize the row to the current row size

        pascal[i][0] = 1; // Set the first element of each row as 1

        for (int j = 1; j < i; j++)
        {
            // Calculate the element by summing the corresponding elements from the previous row
            pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
        }

        pascal[i][i] = 1; // Set the last element of each row as 1
    }

    return pascal;
}