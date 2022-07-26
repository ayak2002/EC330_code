#include <string>
#include "trie.h"

using namespace std;

bool isLeaf(TrieNode* node);

void Trie::insert(string key, int val) {
    TrieNode* trieRoot = this->root;
    for(int i = 0; i < key.length(); i++) {
        int childInd = static_cast<int>(key[i]) - 97;
        if(trieRoot->children[childInd] == nullptr) {
            trieRoot->children[childInd] = new TrieNode;
            (this->tree_size)++;
        }
        trieRoot = trieRoot->children[childInd];
    }
    trieRoot->val = val;
    (this->map_size)++;
    return;
}

int Trie::search(string key) {
    TrieNode* trieRoot = this->root;
    for(int i = 0; i < key.length(); i++) {
        int childInd = static_cast<int>(key[i]) - 97;
        if(trieRoot->children[childInd] == nullptr) {
            return 0;
        }
        trieRoot = trieRoot->children[childInd];
    }
    return trieRoot->val;
}

void Trie::remove(string key) {
    TrieNode* trieRoot = this->root;
    for(int i = 0; i < key.length(); i++) {
        int childInd = static_cast<int>(key[i]) - 97;
        if(i == (key.length() - 1)) {
            if(isLeaf(trieRoot->children[childInd])) {
                trieRoot->children[childInd] = nullptr;
                (this->tree_size)--;
            }
            else {
                trieRoot->children[childInd]->val = 0;
            }
            (this->map_size)--;
        }
        trieRoot = trieRoot->children[childInd];
    }
    
}

bool isLeaf(TrieNode* node) {
    for(int i = 0; i < 26; i++){
        if(node->children[i] != nullptr) {
            return false;
        }
    }
    return true;
}
