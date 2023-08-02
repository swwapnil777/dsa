#include <bits/stdc++.h>
using namespace std;

// Function to find the first occurrence of 'key' in the vector 'v'
int firstOccurrence(vector<int> &v, int i, int key, int n) {
    // If we have reached the end of the vector without finding 'key', return -1
    if (i == n) {
        return -1;
    }

    // If the current element is equal to 'key', we have found the first occurrence
    if (v[i] == key) {
        return i;
    }

    // Recursively search for 'key' in the rest of the vector
    return firstOccurrence(v, i + 1, key, n);
}

// Function to find the last occurrence of 'key' in the vector 'v'
int lastOccurrence(vector<int> &v, int i, int key, int n) {
    // If we have reached the end of the vector, return -1
    if (i == n) {
        return -1;
    }

    // Recursively search for 'key' in the rest of the vector
    int next_occurrence = lastOccurrence(v, i + 1, key, n);

    // If 'key' is found later in the vector, update the last occurrence position
    if (next_occurrence != -1) {
        return next_occurrence;
    }

    // If the current element is equal to 'key', we have found the last occurrence
    if (v[i] == key) {
        return i;
    }

    // 'key' was not found in the rest of the vector, return -1
    return -1;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    int key;
    cin >> key;

    // Find the first occurrence of 'key' in the vector 'v'
    int first = firstOccurrence(v, 0, key, n);
    cout << "First Occurrence: " << first << endl;

    // Find the last occurrence of 'key' in the vector 'v'
    int last = lastOccurrence(v, 0, key, n);
    cout << "Last Occurrence: " << last << endl;

    return 0;
}
