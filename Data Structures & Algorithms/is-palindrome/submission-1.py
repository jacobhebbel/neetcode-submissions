class Solution:
    def isPalindrome(self, s: str) -> bool:
        
        s = "".join(c for c in s if c.isalnum()).lower()
        print(s)
        lptr, rptr = 0, len(s) - 1
        while lptr < rptr:
            if s[lptr] != s[rptr]: return False
            lptr+=1;
            rptr-=1;

        return True