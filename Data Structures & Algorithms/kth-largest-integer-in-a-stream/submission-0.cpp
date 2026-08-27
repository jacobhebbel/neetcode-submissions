class KthLargest {
public:

    std::priority_queue<int> q;
    int rank;

    KthLargest(int k, vector<int>& nums) {
        rank = k;
        for (auto num : nums) q.push(num);
    }
    
    int add(int val) {
        q.push(val);
        std::stack<int> stk;
        int temp = rank - 1;

        while(temp--)
        {
            stk.push(q.top());
            q.pop();
        }

        int ans = q.top();
        
        while (stk.empty() == false)
        {
            q.push(stk.top());
            stk.pop();
        }

        return ans;
    }
};
