#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class solution{
    public:
        vector<int> twoSum(vector<int>& nums, int target){
            for(int i = 0; i < nums.size(); i++){
                int tmp = target -nums[i];
                for(int j = 0; j < nums.size(); j++){
                    if(nums[j] == tmp){
                        return {i+1, j+1};
                    }
                }
            }
            return {};
        }

        vector<int> twoSumHashMap(vector<int>& nums, int target){
            unordered_map<int,int> map;
            for(int i = 0; i < nums.size(); i++){
                int tmp = target - nums[i];
                if(map.count(tmp)){
                    return {map[tmp],i+1};
                }
                map[nums[i]] = i + 1;
            }
            return {};
        }

        vector<int> twoSumTwoPointer(vector<int>& nums, int target){
            int l = 0, r = nums.size() -1;

            while(l<r){
                int cur = nums[l] + nums[r];
                if(cur < target){
                    l ++;
                }else if(cur > target){
                    r --;
                }else{
                    return{l +1,r +1};
                }
            }
            return {};
        }
};

int main(){
    solution sol;
    vector<int> nums = {1,2,3,4};
    vector<int> res = sol.twoSumTwoPointer(nums,3);
    cout<<"Result: [";
    for(int item:res){
        cout<<item<<" ";
    }
    cout<<"]";
    return 0;
}