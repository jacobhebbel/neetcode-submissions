class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        // assume nums is all unique:
        // given that the range of values is lte to the array size
        // then traversing nums is akin to visiting some index and using the value as a new index
        // because indexes are unique, cases like nums[i] = i are never reachable

        // if nums is not unique, then there is a potential for a loop.
        // using the math behind cycles, we can not only find a cyle but also find its starting node

        // use two pointers, a fast and slow, to traverse the array, where a traversal means vising some nums[i] then treating the value of nums[i] as the next index i
        // let one pointer move "fast", moving twice per iteration, and one pointer move "slow", only once per iteration. We say fast moves twice as much as slow.

        // when a cycle exists, the following is true:
        // -> slow will meet fast inside the cycle
        // -> when slow has met fast, fast has still moved 2x as much as slow
        // -> fast has moved m + k + n*x, slow has moved m+k+ n*y
        //       where m is len before cycle, n is cycle length, k is len inside cycle when pointers meet

        // Because fast moves twice as fast as slow, we can say
        // Dist_Fast = 2*Dist_Slow
        // m + k + n*x = 2*(m + k + n*y)
        // n*x = m+k + 2*n*y
        // m+k = 2ny - nx = ny + ny - nx = n(2y-x)
        // the realization is: the distance from the start to the meeting location (m+k) is a multiple of n, the cycle length. the 

        // we use this to argue the following. If the pointers meet inside a loop, then we can compute the location of the cycle start

        int fast = 0, slow = 0;

        // forever loop to detect the guaranteed cycle
        while (true)
        {
            fast = nums[nums[fast]];
            slow = nums[slow];
            if (fast == slow) break;
        }

        // keep fast at the meet location, move slow to the head of the list
        // when they meet again, they are at the cycle loop
        slow = 0;
        while (true)
        {
            fast = nums[fast];
            slow = nums[slow];
            if (fast == slow) break;
        }

        return slow;
    }
};
