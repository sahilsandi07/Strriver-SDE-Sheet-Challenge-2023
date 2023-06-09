#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n)
{
    // Write your code here.
    int c = 1;
    sort(arr.begin(), arr.end());

    if (n == 1)
        return 1;

    int i = 0;
    int j = 1;
    int temp = 1;
    vector<int> min;
    int m = 1;
    min.push_back(1);
    while (j < n)
    {
        if (arr[j] - arr[i] == 0)
        {
            i++;
            j++;
            continue;
        }

        else if (arr[j] - arr[i] == 1)
        {
            c++;
            temp = c;
        }
        else
        {

            min.push_back(temp);
            m = *max_element(min.begin(), min.end());

            temp = 1;
            c = 1;
        }

        i++;
        j++;
    }
    if (m > temp)
        return m;
    else
        return temp;
}