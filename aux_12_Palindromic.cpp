#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


// a boolean function to check if s is palindrome
bool is_Palindrome(string s) {
  int n = s.size();
  int left = 0;
  int right = n-1;

  while(left < right) {
    if (s[left] != s[right]) {
      return false;
    }
    left += 1;
    right -= 1;
  }
  return true;
};


// expand both directions to check if the symmetric happen
// for even-length of palindrome, start from left = i,  right = i+1
// for odd-length of palindrome, start from left = right = i;

string center_function(string s, int left, int right) {
  int l = left;
  int r = right;
  int n = s.length();
  
  while ((l >= 0) && (r <= n-1) && (s[l] == s[r])) {
    l -= 1;
    r += 1;
  }
  // the length of palindrome is r-l-1 and start from index = l+1
  return s.substr(l+1, r-l-1);
}

string longestPalindrome(string s) {
  int n = s.length();
  if (n == 0) return " ";

  
  string longest_str = s.substr(0,1);
  string s1, s2;

  for (int i = 1; i < n-1; i++) {
    s1 = center_function(s, i, i);
    if (s1.length() > longest_str.length()) {
      longest_str = s1;
    }

    s2 = center_function(s, i, i+1);
    if (s2.length() > longest_str.length()) {
      longest_str = s2;
    }
  }

  return longest_str;
}

