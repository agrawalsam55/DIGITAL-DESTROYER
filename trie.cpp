#include "trie.h"
Trie::Trie()
{
    root = new TrieNode();
}
void Trie::insertword(string word)
{
    TrieNode* currNode = root;
    for(char c: word)
    {
        if(currNode->children[c - 'a']==NULL)
            currNode->children[c - 'a']= new TrieNode();
        currNode = currNode->children[c - 'a'];
    }
    currNode->iscomplete = true;
}
bool Trie::searchword(string word)
{
    TrieNode* currNode = root;
    for(char c: word)
    {
        if(currNode->children[c - 'a']==NULL)
            return false;
        currNode = currNode->children[c - 'a'];
    }
    return currNode->iscomplete;
    
}
bool Trie::deleteword(string word)
{
    TrieNode* currNode = root;
    for(char c: word)
    {
        if(currNode->children[c - 'a']==NULL)
            return false;
        currNode = currNode->children[c - 'a'];
    }
    currNode->iscomplete = false;
    return true;
}
void Trie::updateword(string oldword, string newword)
{
    this->deleteword(oldword);
    this->insertword(newword); 
}
