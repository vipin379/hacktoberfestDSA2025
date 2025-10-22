#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Node {
public:
    unordered_map<char, Node*> children;
    Node() {}
};

class Trie {
    Node* root;
    int nodeCount; // counts nodes in Trie

public:
    Trie() {
        root = new Node();
        nodeCount = 1; // root counts as 1 (empty string)
    }

    void insert(string key) {
        Node* temp = root;

        for (int i = 0; i < key.size(); i++) {
            if (temp->children.count(key[i]) == 0) {
                temp->children[key[i]] = new Node();
                nodeCount++; // new node => new substring
            }
            temp = temp->children[key[i]];
        }
    }

    int getUniqueSubstringCount(bool includeEmpty = false) {
        if (includeEmpty) return nodeCount; // keep root
        return nodeCount - 1; // exclude root
    }
};

int main() {
    string str = "ababa";

    Trie t;

    // Insert all suffixes
    for (int i = 0; i < str.size(); i++) {
        t.insert(str.substr(i));
    }

    cout << "Unique substrings (without empty): " << t.getUniqueSubstringCount(false) << endl;
    cout << "Unique substrings (with empty): " << t.getUniqueSubstringCount(true) << endl;

    return 0;
}
