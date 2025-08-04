// https://leetcode.com/problems/two-sum/

// 1. Two Sum

// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.

// Example 1:
// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

// Example 2:
// Input: nums = [3,2,4], target = 6
// Output: [1,2]

// Example 3:
// Input: nums = [3,3], target = 6
// Output: [0,1]


// Constraints:
// 2 <= nums.length <= 104
// -109 <= nums[i] <= 109
// -109 <= target <= 109
// Only one valid answer exists.

// Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    static vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> indices; // clave = numero, valor = indice en el array
        
        for (int i = 0; i < n; i++) {
            indices[nums[i]] = i;
        }

        for (int i = 0; i < n; i++) {
            int x = nums[i];
            int currentTarget = target - x;
            if(indices.count(currentTarget) && indices[currentTarget] != i)
                return {i, indices[currentTarget]};
        }

        return {};
    }
};

int main() {
    vector<int> nums = {3,2,4};
    int target = 6;
    vector<int> solution = Solution::twoSum(nums, target);
    cout << "[" << solution[0] << "," << solution[1] << "]" << endl;
    int zero = true, one = false, two = true, three = true;
    int result = zero + (one << 1) + (two << 2) + (three << 3);
    cout << "Resultado: " << result << endl;
}