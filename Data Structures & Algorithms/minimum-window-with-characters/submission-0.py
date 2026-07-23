class Solution:
    def minWindow(self, s: str, t: str) -> str:

        # build frequency map
        freq_map = {c: 0 for c in t}
        for c in t: freq_map[c] += 1

        # problem objective: window is a valid substring when
        # this set's length equals the length of t
        # if a letter's decremented frequency is lte 0, then its valid
        valid_t = set()

        answer = ""
        best_window_size = float('inf')
        left, right = 0, 0
        while right < len(s):
            
            arriving = s[right]

            # if the letter is in t, take it
            # could also be the start of a new window
            if arriving in freq_map:

                # take the arriving letter
                freq_map[arriving] -= 1
                
                # updating constraint / objective
                if freq_map[arriving] <= 0: 
                    valid_t.add(arriving)

            # after taking the letter, see if the substring is valid
            substring_is_valid = len(valid_t) == len(freq_map)
            while substring_is_valid and left <= right:

                # see if we found the new shortest substring                
                window_size = right - left + 1
                if window_size < best_window_size:
                    best_window_size = window_size
                    answer = s[left:right+1]

                # now that we found a substring, expanding it 
                # doesn't make sense. Move left until its in fmap
                leaving = s[left]
                if leaving in freq_map: 
                    freq_map[leaving] += 1
                    if freq_map[leaving] > 0: 
                        valid_t.discard(leaving)
                        
                substring_is_valid = len(valid_t) == len(freq_map)
                left += 1

            right += 1

        return answer 

