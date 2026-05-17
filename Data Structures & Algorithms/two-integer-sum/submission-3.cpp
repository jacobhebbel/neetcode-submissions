class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        // associates a value with its index
        unordered_map<int, int> valueToIndex;
        for (int i = 0; i < nums.size(); i++) valueToIndex[nums[i]] = i;

        for (int i = 0; i < nums.size(); i++) {
            // if remainder in the value map
            // then remainder's index is the answer
            
            int remainder = target - nums[i];
            if (valueToIndex.contains(remainder)
                && valueToIndex[remainder] != i) {
                int ans = valueToIndex[remainder];
                return { min(i, ans), max(i, ans) };
            }
        }
    }
};
