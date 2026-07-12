class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        
        # bs with row-major indexing
        R, C = len(matrix), len(matrix[0])
        print(R, C)

        lo, hi = 0, (R * C) - 1

        while lo <= hi:

            mid = lo + ((hi - lo) // 2)
            r, c = mid // C, mid % C
            print(r, c)    
            
            # if found: return true
            if matrix[r][c] == target: return True

            # if under: increase lb
            elif matrix[r][c] < target: lo = mid + 1

            # if over: decrease hb
            elif matrix[r][c] > target: hi = mid - 1

        return False