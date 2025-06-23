#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>
#include <sstream>
using namespace std;

class TrieNode {
public:
    bool isEnd;
    unordered_map<string, TrieNode*> children;
    TrieNode() : isEnd(false) {}
};

class SuffixTrie {
private:
    TrieNode* root;
    int n; // n-gram size

public:
    SuffixTrie(int n) : n(n) {
        root = new TrieNode();
    }

    void insertNGrams(const vector<string>& words) {
        for (int i = 0; i <= words.size() - n; i++) {
            TrieNode* node = root;
            for (int j = 0; j < n; j++) {
                string word = words[i + j];
                if (!node->children.count(word))
                    node->children[word] = new TrieNode();
                node = node->children[word];
            }
            node->isEnd = true;
        }
    }

    bool searchNGram(const vector<string>& phrase) {
        TrieNode* node = root;
        for (const string& word : phrase) {
            if (!node->children.count(word))
                return false;
            node = node->children[word];
        }
        return node->isEnd;
    }

    vector<vector<string>> getCommonNGrams(const vector<string>& words) {
        vector<vector<string>> matches;
        for (int i = 0; i <= words.size() - n; i++) {
            vector<string> phrase(words.begin() + i, words.begin() + i + n);
            if (searchNGram(phrase)) {
                matches.push_back(phrase);
            }
        }
        return matches;
    }
};
