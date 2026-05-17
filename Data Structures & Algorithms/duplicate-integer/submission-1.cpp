class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::set numSet = set(nums.begin(), nums.end());

        bool hasDuplicate = numSet.size() < nums.size();
        return hasDuplicate;
    }
};