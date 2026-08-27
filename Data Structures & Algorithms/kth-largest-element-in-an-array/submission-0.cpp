class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        // init the sliding window
        std::priority_queue<int> pq;
        for (int i = 0; i < k; i++) pq.push(nums[i] * -1);

        // loop over the other numbers
        for (int i = k; i < nums.size(); i++)
        {
            int n = nums[i]*-1;
            if (n > pq.top()) continue;

            pq.pop();
            pq.push(n);
        }
        
        return pq.top()*-1;
    }
};
