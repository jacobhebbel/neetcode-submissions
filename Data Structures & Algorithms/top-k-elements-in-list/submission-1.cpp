class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        // gets the frequency of each number
        unordered_map<int, int> frequencies;
        for (int num : nums)
            frequencies[num]++;
        
        // frequencies are now buckets;
        vector<vector<int>> buckets(nums.size() + 1);
        for (auto [num, freq] : frequencies)
            buckets[freq].push_back(num);

        // loop once to get the k biggest frequencies
        vector<int> solution;
        vector<vector<int>>::iterator itr = buckets.end();
        while (itr != buckets.begin()) {
            itr--;
            for (int num : (*itr)) {
                if (solution.size() == k)
                    return solution;
                solution.push_back(num);
            }
        }

        return solution;
    }
};