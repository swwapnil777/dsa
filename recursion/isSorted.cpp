#include <iostream>
#include <vector>
using namespace std;

// Recursive function to check if the given array is sorted or not.
// Arguments:
// - arr: The vector of integers to check for sorting.
// - i: The current index being checked.
// - n: The total number of elements in the vector.
// Returns:
// - true if the array is sorted, false otherwise.
bool isSorted(vector<int> &arr, int i, int n)
{
    // Base case: If the index reaches the last element, the array is sorted.
    if (i == n - 1)
    {
        return true;
    }

    // Check if the current element is greater than the next element.
    // If so, the array is not sorted.
    if (arr[i] > arr[i + 1])
    {
        return false;
    }

    // Recursive call to check the next pair of elements.
    return isSorted(arr, i + 1, n);
}

int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n, 0);
    cout << "Enter " << n << " integers in non-decreasing order: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    if (isSorted(arr, 0, n))
    {
        cout << "The array is sorted." << endl;
    }
    else
    {
        cout << "The array is not sorted." << endl;
    }

    return 0;
}
