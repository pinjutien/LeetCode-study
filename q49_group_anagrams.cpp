#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
  
  // key: sorted string, values: the indexs in strs which has the same order as key.
  unordered_map<string, vector<int>> string_dict;
  string str_temp;
  for (int i = 0; i < strs.size(); i++) {
    sort(strs[i].begin(), strs[i].end());
    str_temp = strs[i];
    string_dict[str_temp].push_back(i);
  }
    
    
  vector<vector<string>> result(string_dict.size());
  int count = 0;
  for(auto& x: string_dict) {
    vector<int> vec_temp = x.second;
    if (vec_temp.size() >= 1) {
      for (int i = 0; i < vec_temp.size(); i++) {
	int indexx = vec_temp[i];
	string element = strs.at(indexx);
	result[count].push_back(element);
      }
            
      count += 1;
    }
  }
    
  return result;
    
}


int main(int argc, const char * argv[]) {
  // insert code here...
  string input[6] = {"eat", "tea", "tan", "ate", "nat", "bat"};
  vector<string> nums(input, input + sizeof(input)/sizeof(input[0]));
  vector<vector<string>> result;
  result = groupAnagrams(nums);
    
  return 0;
}



