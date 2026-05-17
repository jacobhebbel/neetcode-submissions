class Solution {
public:

    bool isSorted(vector<int> &nums, int l, int r) {
        cout << "checking if indices " << l << " to " << r << " are sorted" << endl;
        int prev = nums[l];
        cout << prev << endl;
        for (int i = l + 1; i < r; i++) {
            cout << nums[i] << endl;
            if (nums[i] < prev) return false;
            prev = nums[i];
        }

        return true;
    }

    int findMin(vector<int> &nums) {
        int left = 0;
        int right = nums.size();
        int mid = (right + left) / 2 + (right + left) % 2;
        
        while (right - left > 1) {
            
            cout << "right: " << right << "\nleft: " << left << "\nmid: " << mid << endl;
            
            if (!isSorted(nums, left, mid)) right = mid;
            else if (!isSorted(nums, mid, right)) left = mid;
            else if (nums[left] < nums[mid]) right = mid;
            else left = mid;
            
            mid = (right + left) / 2 + (right + left) % 2;
        }

        cout << left << ' ' << mid << endl;
        return nums[left];
    }
};