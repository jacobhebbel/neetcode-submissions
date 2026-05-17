class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_set<char> uniqueChars; // holds all unique characters
        
        int leftPtr = 0;    // references the start of a unique substring
        int rightPtr = 0;   // references the end of a unique substring
        int length = 0;     // tracks the best length observed

        // outer loop over string, runs linear wrt string length
        while (
            (leftPtr + length) < s.size()
        ) {
            
            // pointers for tracking substring
            char firstChar = s[leftPtr];
            // inner loop moves rightPtr until a duplicate char is found            
            while(
                rightPtr < s.size()
            ) {
                
                char newChar = s[rightPtr];
                if (uniqueChars.find(newChar) != uniqueChars.end())
                    break;

                cout << "adding letter " << newChar << " to set" << endl;
                // adds a unique char and points rightPtr to the next char
                uniqueChars.insert(newChar);
                rightPtr++;
            }
            
            // abcde
            // repeat char found ==> max substr length ==> check if its the biggest
            if (uniqueChars.size() > length) length = uniqueChars.size();
            cout << "max size is " << length << endl;

            // remove the left char and repoint to next char
            uniqueChars.erase(firstChar);
            cout << "removing " << firstChar << " from set" << endl;
            leftPtr++;
        }

        return length != 0 ? length : uniqueChars.size();
    }
};
