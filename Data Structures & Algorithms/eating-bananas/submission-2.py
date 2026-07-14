class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        
        def timeToEatPiles(piles, speed):
            
            total_tte = 0
            for p in piles:
                tte_pile, remainder = p // speed, p % speed
                if remainder: tte_pile += 1
                total_tte += tte_pile
            return total_tte

        largestElement = max(piles)
        lo, hi = 1, largestElement
        best_k = largestElement
        while lo <= hi:
            
            # sample k as the mid in a range
            # get the time to eat all piles at speed k
            k = lo + (hi - lo) // 2
            tte = timeToEatPiles(piles, k)

            print(lo, hi)
            print(k, tte)

            if tte > h:
                # when the tte is too slow, increase the speed
                lo = k + 1
                print('Eating too slow, moving lo')
            else:
                # while the constraint is satisfied, decrease speed
                best_k = min(best_k, k)
                hi = k - 1
                print(f'Satisfied problem, best_k={best_k}, moving hi')
            print()

        return best_k