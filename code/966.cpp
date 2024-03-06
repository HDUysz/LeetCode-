#include<vector>
#include<string>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<string> spellchecker(vector<string> &wordlist, vector<string> &queries) {
      unordered_map<string, string> exactMatch;
      unordered_map<string, string> caseInsensitiveMatch;
      unordered_map<string, string> vowelErrorMatch;

      for (const auto& word : wordlist) {
          exactMatch[word] = word;
          
          string lowerCaseWord = toLowerCase(word);
          if (!caseInsensitiveMatch.count(lowerCaseWord)) {
              caseInsensitiveMatch[lowerCaseWord] = word;
          }
          
          string devowelWord = toDevowel(lowerCaseWord);
          if (!vowelErrorMatch.count(devowelWord)) {
              vowelErrorMatch[devowelWord] = word;
          }
      }

      vector<string> answers;
      for (const auto& query : queries) {
          string lowerQuery = toLowerCase(query);
          string devowelQuery = toDevowel(lowerQuery);
          
          if (exactMatch.count(query)) {
              answers.push_back(exactMatch[query]);
          } else if (caseInsensitiveMatch.count(lowerQuery)) {
              answers.push_back(caseInsensitiveMatch[lowerQuery]);
          } else if (vowelErrorMatch.count(devowelQuery)) {
              answers.push_back(vowelErrorMatch[devowelQuery]);
          } else {
              answers.push_back("");
          }
      }
      return answers;
  }

  string toLowerCase(const string& word) {
      string res;
      for (char c : word) {
          res += tolower(static_cast<unsigned char>(c));
      }
      return res;
  }

  string toDevowel(string word) {
      for (char &c : word) {
          if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
              c = '*';
          }
      }
      return word;
  }
};
