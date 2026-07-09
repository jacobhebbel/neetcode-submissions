class Solution:
    def trap(self, height: List[int]) -> int:
        
        lptr, lmax = 0, height[0]
        rptr, rmax = len(height) - 1, height[-1]

        total_water = 0
        while lptr < rptr:
            
            # calculate water at each ptr
            wall = min(lmax, rmax)
            lwater, rwater = wall - height[lptr], wall - height[rptr]
            total_water += max(lwater, 0) + max(rwater, 0)

            # update lmax, rmax for these pointer spots
            lv, rv = height[lptr], height[rptr]
            lmax, rmax = max(lmax, lv), max(rmax, rv)

            if lv < rv: lptr+=1
            if rv < lv: rptr-=1
            if lv == rv: lptr+=1

        return total_water
