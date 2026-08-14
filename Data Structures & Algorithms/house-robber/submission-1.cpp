class Solution {
public:
    int rob(vector<int>& nums) {
        
        std::vector<int> dp(nums.size());
        
        if (nums.size() < 3)
        {
            if (nums.size() == 0) return 0;
            if (nums.size() == 1) return nums[0];
            if (nums.size() == 2) return std::max(nums[0], nums[1]);
        }

        dp[0] = nums[0];
        dp[1] = std::max(nums[0], nums[1]);

        for (int i = 2; i < dp.size(); i++)
        {
            dp[i] = std::max(dp[i-1], dp[i-2] + nums[i]);
        }

        return dp[nums.size() - 1];
    }
};
