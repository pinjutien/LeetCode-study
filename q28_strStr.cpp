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