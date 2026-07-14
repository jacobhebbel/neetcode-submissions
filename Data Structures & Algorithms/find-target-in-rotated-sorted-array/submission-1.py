class Solution:
    def search(self, nums: List[int], target: int) -> int:
        
        lo, hi = 0, len(nums) - 1
        while lo <= hi:
            
            mid = lo + (hi - lo) // 2

            # check if lucky
            if nums[lo] == target: return lo
            if nums[mid] == target: return mid
            if nums[hi] == target: return hi

            left_sorted = nums[lo] < nums[mid]
            right_sorted = nums[mid] < nums[hi]

            # check the sorted intervals if they contain our value (easy)
            if left_sorted and (nums[lo] < target and target < nums[mid]):
                hi = mid - 1
            
            elif right_sorted and (nums[mid] < target and target < nums[hi]):
                lo = mid + 1
            
            # if sorted intervals don't contain our value
            # explore the other subarray            
            elif left_sorted:   lo = mid + 1
            else:               hi = mid - 1

            # [lo, mid] or [mid, hi] is sorted, and may contain my target
            


        return -1