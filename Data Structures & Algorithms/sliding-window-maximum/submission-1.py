class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        import heapq

        # build a map (utility for tracking)
        window_freq = {x: 0 for x in nums}
        pq = [] # heappush does minheap, negate x to make it a max heap
        for i in range(k - 1):
            x = nums[i]
            window_freq[x] += 1
            heapq.heappush(pq, (-x, x))
        
        # print('PQ snapshot')
        # print(pq)
        answer = [] # answer tracks largest element at window position i
        left, right = 0, k-1 # pointers to enqueue / dequeue elements
        while right < len(nums):
            # print(f"right={right}")
            # Flow: 
            # 1. get a valid max element
            # 2. assign the max element for the window
            # 3. update window frequencies (pre move)
            # 4. move window (move)

            # take whats at right
            arriving = nums[right]
            window_freq[arriving] += 1
            heapq.heappush(pq, (-arriving, arriving))

            # print('PQ snapshot')
            # print(pq)
            # the top element may have a frequency of 0
            # if it does then its not a valid element
            _, max_element = pq[0]
            while window_freq[max_element] <= 0:
                heapq.heappop(pq)
                # print('PQ snapshot')
                # print(pq)
                _, max_element = pq[0]
            
            # invariant: max element is an element in the window
            answer.append(max_element)

            # update frequencies
            leaving = nums[left]
            window_freq[leaving] -= 1

            # actually move the window
            left += 1
            right += 1

        return answer