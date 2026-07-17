class Solution:
    def characterReplacement(self, s: str, k: int) -> int:

        # The character to use is the most frequent
        # For a substring, we want to increase it until it has k not-most frequent characters

        # early return case where we can pick the string
        if k >= len(s): return len(s)

        # strategy: use 2 pointers to set the window
        # track the most frequent letter: this is what we set letters to
        # compute how many letters arent that in the window: this is our budget
        # while under budget: increase the window
        # once broke: move the window until not broke
        # the answer is the maximum window size
        
        max_win_size = 1
        left, right = 0, 1
        freq, max_freq, other = {s[0]: 1}, 1, 0
        while right < len(s):
            window_size = right - left + 1

            # set this letter's frequency
            c = s[right]
            freq[c] = freq.get(c, 0) + 1

            max_freq = max(max_freq, freq[c])
            other_count = window_size - max_freq

            over_budget = other_count > k
            
            if over_budget:
                freq[s[left]] -= 1
                left += 1
            
            right += 1

        return right - left