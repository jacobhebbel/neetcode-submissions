class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        
        # Planning:
        #
        # Longest substring within string, so track moving length
        # probably with two pointers like
        # l, r = beginning
        # while l isnt end of word: see if adding r breaks the invariant

        # how to count duplicates
        # keep a set of letters over the two pointers
        # when r moves, add the letter it lands on to the set
        # when l moves, remove the letter it was just on
        
        if len(s) == 0: return 0
        
        
        lptr, rptr = 0, 1
        chars = { s[lptr] }
        longest = len(chars)

        while rptr < len(s):
            # try adding rptr
            # if it breaks, move lptr up
            
            new_char = s[rptr]
            while new_char in chars:
                chars.discard(s[lptr])
                lptr += 1
            
            chars.add(new_char)
            rptr += 1
            longest = max(longest, len(chars))
        
        return longest