#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include <cctype>

using namespace std;

string toLowerCase(const string& str) {
    string lowerStr = str;
    for (char& c : lowerStr) {
        c = tolower(c);
    }
    return lowerStr;
}

string removePunctuation(const string& str) {
    string cleanedStr;
    for (char c : str) {
        if (!ispunct(c)) {
            cleanedStr += c;
        }
    }
    return cleanedStr;
}

int main() {
    string paragraph;
    cout << "Enter a paragraph: ";
    getline(cin, paragraph);

    paragraph = toLowerCase(paragraph);

    stringstream ss(paragraph);
    string word;
    map<string, int> wordCount;

    while (ss >> word) {
        word = removePunctuation(word);
        wordCount[word]++;
    }

    cout << "Word frequencies:" << endl;
    for (const auto& pair : wordCount) {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}
