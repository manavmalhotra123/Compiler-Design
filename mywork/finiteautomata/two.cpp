#include <iostream>
#include <string>

using namespace std;

bool isMemberOfLanguage1(const string& input, size_t index) {
    if (index >= input.length()) {
        return true;
    }

    char currentChar = input[index];
    if (index % 2 == 0) {
        // Even position, expecting 'a'
        if (currentChar != 'a') {
            return false;
        }
    } else {
        // Odd position, expecting 'b'
        if (currentChar != 'b') {
            return false;
        }
    }

    return isMemberOfLanguage1(input, index + 1);
}

int main() {
    string input;

    cout << "Enter a string: ";
    cin >> input;

    if (input.length() % 2 == 0 && isMemberOfLanguage1(input, 0))
        cout << "The string belongs to (ab)+.\n";
    else
        cout << "The string does not belong to (ab)+.\n";

    return 0;
}
