# Autocomplete using Trie

## Data structure implemented
Trie (also called Prefix Tree)

## Short explanation
A trie is a tree-like data structure used to store words in a way that makes prefix searching fast.  
Each node represents a letter, and words are formed by linking nodes together.  
This program uses a trie to suggest words when the user types a prefix.

## How to run
1. Make sure `main.cpp` and `words_alpha.txt` are in the same folder.
2. Open a terminal or command prompt in that folder.
3. Compile the code:
   Example:
   For Windows, 
    g++ main.cpp -o autocomplete
   autocomplete.exe
   For MAC, 
    g++ main.cpp -o autocomplete
    ./autocomplete

5. Type a prefix and press Enter to see word suggestions.
6. Type `exit` to quit.

## What it does
When you type in a few letters, the program searches the trie and shows up to 10 words from the dictionary that start with your input.
For example,
dictionary loaded!
type a prefix (or 'exit' to quit):
> umbrella
suggestions: umbrella umbrellaed umbrellaing umbrellaless umbrellalike umbrellas umbrellawise umbrellawort 
