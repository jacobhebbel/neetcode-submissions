class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        
        # sliding window logic:
        # if all my letters have a frequency of exactly 0
        # and my window does not contain invalid letters
        # then I have found the permutation
        # else: either expand or shift the window

        # build the frequency map of s1
        freq_map = {c: 0 for c in s1}
        for c in s1: freq_map[c] += 1

        # setup variables
        C_NOT_FOUND = -1
        invalid_c = set()
        foreign_c = set()
        left, right = 0, 0
        while right < len(s2):
            
            # take s2_at_right into window
            s2_at_right = s2[right]
            s2_at_left  = s2[left]
            if s2_at_right not in freq_map:
                foreign_c.add(s2_at_right)
            else:
                freq_map[s2_at_right] -= 1
                if freq_map[s2_at_right] < 0:
                    invalid_c.add(s2_at_right)

            # evaluate invariant conditions
            has_foreign_c = len(foreign_c) > 0
            has_invalid_c = len(invalid_c) > 0
            while has_foreign_c or has_invalid_c:
                print('Window breaks invariants')
                print(f'has_foreign? {has_foreign_c}')
                print(f'has_invalid? {has_invalid_c}')
                print(f'Indices are: ({left}, {right})')
                print(f"win_size={right - left + 1}")
                print(f"win={s2[left:right+1]}")
                print(f"freq_map={freq_map}")
                print()
                
                # loop:
                # 0 (entry condition): we are invalid
                # 1. shift window to potentially become valid
                # 2. update constraints
                # 3. evaluate constraints

                # pre-shift ritual: discard whatever was at left
                # if left was in freq_map? add it back 
                # possibly the wrong procedure
                foreign_c.discard(s2_at_left)
                if s2_at_left in freq_map: 
                    freq_map[s2_at_left] += 1
                    if freq_map[s2_at_left] >= 0:
                        invalid_c.discard(s2_at_left)
                
                # shift window
                left += 1
                right += 1

                # guard to prevent oob
                if left >= len(s2) or right >= len(s2): return False
                s2_at_right = s2[right]
                s2_at_left  = s2[left]

                # now see if shifting right broke a constraint
                if s2_at_right not in freq_map:
                    foreign_c.add(s2_at_right)
                else:
                    freq_map[s2_at_right] -= 1
                    if freq_map[s2_at_right] < 0:
                        invalid_c.add(s2_at_right)

                # re-evaluate invariant conditions
                has_foreign_c = len(foreign_c) > 0
                has_invalid_c = len(invalid_c) > 0

            # now that we know we have a valid window
            # evaluate the success condition

            window_size = right - left + 1
            success_condition = window_size == len(s1)
            print("found a valid window")
            print(f"win_size={window_size}")
            print(f"win={s2[left:right+1]}")
            print(f"freq_map={freq_map}")
            print(f'has_foreign? {has_foreign_c}')
            print(f'has_invalid? {has_invalid_c}')
            print()
            if success_condition: return True
            else: right += 1

        return False
