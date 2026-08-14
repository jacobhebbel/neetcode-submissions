class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        // min cost is determined with subproblems
        // to reach floor i, you must be at 
        // -> floor i-1
        // -> floor i-2
        // the optimal way to reach floor i is to take
        // the cheaper of these two options


        // base cases:
        int num_floors = cost.size();
        if (num_floors == 0) return 0;
        if (num_floors == 1) return cost[0];
        if (num_floors == 2) return std::min(cost[0], cost[1]);

        // base cases covered, now we can build our dynamic program
        std::vector<int> dp(num_floors);
        dp[0] = cost[0];
        dp[1] = cost[1];

        // subproblem execution
        for (int i = 2; i < num_floors; i++)
        {
            dp[i] = cost[i] + std::min(dp[i-1], dp[i-2]);
        }

        // when we reach the last or second to last floor, we can choose to leave
        // so we can return the min of the last two elements
        return std::min(dp[num_floors - 1], dp[num_floors - 2]);
    }
};
