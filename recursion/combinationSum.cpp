#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Helper function for finding combination sum using backtracking
void helper(vector<vector<int>>& ans, int sumTillNow, vector<int>& subSets, vector<int>& arr, int target, int i) {
    // If the sum reaches the target, add the subset to the result and return
    if (sumTillNow == target) {
        ans.push_back(subSets);
        return;
    }
    
    // If the sum exceeds the target or we have reached the end of the array, return
    if (sumTillNow > target || i >= arr.size()) {
        return;
    }
    
    // Include the current element in the subset and continue exploring
    subSets.push_back(arr[i]);
    helper(ans, sumTillNow + arr[i], subSets, arr, target, i);
    subSets.pop_back(); // Backtrack by removing the current element
    
    // Exclude the current element and continue exploring with the next element
    helper(ans, sumTillNow, subSets, arr, target, i + 1);
}

// Function to find all combinations of numbers that add up to the target
vector<vector<int>> combinationSum(vector<int>& arr, int target) {
    vector<vector<int>> ans;
    vector<int> subSets;
    sort(arr.begin(), arr.end()); // Sorting the input array to ensure the subsets are in ascending order
    helper(ans, 0, subSets, arr, target, 0);
    return ans;
}

// Main function for testing the combinationSum function
int main() {
    vector<int> arr = {2, 3, 5};
    int target = 8;
    vector<vector<int>> ans = combinationSum(arr, target);

    // Displaying the results
    for (const vector<int>& subSet : ans) {
        cout << "[";
        for (int i = 0; i < subSet.size(); ++i) {
            cout << subSet[i];
            if (i < subSet.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}
