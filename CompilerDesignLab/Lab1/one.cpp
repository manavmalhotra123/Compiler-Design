// 11 august 2023 
// reading the text from the input file and counting words,characters and sentences in it.

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

int charactercount(string input) {
    return input.length();
}

int countWords(const string &text) {
    int count = 0;

    for (size_t i = 0; i < text.length(); i++) {
        if (text[i] != ' ') {
            count++;
            while (i < text.length() && text[i] != ' ') {
                i++;
            }
        }
    }
    return count;
}

int countsentences(const string &input) {
    int count = 0;

    for (int i = 0; i < input.length(); i++) {
        if (input[i] == '.' || input[i] == '?') {
            count++;
        }
    }

    return count;
}

string readFromFile(string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Failed to open the file: " << filename <<endl;
        return "";
    }

    string content = "";
    string line;
    while (getline(file, line)) {
        content += line + "\n";
    }

    return content;
}

int main() {
    string filename = "input.txt"; // Change this to the actual filename
    string text = readFromFile(filename);

    if (text.empty()) {
        return 1;
    }

    int wordcount = countWords(text);
    cout << "Number of words in the text is " << wordcount << endl;

    int sentence = countsentences(text);
    cout << "Number of sentences in the text is " << sentence << endl;

    int charcount = charactercount(text);
    cout << "Number of characters in the text is " << charcount << endl;

    return 0;
}
