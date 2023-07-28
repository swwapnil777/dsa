#include <iostream>
#include <vector>
using namespace std;

// Function to calculate the sum of elements in the array using recursion
int sumOfArray(vector<int> &arr, int n)
{
    
    // Base case: if 'n' is less than or equal to 0, the array is empty or invalid, so return 0.
    if (n <= 0)
    {
        return 0;
    }

    // Recursive step: Add the current element at index (n-1) to the sum of the remaining elements (from index 0 to n-2).
    return arr[n - 1] + sumOfArray(arr, n - 1);
}

int main()
{
    int n;
    cin >> n;

    // Create a vector to store the array elements
    vector<int> arr(n);

    // Input the elements of the array from the user
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Call the 'sumOfArray' function with the vector 'arr' and its size 'n' to calculate the sum of array elements
    cout << sumOfArray(arr, arr.size());

    return 0;
}
