#include <bits/stdc++.h>
using namespace std;

// Function to reverse the characters in a string from index 'i' to 'j' (inclusive)
void reverse(string &s, int i, int j)
{
    // Base case: When 'i' becomes equal to 'j', no more characters to swap, so return
    if (i >= j)
    {
        return;
    }

    // Recursive step: Swap the characters at 'i' and 'j', then continue reversing the substring in between
    swap(s[i], s[j]);

    // Recursive call to reverse the substring between 'i+1' and 'j-1'
    reverse(s, i + 1, j - 1);
}

int main()
{
    string s;
    cin >> s;

    // Call the 'reverse' function to reverse the entire string 's'
    reverse(s, 0, s.size() - 1);

    // Print the reversed string
    cout << "Reversed string: " << s << endl;

    return 0;
}
