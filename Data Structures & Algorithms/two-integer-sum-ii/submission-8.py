class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        

        lptr, rptr = 0, 1
        while lptr < len(numbers) - 1:
            if rptr >= len(numbers): 
                lptr += 1
                rptr = lptr + 1
        
            ln, rn = numbers[lptr], numbers[rptr]

            if ln + rn == target:
                return [lptr + 1, rptr + 1]
            
            if ln + rn < target:
                rptr+=1
            
            if ln + rn > target:
                lptr += 1
                rptr = lptr + 1
