#include <iostream>
using namespace std;

const int MOD = 1000000007;

// Function to calculate the power of a number 'n' raised to 'r' using recursion
int powerOfNumber(int n, int r) {
    // Base case: when 'r' becomes 0, any number raised to power 0 is 1
    if (r == 0) {
        return 1;
    }

    // Recursive step: calculate n * (n^(r-1)) to get the power of 'n' raised to 'r'
    long long int temp = powerOfNumber(n, r - 1);
    return (n * temp) % MOD;
}

int main() {
    int n, r;

    // Input 'n' and 'r' from the user
    cin >> n >> r;

    // Call the 'powerOfNumber' function with the given 'n' and 'r', taking modulo 10^9 + 7, and print the result
    cout << powerOfNumber(n, r) << endl;

    return 0;
}
