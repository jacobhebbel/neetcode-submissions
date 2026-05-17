class Solution {
public:
    bool isPalindrome(string s) {
        
        string newS = "";

        for (int i = 0; i < s.size(); i++) {
            if (!isalnum(s[i])) continue;
            newS.push_back(tolower(s[i]));
        }
        
        s = newS;


        int lptr = 0;
        int rptr = s.size() - 1;

        while (lptr < rptr) {
            if (s[lptr] != s[rptr])
                return false;

            lptr++;
            rptr--;
        }

        return true;
    }
};
