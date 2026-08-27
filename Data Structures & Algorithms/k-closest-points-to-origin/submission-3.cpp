class Solution {
public:

    static int dist_from_origin(std::vector<int> v)
    {
        return v[0]*v[0] + v[1]*v[1];
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        auto comparison = [](vector<int> &a, vector<int> &b)
        {
            // we want smaller points higher
            int dist_a = dist_from_origin(a);
            int dist_b = dist_from_origin(b);
            
            return dist_a > dist_b;
        };

        std::make_heap(points.begin(), points.end(), comparison);
        std::vector<std::vector<int>> ans;

        auto last = points.end();
        while (k--)
        {
            std::pop_heap(points.begin(), last, comparison);
            last--;
            ans.push_back(*last);
        }

        return ans;
    }
};
