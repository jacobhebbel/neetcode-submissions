class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        
        # rectange has height (up-down) and width (left-right)
        # height is the smallest bar in a sequence
        # width is the distance in indices as right - left

        # what question can i answer?
        # => if it bounds a rectangle?
        # => if its the minimum length of a rectangle?

        heights.append(0)
        stack = []  # indices of monotonic-increasing heights
        max_area = 0
        for w, h in enumerate(heights):
            stack_empty = len(stack) == 0
            if stack_empty: 
                stack.append(w)
            
            else:
                w_ = stack[-1]
                h_ = heights[w_]
                while h_ > h:
                    
                    w_ = stack.pop()
                    h_ = heights[w_]
                    stack_empty = len(stack) == 0
                    
                    rwall = w
                    lwall = -1 if stack_empty else stack[-1]

                    their_area = h_ * (rwall - lwall - 1)
                    max_area = max(max_area, their_area)

                    if stack_empty: break

                    # update loop stop condition
                    w_ = stack[-1]
                    h_ = heights[w_]

                stack.append(w)

        return max_area


            