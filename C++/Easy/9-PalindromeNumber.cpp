// https://leetcode.com/problems/palindrome-number/

// 9. Palindrome Number

// Given an integer x, return true if x is a palindrome, and false otherwise.


// Example 1:
// Input: x = 121
// Output: true
// Explanation: 121 reads as 121 from left to right and from right to left.

// Example 2:
// Input: x = -121
// Output: false
// Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

// Example 3:
// Input: x = 10
// Output: false
// Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

// Constraints:
// -2^31 <= x <= 2^31 - 1 (un entero, vaya)

// Follow up: Could you solve it without converting the integer to a string?

#include <iostream>
#include <cmath>

class Solution {
public:
    static int digitAtPos(int x, int position) {
        int divisor = std::pow(10, position - 1);
        return (x / divisor) % 10;
    }
public:
    static bool isPalindrome(int x) {
        if (x < 0) return false;
        int digits = x == 0 ? 1 : (int)std::log10(x) + 1;

        int counter = 1;
        while (counter <= digits/2) {
            int d1 = digitAtPos(x, counter), d2 = digitAtPos(x, digits - counter + 1);
            if (d1 != d2) return false;
            counter++;
        }

        return true;
    }
};

int main() {
    int number;
    std::cout << "Number: ";
    std::cin >> number;
    std::string res = Solution::isPalindrome(number) ? "true" : "false";
    std::cout << res << std::endl;
}