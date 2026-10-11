class Solution {
public:
    int majorityElement(vector<int>& nums) {
         std::sort(nums.begin(), nums.end());
        int maxCount = 0;
        int count = 0;
        int value = 0;
        if(nums.size() == 1){
            return nums[0];
        }
        for (int i = 0; i < nums.size() -1; i++)
        {
            if(nums[i] == nums[i+1]){
                count ++;
            }else{
                count = 0;
            }
            
            if(count > maxCount){
                maxCount = count;
                value = nums[i];
            }
            
        }
        return value;
    }
};