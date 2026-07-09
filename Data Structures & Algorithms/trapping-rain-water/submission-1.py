class Solution:
    def trap(self, height: List[int]) -> int:
        
        lmax = [0] * len(height)
        lmax[0] = height[0]
        for i in range(1, len(height)):
            lmax[i] = max(lmax[i - 1], height[i - 1])

        rmax = [0] * len(height)
        rmax[-1] = height[-1] 
        for i in range(len(height) - 2, -1, -1):
            rmax[i] = max(rmax[i + 1], height[i + 1])


        total_water = 0
        for i in range(len(height)):

            lwall, rwall = lmax[i], rmax[i]
            small_wall = min(lwall, rwall)
            this_wall = height[i]

            this_water = max(small_wall - this_wall, 0)
            total_water += this_water

        return total_water


