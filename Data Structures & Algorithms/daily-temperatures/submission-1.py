class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        
        # we can answer the question only for visited temperatures i
        # by tracking unanswered questions in the stack and answering later 
        stack, ans = [], [0] * len(temperatures)
        for i, t in enumerate(temperatures):

            print(f'On question #{i}:')
            stack_empty = len(stack) == 0
            if stack_empty: 
                stack.append(i)
                print('adding today\'s question')
                print(f'Stack snapshot: {stack}')
                print()

            else:

                # see if we can answer previous questions
                idx = stack[-1]
                temp = temperatures[idx]
                while temp < t:
                    
                    print(f'Identified answerable question (#{idx})')
                    print(f'Stack snapshot: {stack}')

                    # today is hotter than idx, so save the answer
                    # then remove the question from the stack
                    ans[idx] = i - idx
                    stack.pop()

                    print(f'Answered question #{idx}')
                    print(f'Stack snapshot: {stack}')
                    stack_empty = len(stack) == 0
                    if stack_empty: break

                    # update the loop to point to the new top of stack
                    idx = stack[-1]
                    temp = temperatures[idx]

                    
                # because we can't answer today's question yet
                # we put it on the stack, knowing it is the coldest
                # day yet
                stack.append(i)
                print('adding today\'s question')
                print(f'Stack snapshot: {stack}')
                print()
                

        return ans