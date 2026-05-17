#include <unordered_map>
#include <iostream>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        std::unordered_map<int, int> mapping;
        
        for (int i = 0; i < nums.size(); i++) {
            
            int targetPair = target - nums[i];
            
            if (mapping.find(targetPair) != mapping.end()){    
                if (mapping[targetPair] != i)
                    return {mapping[targetPair], i};
            }

            mapping[nums[i]] = i;
        }

        return {-1, -1};
    }
};
