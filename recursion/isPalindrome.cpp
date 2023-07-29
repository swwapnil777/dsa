#include <iostream>
using namespace std;

// Function to check if a given string is a palindrome recursively
bool isPalindrome(string s, int i, int j) {
    // Base case: If i crosses j (i > j), it means all characters have been compared, return true (it is a palindrome)
    if (i > j) {
        return true;
    }

    // Recursive step: Check if characters at positions i and j are equal and continue comparing the rest of the string
    return s[i] == s[j] && isPalindrome(s, i + 1, j - 1);
}

int main() {
    string s;
    cin >> s;

    // Call the isPalindrome function with starting indices 0 and s.size() - 1 (first and last characters of the string)
    if (isPalindrome(s, 0, s.size() - 1)) {
        cout << "Palindrome" << endl;
    } else {
        cout << "Not Palindrome" << endl;
    }

    return 0;
}
