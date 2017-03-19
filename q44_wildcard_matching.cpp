//
//  main.cpp
//  CPP-project
//
//  Created by Pin-Ju Tien on 1/14/17.
//  Copyright © 2017 Pin-Ju Tien. All rights reserved.
//

#include <iostream>

using namespace std;

// wildcard matching
// http://www.geeksforgeeks.org/wildcard-pattern-matching/
// https://www.youtube.com/watch?v=3ZDZ-N0EPV0

/*
 
Note: 
 - T[i][j] include null charater in 0-th row and 0-th column
 - We populate space both in front of text and pattern.
   Thus, T[i][j] correspond to text[i] and pattern[j]
 
 
 
 - when pattern[j] == ? or pattern[j] == text[i],

 For example,
 
 pattern: a b ? [j]
 text:    a b c [i]
 
 this question becomes:
 
 pattern: a b  [j-1]
 text:    a b  [i-1]
 -> T[i][j] = T[i-1][j-1]
 
 
 - when pattern[j] == *, it can match the following any sequence.
 
 For example,
 
 pattern: x ? y * [j]
 text:    x a y   [i]
 
 Either * represent zero sequence,
 
 pattern: x ? y  [j-1]
 text:    x a y  [i]
 
 => True
 
 T[i][j] = T[i][j-1]
 
 
 or
 
 Either * match the y in the end of text,
 
 pattern: x ? y   [j]
 text:    x a     [i-1]
 => False
 
 T[i][j] = T[i-1][j]
 
*/




bool is_match(string text, string pattern, int text_size, int pattern_size) {
    
    if (pattern_size == 0) return (text_size == 0);
    
    // intialize the lookup table T.
    // Assume first charactoer of text and pattern are all null charatcer.
    // T[i][j]: true if first i characters in the text matches the first j characters of pattern
    
    bool T[text_size +1][pattern_size + 1];
    memset(T, false, sizeof(T));
    T[0][0] = true;
    text = " " + text;
    pattern = " " + pattern;
    
    for (int j = 1; j <= pattern_size; j++) {
        // j-th index in pattern corresponds to j-th in table T.
        if (pattern[j] == '*') {
            T[0][j] = T[0][j-1];
        }
    }
    
    for (int i = 1; i <= text_size; i++) {
        for (int j = 1; j <= pattern_size; j++) {
            if (pattern[j] == '*') {
                T[i][j] = T[i][j-1] || T[i-1][j];
            }
            else if ((pattern[j] == '?') || text[i] == pattern[j]) {
                T[i][j] = T[i-1][j-1];
            }
            else {
                T[i][j] = false;
            }
        }
        
    }
    
    return T[text_size][pattern_size];
    
}




int main() {
    
    string text = "baaabab";
    string pattern = "baaa?ab";
    bool res = is_match(text, pattern, text.size(), pattern.size());
    cout << "Match: \n" << " ";
    cout << res << "\n";
    return 0;
    
}
