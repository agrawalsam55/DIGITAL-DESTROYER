#include <iostream>
#include <vector>
using namespace std;

struct TrieNode {
    bool isEndOfWord;
    vector<TrieNode*> children;

    TrieNode() : isEndOfWord(false), children(26, nullptr) {}
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* curr = root;
        for (char c : word) {
            int index = c - 'a';
            if (curr->children[index] == nullptr) {
                curr->children[index] = new TrieNode();
            }
            curr = curr->children[index];
        }
        curr->isEndOfWord = true;
    }

    bool search(const string& word) {
        TrieNode* curr = root;
        for (char c : word) {
            int index = c - 'a';
            if (curr->children[index] == nullptr) {
                return false;
            }
            curr = curr->children[index];
        }
        return curr != nullptr && curr->isEndOfWord;
    }
};

int main() {
    Trie dictionary;
    
    // Inserting words into the dictionary
    vector<string> words = {"hello", "world", "apple", "banana", "orange"};
    for (const string& word : words) {
        dictionary.insert(word);
    }

    // Searching for words in the dictionary
    vector<string> searchWords = {"hello", "world", "apple", "banana", "orange", "grape"};
    for (const string& word : searchWords) {
        if (dictionary.search(word)) {
            cout << "Word \"" << word << "\" found in the dictionary." << endl;
        } else {
            cout << "Word \"" << word << "\" not found in the dictionary." << endl;
        }
    }

    return 0;
}
