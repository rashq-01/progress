#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool is_end_of_word;

    TrieNode() {
        is_end_of_word = false;
    }
};
class Trie {
private:
    TrieNode* root;

    void findWordsFromNode(TrieNode* node, string prefix, vector<string>& words) {
        if (node->is_end_of_word) {
            words.push_back(prefix);
        }
        for (auto& child : node->children) {
            findWordsFromNode(child.second, prefix + child.first, words);
        }
    }

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->is_end_of_word = true;
    }

    vector<string> search(const string& prefix) {
        TrieNode* node = root;
        vector<string> words;
        for (char c : prefix) {
            if (node->children.find(c) == node->children.end()) {
                return words;
            }
            node = node->children[c];
        }
        findWordsFromNode(node, prefix, words);
        return words;
    }
};
int main() {
    Trie trie;
    vector<string> search_terms = {"apple", "app", "application", "banana", "bat", "bath", "cat", "car", "carbon"};

    for (const string& term : search_terms) {
        trie.insert(term);
    }

    string prefix;
    cout << "Enter a prefix to autocomplete: ";
    cin >> prefix;

    vector<string> suggestions = trie.search(prefix);
    
    cout << "Suggestions:\n";
    for (const string& suggestion : suggestions) {
        cout << suggestion << endl;
    }

    return 0;
}
