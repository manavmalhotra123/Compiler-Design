#include <iostream>
#include <string>

using namespace std;

bool isMemberOfLanguage5(const string& input, size_t start, size_t end) {
    if (start >= end) {
        return true;
    }

    if (input[start] != input[end]) {
        return false;
    }

    return isMemberOfLanguage5(input, start + 1, end - 1);
}

int main() {
    string input;

    cout << "Enter a string: ";
    cin >> input;

    if (isMemberOfLanguage5(input, 0, input.length() - 1))
        cout << "The string is a palindrome.\n";
    else
        cout << "The string is not a palindrome.\n";

    return 0;
}
