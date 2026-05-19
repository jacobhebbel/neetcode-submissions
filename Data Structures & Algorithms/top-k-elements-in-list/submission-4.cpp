class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        // build a frequency mapping
        unordered_map<int, int> freqMapping;
        for (int i : nums) freqMapping[i]++;
        
        // bucket sort freqs with nums as vector index
        vector<vector<int>> freqBuckets(nums.size() + 1, vector<int>());
        for (const auto [num, freq] : freqMapping)
            freqBuckets[freq].push_back(num);

        // iterate backwards, taking nums until solution is size k
        vector<int> sol;
        for (int i = nums.size(); i >= 0; i--) {
            if (freqBuckets[i].size() == 0) 
                // skip this bucket is empty
                continue;
            
            // iterate over bucket until empty or sol is full
            int j = 0;
            while(sol.size() < k && j < freqBuckets[i].size()) {
                sol.push_back(freqBuckets[i][j]);
                j++;
            }
        } 


        return sol;

    }
};
