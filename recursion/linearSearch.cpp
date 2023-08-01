#include <bits/stdc++.h>
using namespace std;

// Recursive linear search function to find the 'key' in the vector 'arr'
// Arguments:
// - arr: The vector of integers to search through.
// - i: The current index being checked in the vector.
// - n: The total number of elements in the vector.
// - key: The value to be searched in the vector.
// Returns:
// - true if the 'key' is found in the vector, false otherwise.
bool linearSearch(vector<int> &arr, int i, int n, int key) {
    // Base case: If we have reached the last index, return false as the 'key' is not found.
    if (i == n - 1) {
        return false;
    }

    // If the element at the current index 'i' is equal to the 'key', return true.
    if (arr[i] == key) {
        return true;
    }

    // Recursive call: Move to the next index and search for the 'key'.
    return linearSearch(arr, i + 1, n, key);
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n, 0);
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int key;
    cout << "Enter the key to search for: ";
    cin >> key;

    if (linearSearch(arr, 0, n, key)) {
        cout << "Found" << endl;
    } else {
        cout << "Not Found" << endl;
    }

    return 0;
}
