#include <iostream>
#include <string>

using namespace std;

bool isMemberOfLanguage(const string& input, int index) {
    // Base case: If the index is beyond the string length, return true
    if (index >= input.length()) {
        return true;
    }

    // Check if the current character is 'a' or 'b'
    char currentChar = input[index];
    if (currentChar == 'a' || currentChar == 'b') {
        // Make a recursive call for the rest of the string
        return isMemberOfLanguage(input, index + 1);
    } else {
        // If any other character is encountered, return false
        return false;
    }
}

int main() {
    string input;

    cout << "Enter a string: ";
    cin >> input;

    if (isMemberOfLanguage(input, 0))
        cout << "The string belongs to (a+b)*.\n";
    else
        cout << "The string does not belong to (a+b)*.\n";

    return 0;
}
