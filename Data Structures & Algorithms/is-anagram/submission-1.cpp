class Solution {
public:
    bool isAnagram(string s, string t) {
        
        // anagrams must be the same size
        if (s.size() != t.size()) return false;
        
        // count letter frequency with hash maps
        unordered_map<char, int> freqS;
        for (char c : s) freqS[c]++;
        unordered_map<char, int> freqT;
        for (char c : t) freqT[c]++;

        return freqS == freqT;
    }
};
