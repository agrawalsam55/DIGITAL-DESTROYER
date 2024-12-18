#include <iostream>
#include <vector>
using namespace std;
#include "trie.h"
#define UNDERLINE_ON "\033[4m" 
#define UNDERLINE_OFF "\033[0m"
int main()
{
    Trie oTrie;
    // creating a dictionary
    vector<string> words = {"cat", "car", "cart", "ball", "bat", "bats"};
    for(string word: words)
    {
        oTrie.insertword(word);
    }
    string s = "";
    while (char c = getchar())
    {
        
        if(c == ' ' || c== '\n')
        {
            oTrie.searchword(s) ? cout << s << UNDERLINE_ON : cout << s<< UNDERLINE_OFF;
            s= "";
            cout<<c;
        }
        else 
        {
            s= s+c;
        }
    }
    cout << endl;   
    return 0;
}
