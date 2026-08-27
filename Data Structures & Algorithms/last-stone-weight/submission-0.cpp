class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::priority_queue<int> pq;

        // adding stones to the pq
        for (auto num : stones) pq.push(num);

        while (pq.size() > 1)
        {
            int x = pq.top();
            pq.pop();

            int y = pq.top();
            pq.pop();

            int new_stone = x - y;
            if (new_stone > 0) pq.push(new_stone);
        }

        int ans = pq.size() == 1 ? pq.top() : 0;
        return ans;
    }
};
