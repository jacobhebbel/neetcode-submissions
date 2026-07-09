class Solution:
    def maxArea(self, heights: List[int]) -> int:
    
        best_area = 0
        lptr, rptr = 0, len(heights) - 1
        while lptr < rptr:
            
            # area calculation
            length = min(heights[lptr], heights[rptr])
            width = rptr - lptr
            this_area = length * width
            best_area = max(this_area, best_area)

            # move step
            # objective: maximize length
            length_l, length_r = heights[lptr], heights[rptr]

            if length_l < length_r:
                lptr+=1
            
            if length_l > length_r:
                rptr-=1
            
            if length_l == length_r:
                lptr+=1

        return best_area