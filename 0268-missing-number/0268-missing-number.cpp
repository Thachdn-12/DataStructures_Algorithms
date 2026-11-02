class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int missingNum = 0;
        for (int i = 1; i <= nums.size(); i++) {
            missingNum = missingNum ^ i;
        }

        for (int i = 0; i < nums.size(); i++) {
            missingNum = missingNum ^ nums[i];
        }
        return missingNum;
    }
};