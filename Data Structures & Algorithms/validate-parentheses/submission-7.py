class Solution:
    def isValid(self, s: str) -> bool:

        stack = []        
        bracket_map = {
            ')': '(',
            '}': '{',
            ']': '['
        }

        for c in s:
            is_open_bracket = c in bracket_map.values()
            if is_open_bracket: stack.append(c)
            
            elif len(stack) == 0: return False

            else:
                expected_bracket = bracket_map.get(c)
                actual_bracket = stack[-1]
                print(
                    expected_bracket,
                    actual_bracket
                )
                if expected_bracket != actual_bracket:
                    return False
                else: stack.pop()
        
        stack_empty = len(stack) == 0
        if stack_empty: return True
        else:           return False
            