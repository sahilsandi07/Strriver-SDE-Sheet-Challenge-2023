int findMajorityElement(int arr[], int n) {
    int majorityElement = arr[0];  // Assume the first element as the majority element
    int count = 1;                // Initialize count of majority element as 1

    // Find the majority element
    for (int i = 1; i < n; i++) {
        if (arr[i] == majorityElement) {
            count++;  // Increment count if current element is equal to the majority element
        } else {
            count--;  // Decrement count if current element is not equal to the majority element
        }

        if (count == 0) {
            majorityElement = arr[i];  // Update the majority element if count becomes 0
            count = 1;                 // Reset count to 1
        }
    }

    // Verify if the majority element is indeed the majority
    count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == majorityElement) {
            count++;
        }
    }
    if (count > n / 2) {
        return majorityElement;  // Return the majority element
    }

    return -1;  // Return -1 if there is no majority element
}