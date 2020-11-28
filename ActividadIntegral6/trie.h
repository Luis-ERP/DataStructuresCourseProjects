#pragma once
#include <iostream>
#include <string>

using namespace std;
 

class Trie
{
public:
    bool isLeaf;
    Trie* character[128];
 
    // Constructor
    Trie();
 
	// Functions
    void insert(string);
    bool search(string);
};

// Constructor
Trie::Trie(){
	this->isLeaf = false;
	for (int i = 0; i < 128; i++)
		this->character[i] = nullptr;
}
 

// Add a word into tree
// Returns none; input a valid word
void Trie::insert(string key){
    // Start from root node
    Trie* curr = this;
    for (int i = 0; i < key.length(); i++)
    {
        // create a new node if path doesn't exists
        if (curr->character[key[i]] == nullptr)
            curr->character[key[i]] = new Trie();
 
        // go to next node
        curr = curr->character[key[i]];
    }
 
    // mark current node as leaf
    curr->isLeaf = true;
}
 

// Search for a word in tree
// Returns boolean; input a valid word
bool Trie::search(string key){ 
    Trie* curr = this;
    for (int i=0; i<key.length(); i++){
        // go to next node
        curr = curr->character[key[i]];
 
        // if string is invalid (reached end of path in Trie)
        if (curr == nullptr)
            return false;
    }
 
    // if current node is a leaf and we have reached the
    // end of the string, return true
    return curr->isLeaf;
}