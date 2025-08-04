#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
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

int main() {
    vector<int> nums = {3,2,4};
    int target = 6;
    vector<int> solution = twoSum(nums, target);
    cout << "[" << solution[0] << "," << solution[1] << "]" << endl;
    int zero = true, one = false, two = true, three = true;
    int result = zero + (one << 1) + (two << 2) + (three << 3);
    cout << "Resultado: " << result << endl;
}