// 🌸 Hacktoberfest DSA 2025 Contribution
// Problem: Length of Last Word
// Language: C++
// Description: Returns the length of the last word in a given string.
// Author: Japinder Kaur
// GitHub: https://github.com/<your-username>

// 🎯 Example:
// Input: "Hello World"
// Output: 5

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size() - 1;
        while (i >= 0 && s[i] == ' ') --i;   // skip trailing spaces
        int len = 0;
        while (i >= 0 && s[i] != ' ') {      // count last word
            ++len;
            --i;
        }
        return len;
    }
};

// 🧪 Test Case
int main() {
    string input;
    cout << "Enter a sentence: ";
    getline(cin, input);

    Solution sol;
    cout << "Length of last word: " << sol.lengthOfLastWord(input) << endl;

    return 0;
}
