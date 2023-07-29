#include <iostream>
#include <vector>
using namespace std;

// Function to find the minimum element in the vector recursively
int minElement(vector<int> &arr, int n) {
    // Base case: If the vector is empty (n == 0), return INT_MAX (a very large value)
    if (n == 0) {
        return INT_MAX; // Use INT_MAX as the base case value
    }

    // Recursively find the minimum of the current element and the minimum of the rest of the elements
    return min(arr[n - 1], minElement(arr, n - 1));
}

int main() {
    int n;
    cin >> n;

    // Input validation: Check if n is non-positive, which is an invalid input
    if (n <= 0) {
        cout << "Invalid input. Please enter a positive value for n." << endl;
        return 1; // Return a non-zero value to indicate an error
    }

    // Create a vector of integers of size n to store the elements
    vector<int> arr(n, 0);

    // Input the elements of the vector
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Call the minElement function to find the minimum element in the vector
    cout << "Minimum Element: " << minElement(arr, n) << endl;

    return 0; // Return 0 to indicate successful execution
}
