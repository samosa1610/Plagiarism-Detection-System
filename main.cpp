// #include "include/SuffixTrie.h"
#include "SuffixTrie.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
#include <chrono>

using namespace std;

vector<string> tokenize(const string &text)
{
    vector<string> words;
    string word;
    stringstream ss(text);
    while (ss >> word)
    {
        // Remove punctuation and convert to lowercase
        word.erase(remove_if(word.begin(), word.end(),
                             [](char c)
                             { return !isalnum(c); }),
                   word.end());

        if (!word.empty())
        {
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            words.push_back(word);
        }
    }
    return words;
}

string readFile(const string &filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Error: Could not open file " << filename << endl;
        return "";
    }

    stringstream buffer;
    buffer << file.rdbuf();
    file.close();
    return buffer.str();
}

double calculateSimilarity(const vector<vector<string>> &matches,
                           const vector<string> &words2, int n)
{
    if (words2.size() < n)
        return 0.0;

    int totalPossibleNGrams = words2.size() - n + 1;
    int matchingNGrams = matches.size();

    return (double)matchingNGrams / totalPossibleNGrams * 100.0;
}

int main()
{
    auto start = std::chrono::high_resolution_clock::now();

    int n = 3; // Reduced n-gram length for better detection
    SuffixTrie trie(n);

    cout << "Reading files..." << endl;

    string file1Content = readFile("file1.txt");
    string file2Content = readFile("file2.txt");

    if (file1Content.empty() || file2Content.empty())
    {
        cerr << "Error: Could not read one or both files." << endl;
        return 1;
    }

    vector<string> words1 = tokenize(file1Content);
    vector<string> words2 = tokenize(file2Content);

    cout << "File 1 words: " << words1.size() << endl;
    cout << "File 2 words: " << words2.size() << endl;

    if (words1.size() < n || words2.size() < n)
    {
        cout << "Files are too short for " << n << "-gram analysis." << endl;
        return 0;
    }

    // Insert n-grams from first file
    trie.insertNGrams(words1);

    // Find common n-grams in second file
    vector<vector<string>> matches = trie.getCommonNGrams(words2);
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Time taken: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
              << " ms" << std::endl;

    cout << "\nAnalysis Results:" << endl;
    cout << "==================" << endl;
    cout << "N-gram size: " << n << endl;
    cout << "Common phrases found: " << matches.size() << endl;

    if (!matches.empty())
    {
        cout << "\nMatching phrases:" << endl;
        for (size_t i = 0; i < matches.size() && i < 10; i++)
        { // Show max 10 matches
            cout << (i + 1) << ". ";
            for (const string &word : matches[i])
            {
                cout << word << " ";
            }
            cout << endl;
        }

        if (matches.size() > 10)
        {
            cout << "... and " << (matches.size() - 10) << " more matches." << endl;
        }

        double similarity = calculateSimilarity(matches, words2, n);
        cout << "\nSimilarity: " << similarity << "%" << endl;

        if (similarity > 20.0)
        {
            cout << "HIGH PLAGIARISM RISK detected!" << endl;
        }
        else if (similarity > 10.0)
        {
            cout << "MODERATE PLAGIARISM RISK detected." << endl;
        }
        else
        {
            cout << "LOW PLAGIARISM RISK." << endl;
        }
    }
    else
    {
        cout << "\nNo matching phrases found." << endl;
        cout << "No plagiarism detected." << endl;
    }

    return 0;
}
