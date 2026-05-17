class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        // will map anagram to vector of words
        unordered_map<string, vector<string>> anagramMap;
        
        for (string word : strs) {

            // represents a word encoding
            vector<int> encoding(26);
            
            // builds the word encoding
            for (char c : word)
                encoding[int(c) - 97]++;
            
            // make string representation of the encoding
            string encStr = "";
            for (int f : encoding)
                encStr += '#' + std::to_string(f);

            // inserts the encoding
            if (anagramMap.find(encStr) == anagramMap.end())
                anagramMap[encStr] = {};
            anagramMap[encStr].push_back(word);
        }

        // collect all the vectors
        vector<vector<string> > solution;
        for (
            auto itr = anagramMap.begin();
            itr != anagramMap.end();
            itr++
        )
            solution.push_back(itr->second);
        
        return solution;
    }
};
