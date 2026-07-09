class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        
        nums = sorted(nums)

        sol_set = set()
        for i in range(1, len(nums) - 1):
            
            lptr, rptr = 0, len(nums) - 1
            while lptr < i and rptr > i:
                # move one or the other while the sum isnt 0

                total = nums[lptr] + nums[i] + nums[rptr]

                if total == 0:
                    sol_set.add((nums[lptr], nums[i], nums[rptr]))
                    lptr+=1
                
                if total < 0:
                    lptr+=1
                
                if total > 0:
                    rptr-=1

        answer = []
        for group in sol_set:
            l, m, r = group
            answer.append([l, m, r])

        return answer
        
            
