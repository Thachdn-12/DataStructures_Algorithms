class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int id = 0; id < n-2; id++){
            if(id > 0 && nums[id] == nums[id-1]){
                continue;
            }
                
            if(nums[id] > 0){
                break;
            }

            int left = id +1;
            int right = n -1;

            while(left < right){
                int sum = nums[id] + nums[left] + nums[right];
                if(sum < 0){
                    left ++;
                }else if (sum > 0){
                    right --;
                }else{
                    ret.push_back({nums[id], nums[left], nums[right]});
                    left ++;
                    right --;
                    while(left < right && nums[left] == nums[left -1]){
                    left ++;
                }
                while(left < right && nums[right] == nums[right +1]){
                    right --;
                }
                }
                

                
            }
        }
        return ret;
    }
};