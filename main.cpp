#include <iostream>   // for input and output
#include <vector>     // for using vector to store suggestions
#include <fstream>    // for reading the dictionary file
using namespace std;  // so we don't need to write std:: every time

// this is a node in the trie
struct TrieNode {
    TrieNode* children[26]; // each letter from a-z 
    bool isEnd;             // true if a word ends here
    TrieNode() {
        isEnd = false; // when new node is made, no word ends here yet
        for (int i = 0; i < 26; i++) children[i] = nullptr; // no children yet
    }
};

// trie class to store words
class Trie {
    TrieNode* root; // root node
public:
    Trie() { root = new TrieNode(); } // make new empty trie

    // insert a word into the trie
    void insert(string word) {
        TrieNode* node = root; // start from root
        for (char c : word) {  // go through each letter
            if (!isalpha(c)) return; // skip if not a letter
            c = tolower(c); // change to lowercase
            int index = c - 'a'; // get position in alphabet (0-25)
            if (!node->children[index]) // if no child for this letter
                node->children[index] = new TrieNode(); // make new node
            node = node->children[index]; // move to next node
        }
        node->isEnd = true; // mark end of a word
    }

    // find all words starting from this node
    void findWords(TrieNode* node, string prefix, vector<string>& results) {
        if (node->isEnd) results.push_back(prefix); // if word ends here, add to results
        for (int i = 0; i < 26; i++) { // check all letters
            if (node->children[i]) // if child exists
                findWords(node->children[i], prefix + char('a' + i), results); // go deeper
        }
    }

    // search for a prefix in trie and return all words that start with it
    vector<string> searchPrefix(string prefix) {
        TrieNode* node = root; // start from root
        for (char c : prefix) { // go through each letter of prefix
            if (!isalpha(c)) return {}; // skip if not a letter
            c = tolower(c); // make lowercase
            int index = c - 'a'; // find index
            if (!node->children[index]) return {}; // prefix not found
            node = node->children[index]; // move to next
        }
        vector<string> results; // store words found
        findWords(node, prefix, results); // find all words starting with prefix
        return results; // return them
    }
};

int main() {
    Trie trie; // make a trie

    ifstream file("words_alpha.txt"); // open dictionary file
    string word;
    while (file >> word) { // read each word from file
        trie.insert(word); // put it in the trie
    }
    file.close(); // close file
    cout << "dictionary loaded!\n"; // tell user dictionary is ready

    string input;
    cout << "type a prefix (or 'exit' to quit):\n"; // ask user for input
    while (true) { // keep looping
        cout << "> "; // prompt
        cin >> input; // get word from user
        if (input == "exit") break; // if user types exit, stop

        vector<string> suggestions = trie.searchPrefix(input); // find suggestions
        if (suggestions.empty()) // if no matches
            cout << "no suggestions.\n"; // tell user
        else {
            cout << "suggestions: ";
            int count = 0; // counter so we don't show too many
            for (string s : suggestions) { // go through each suggestion
                cout << s << " "; // print word
                if (++count == 10) break; // only show first 10
            }
            cout << endl; // new line
        }
    }
    return 0; // end program
}
