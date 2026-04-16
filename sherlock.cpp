#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

void getWords(std::vector<std::string> &words, std::ifstream &file) {
    std::string token;
    while (file >> token) {
        // Remove leading/trailing punctuation and convert to lowercase
        std::string cleaned;
        for (char ch : token) {
            if (std::isalpha(static_cast<unsigned char>(ch))) {
                cleaned += static_cast<char>(std::tolower(static_cast<unsigned char>(ch)));
            }
        }
        if (!cleaned.empty()) {
            words.push_back(cleaned);
        }
    }
}
 

void sortWords(std::vector<std::string> &words) {
    std::sort(words.begin(), words.end());
}

std::vector<std::pair<std::string, int>> getWordCounts(std::vector<std::string> &words) {
    std::vector<std::pair<std::string, int>> wordCounts;
 
    for (size_t i = 0; i < words.size(); ) {
        int count = 1;
        while (i + count < words.size() && words[i + count] == words[i]) {
            ++count;
        }
        wordCounts.push_back({words[i], count});
        i += count;
    }
 
    return wordCounts;
}
 
void printWordCounts(std::vector<std::pair<std::string, int>> &wordCounts) {

    std::sort(wordCounts.begin(), wordCounts.end(),
              [](const std::pair<std::string, int> &a,
                 const std::pair<std::string, int> &b) {
                  return (a.second != b.second) ? (a.second > b.second)
                                                : (a.first < b.first);
              });
 
    std::cout << std::string(30, '-') << "\n";
    std::cout << "  Word                  Count\n";
    std::cout << std::string(30, '-') << "\n";
 
    for (const auto &entry : wordCounts) {
        std::cout << "  " << entry.first;
        // Pad to column 22
        int pad = 22 - static_cast<int>(entry.first.size());
        std::cout << std::string(std::max(pad, 1), ' ') << entry.second << "\n";
    }
 
    std::cout << std::string(30, '-') << "\n";
    std::cout << "  Total unique words: " << wordCounts.size() << "\n";
}
int main() {
    const std::string filename = "homes.txt";
 
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: could not open \"" << filename << "\"\n";
        return 1;
    }
 

    std::vector<std::string> words;
    getWords(words, file);
    file.close();
 
    std::cout << "Total words read: " << words.size() << "\n\n";

    sortWords(words);
 
    std::vector<std::pair<std::string, int>> wordCounts = getWordCounts(words);
 

    printWordCounts(wordCounts);
 
    return 0;
}