class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        
        # This jit fucked
        # We track 1 set of lo hi for 1 array
        # Our stop condition is when we find the median
        # The median is the floor((||M|| + ||N||) / 2)th element (m*)
        # We sample a potential median i in M, and do m* - i to get j in N
        # These are the midpoints, and we have to check some conditions:
        
        # we claim m is smaller or equal to n in size
        m = nums1 if len(nums1) < len(nums2) else nums2
        n = nums1 if m is nums2 else nums2
        
        length = len(m) + len(n)
        mid = length // 2

        lo, hi = 0, len(m)
        while lo <= hi:
            
            # let median be some i + j
            i = lo + (hi - lo) // 2
            j = mid - i

            # if i + j is the median, then the following holds true:
            # m[i] should be greater than n[j-1]
            # n[j] should be greater than m[i-1]
            # m[i] should be less than n[j+1]
            # n[j] should be less than m[i+1]
            
            m_larger = m[i] if i < len(m) else float('inf')
            n_larger = n[j] if j < len(n) else float('inf')
            m_smaller = m[i-1] if i-1 >= 0 else float('-inf')
            n_smaller = n[j-1] if j-1 >= 0 else float('-inf')
            
            if m_larger >= n_smaller and n_larger >= m_smaller:
                # success, condition satisfied
                if length % 2: return min(m_larger, n_larger)
                else: return (
                    (max(n_smaller, m_smaller) + min(m_larger, n_larger)) / 2
                )

            elif m_larger < n_smaller:
                # failure condition, need to make m bigger
                lo = i + 1
            else: # n_larger < m_smaller
                # failure condition, need to make m smaller
                hi = i - 1

        return -1

