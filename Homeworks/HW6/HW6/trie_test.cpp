#include <iostream>
#include "trie.h"

int main() {

    Trie t;
    t.insert("hello", 12);
    t.insert("world", 19);
    t.insert("coffee", 12);
    t.insert("corinth", 99);
    t.insert("to", 15);
    t.insert("tool", 28);
    std::cout << "map has " << t.map_size << " elements and " << t.tree_size << " nodes." << std::endl;
    std::cout << "hello: " << t.search("hello") << " (0 value means I don't have the key)" << std::endl;
    std::cout << "corinth: " << t.search("corinth") << " (0 value means I don't have the key)" << std::endl;
    std::cout << "lorem: " << t.search("lorem") << " (0 value means I don't have the key)" << std::endl;
    std::cout << "to: " << t.search("to") << " (0 value means I don't have the key)" << std::endl;
    std::cout << "tool: " << t.search("tool") << " (0 value means I don't have the key)" << std::endl;
    t.remove("corinth");
    t.remove("to");
    std::cout << "REMOVE: corinth." << std::endl;
    std::cout << "hello: " << t.search("hello") << " (0 value means I don't have the key)" << std::endl;
    std::cout << "corinth: " << t.search("corinth") << " (0 value means I don't have the key)" << std::endl;
    std::cout << "to: " << t.search("to") << " (0 value means I don't have the key)" << std::endl;
    std::cout << "tool: " << t.search("tool") << " (0 value means I don't have the key)" << std::endl;
    std::cout << "map has " << t.map_size << " elements and " << t.tree_size << " nodes." << std::endl;

    return 0;
}
