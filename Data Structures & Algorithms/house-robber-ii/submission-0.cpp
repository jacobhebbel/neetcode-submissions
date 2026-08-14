class Solution {
public:
    int rob(vector<int>& nums) {
        
        // base cases
        int num_houses = nums.size();
        if (num_houses == 1) return nums[0];
        if (num_houses == 2) return std::max(nums[0], nums[1]);

        
        std::vector<int> dp1(num_houses - 1);
        dp1[0] = nums[0];
        dp1[1] = std::max(dp1[0], nums[1]);
        for (int i = 2; i < num_houses-1; i++)
        {
            dp1[i] = std::max(dp1[i-1], dp1[i-2] + nums[i]);
        }

        std::vector<int> dp2(num_houses - 1);
        dp2[0] = nums[1];
        dp2[1] = std::max(dp2[0], nums[2]);
        for (int i = 2; i < num_houses-1; i++)
        {
            dp2[i] = std::max(dp2[i-1], dp2[i-2] + nums[i+1]);
        }
        return std::max(dp1.back(), dp2.back());
    }
};
