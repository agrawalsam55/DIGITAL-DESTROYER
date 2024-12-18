#include <iostream>
using namespace std;
struct TrieNode
{
    bool iscomplete= false;
    TrieNode* children[26]={NULL};
};
class Trie
{
    TrieNode* root = NULL;
    public:
    TrieNode();
    void insertword(string word);
    bool searchword(string word);
    bool deleteword(string word);
    bool updateword(string oldword, string newword);
};
