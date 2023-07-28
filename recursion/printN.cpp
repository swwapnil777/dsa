#include <iostream>
using namespace std;

// Recursive function to print numbers from 1 to n in ascending order
void print(int n)
{
    // Base case: When n becomes 0, stop the recursion
    if (n == 0)
    {
        return;
    }

    // Recursive step: Print the numbers from 1 to (n-1) using recursion
    print(n - 1);

    // Print the current number after the recursive call (ascending order)
    cout << n << " ";
}

int main()
{
    int n;

    // Input 'n' from the user
    cin >> n;

    // Call the 'print' function with the given 'n' to print numbers from 1 to 'n'
    cout << "Numbers from 1 to " << n << " in ascending order: ";
    print(n);

    return 0;
}
