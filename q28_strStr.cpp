#include <string>
#include <iostream>
#define kbase 26

class Solution {
public:
    int strStr(string haystack, string needle) {
        std::size_t temp = haystack.find(needle);
		// npos: it tells you that find does not find anything.
		// ::npos -> -1
        if (temp!=std::string::npos) {
            return temp;
        }
        else return -1;
        
    }
};

// ref: http://courses.csail.mit.edu/6.006/spring11/rec/rec06.pdf
int RabinKarp(const string &text, const string &pattern) {
	if (text.size() < pattern.size()) {
		return -1;
	}
	
	int prime_number = 101;
	int text_hash =0;
	int pattern_hash =0;
	int power_s = 1;
	// power_s = pow(kbase, L-1)
	for (int i = 0; i < pattern.size(); i++) {
		power_s = i > 0 ? power_s * kbase : 1;
		text_hash = (text_hash * kbase + text[i])%prime_number;
		pattern_hash = (pattern_hash * kbase + pattern[i])%prime_number;
	}
	
	for (int i = pattern.size(); i < text.size(); i++) {
		
		// if text_hash and patter_hash are the same, we can check if there is
		// a collision happen.
		if ( (text_hash == pattern_hash) & (text.compare(i-pattern.size(), pattern.size(), pattern))) {
			return i - pattern.size();
		}
		
		text_hash = kbase*(text_hash - power_s*text[i - pattern.size()]) + text[i];
		
	}
	
	if (text_hash = pattern_hash & text.compare(text.size() - pattern.size(), pattern.size(), pattern) == 0) {
		return text.size() - pattern.size();
	}
	
	return -1;
}


int main() {
	
	
	
}


