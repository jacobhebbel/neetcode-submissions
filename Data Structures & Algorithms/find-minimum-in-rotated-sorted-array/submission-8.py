class Solution:
    def findMin(self, nums: List[int]) -> int:
        
        # if interval is sorted: return 0th element
        # else: bisect while l > r 

        lo, hi = 0, len(nums) - 1

        # binary search procedure
        while lo < hi:
            mid = lo + (hi - lo) // 2
            print(lo, hi, mid)

            if nums[mid] > nums[hi]: lo = mid + 1
            else: hi = mid
        
        return nums[lo]



