// https://leetcode.com/problems/longest-substring-without-repeating-characters/

// 3. Longest Substring Without Repeating Characters

// Hint
// Given a string s, find the length of the longest substring without duplicate characters.

// Example 1:
// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.

// Example 2:
// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.

// Example 3:
// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

// Constraints:
// 0 <= s.length <= 5 * 104
// s consists of English letters, digits, symbols and spaces.

#include <iostream>
#include <unordered_set>

class Solution {
public:
    static int lengthOfLongestSubstring(std::string str) {
        int i, j = 0;
        int bestLen = 0;
        int n = (int) str.length();
        std::unordered_set<char> set = {};
        while (j < n) {
            char currChar = str[static_cast<std::string::size_type>(j)];
            // Si ya está en el mapa, hay que quitarlo
            while (set.find(currChar) != set.end()) {
                set.erase(str[i]);
                i++;
            }
            set.insert(currChar);
            if (j - i + 1 > bestLen) bestLen = j - i + 1;
            j++;
        }
        return bestLen;
    }
};

int main() {
    std::string str = "hooola cooomo estas!!";
    std::cout << "String input: " << str << std::endl;
    std::cout << "Longest substring with no repeating characters: " << Solution::lengthOfLongestSubstring(str) << std::endl;
}