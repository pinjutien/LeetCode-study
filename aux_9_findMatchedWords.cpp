#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;
using std::string;
using std::vector;
using std::map;


string decode_pattern(string pattern) {
  map<string, int> mymap;
  int current_value = 0;
  string res = "";
 
  int i;
  for (i = 0; i < pattern.size(); i++) {
    // when it is not the key in the map
    if ( mymap.find(pattern[i]) == dict.end()) {
      current_value += 1;
      mymap[pattern[i]] = current_value;
    }

    res = res + to_string(it->second);    
  }

  return res;

};

vector<string> findMatchedWords(vector<string> dict, string pattern) {
  string pattern_code = decode_pattern(pattern);
  string temp_code;
  vector<string> final_res;
  for (int k = 0; k < dict.size(); k++) {
    temp_code = decode_pattern(dict[i]);
    if (temp_code == pattern_code) {
      final_res.push_back(temp_code);
    }
  }

  return final_res;
}
