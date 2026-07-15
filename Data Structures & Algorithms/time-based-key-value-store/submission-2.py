class TimeMap:

    def __init__(self):
        self.cache = {}

    def set(self, key: str, value: str, timestamp: int) -> None:
        
        # Strategy:
        # key points to two lists: values, stamps
        # When given a query, B.S. on stamps to find stamp_q
        # the index of stamp_q correlates to its associated value
        # Insert complexity:
        # Time: O(1), dict is unsorted, list append is O(1) amortized
        # Space: O(n), technically O(2n) as we maintain 2 n-sized lists for n samples

        # guard to make a new dict entry
        if key not in self.cache:
            self.cache[key] = {
                'stamps': [timestamp],
                'values': [value]
            }
        
        # otherwise append - assuming timestamps are strictly increasing
        else:

            # name the lists because they're unordered
            # O(1) access because dict is unsorted
            values = self.cache[key]['values']
            stamps = self.cache[key]['stamps']

            # append the vals (amortized O(1))
            stamps.append(timestamp)
            values.append(value)


    def get(self, key: str, timestamp: int) -> str:
        
        # Strategy:
        # given a key, timestamp: return the value 
        # timestamp (ts) may not exist; return the largest timestamp <= ts
        # Lookup must be O(log n) ==> Binary Search

        # Binary Search on key.stamps, return the index in key.values

        # guard clause for early return:
        # is key lookup O(1)? If cache maintains a hashset then yeah, otherwise doubt
        if key not in self.cache: return ""

        values = self.cache[key]['values']
        stamps = self.cache[key]['stamps']

        # search over the full list, we can't check if the key exists or not in O(log n) time
        lo, hi = 0, len(stamps) - 1
        approximation = ""

        # B.S. procedure
        while lo <= hi:
            
            # check the midpoint between lo and hi,
            # closing half the interval based on mid
            mid = lo + (hi - lo) // 2

            # mid is between lo and hi ==> its a valid index
            ts, val = stamps[mid], values[mid]

            # success condition: we found the exact timestamp to return
            if ts == timestamp: return val

            # absolute failure: we looked ahead, focus on the lower interval next iteration
            elif ts > timestamp: hi = mid - 1

            # partial failure: we didn't find timestamp, however it is a valid candidate
            # if the item doesn't exist, then we can safely return the last set best_index 
            else:

                approximation = val                
                lo = mid + 1
        
        # couldn't find the exact match
        return approximation








