class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        map<map<char, int>, vector<string>> table;
        for (string str : strs) {
            
            // build a frequency mapping of a string
            map<char, int> mapping;
            for (char c : str) mapping[c]++;

            // hashmaps with same kv pairs are anagrams of each other
            // hashmaps with same kv pairs satisfy object equality
            if (table.contains(mapping)) table[mapping].push_back(str);
            else table[mapping] = { str };
        }

        // make vector of anagrams
        vector<vector<string>> matchings;
        for (auto kv : table) matchings.push_back(kv.second);

        return matchings;
    }
};
