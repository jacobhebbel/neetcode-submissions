class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        
        if len(nums) == 0: return 0
        min_ = min(nums)
        max_ = max(nums)
        numset = set(nums)
        best_lcs = 1
        for i in nums:
            # finds a valid sequence starter
            if i - 1 in numset:
                continue

            lcs = 1
            seq = i
            while seq + 1 in numset:
                lcs+=1
                seq+=1
            
            best_lcs = max(best_lcs, lcs)
        return best_lcs
            