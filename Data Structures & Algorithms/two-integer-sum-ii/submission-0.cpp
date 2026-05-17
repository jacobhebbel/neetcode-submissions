class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        // iterate moves through the array
        // find moves through the option space
        int iteratePtr = 0;
        int findPtr = 0;


        // iterate until itrPtr reaches the end
        while (iteratePtr < numbers.size()) {
            
            // root-leaf: root < leaf due bc arr is ascending sorted
            int root = numbers[iteratePtr];
            findPtr = iteratePtr + 1;
            while (findPtr < numbers.size() &&
                    (root + numbers[findPtr]) <= target) {
                
                int leaf = numbers[findPtr];
                if ((root + leaf) == target)
                    return {iteratePtr + 1, findPtr + 1};
                findPtr++;
            }

            iteratePtr++;
        }

        return {-1, -1};
    }
};
