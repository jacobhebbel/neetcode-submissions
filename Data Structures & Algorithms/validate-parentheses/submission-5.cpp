class Solution {
public:
    bool isValid(string s) {
        
        unordered_map<char, char> mapping = {
            {'(', ')'},
            {'{', '}'},
            {'[', ']'},
        };

        unordered_set<char> openings = {'(', '{', '['};
        stack<char> brackets;

        if (s.size() % 2) return false;

        for (char c : s) {
            
            // if opening: push to stack
            if (openings.find(c) != openings.end())
                brackets.push(mapping[c]);
            
            // if close but not on top / stack is empty: error
            else if (brackets.size() == 0) return false;
            else if (c != brackets.top())
                return false;
            
            // else it matches, so dequeue
            else brackets.pop();
        }

        return brackets.size() == 0;
    }
};
