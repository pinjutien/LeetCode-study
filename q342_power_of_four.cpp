// https://discuss.leetcode.com/topic/45237/can-someone-explain-to-me-how-to-get-0x55555555/2
// http://www.geeksforgeeks.org/find-whether-a-given-number-is-a-power-of-4-or-not/


/*
Decide if the number is power of four:

For example,
num : bits 
2:      10
4:     100
8:    1000 
16:  10000 


1st condition: num > 0
2nd condition: (num & (num - 1)) ==0

4 & 4-1 = 4 & 3
     100
&     11
------------
     000


8 & 8-1 = 8 & 7
     1000
&     111
------------
     0000

=> both 2^k satisfy this condition.

Thus, we need another condition to distinguish 2^(2k) and 2^(2k-1).

For 2^(2k), in binary form, the 1 will show up in index 2, 4, 6, ...etc poistion.
For 2^(2k-1), in binary form, the 1 will show up in index 3, 5, 7, ...etc poistion.


0x55555555:
0x: hexadecimal digit, 5 = 4+ 1, 0101

for example, 0x5555 means the followings:

0101 0101 0101 0101
                100 -> 4, (num & 0x55555555 ) != 0
               1000 -> 8, (num & 0x55555555 ) = 0
             1 0000 -> 16, (num & 0x55555555 ) != 0
 */


class Solution {
public:
    bool isPowerOfFour(int num) {
        return num > 0 && (num & (num - 1)) == 0  && (num & 0x55555555 ) != 0;
    }
};
