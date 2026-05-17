#include <unordered_map>

class Solution {
public:
    bool isAnagram(string s, string t) {
        
        std::unordered_map<char, int> frequencyMap;
        
        // count the frequency of letters in w1
        for (char c : s)
            frequencyMap[c]++;
        
        // decrement frequency for letters in w2
        for (char c : t)
            frequencyMap[c]--;

        // iterate over the map's kv pairs
        // if any index isn't 0, that means a mismatch on that letter
        for (auto itr = frequencyMap.begin();
            itr != frequencyMap.end();
            itr++)
            if (itr->second != 0)
                return false;
        
        // implies all values in the map equal 0
        return true;
    }
};
