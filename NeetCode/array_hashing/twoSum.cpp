#include <iostream>
#include <vector>
#include <unordered_map>


using namespace std;

class solution{
    public:
        /*
            Time complexity: O(n)
            Space complexity: O(n)
        */
        vector<int> twoSum(vector<int>& nums, int target){
            unordered_map<int, int> seen;
            for(int i = 0; i< nums.size(); i++){
                int complement = target - nums[i];
                if(seen.count(complement)){
                    return {seen[complement],i};
                }
                seen[nums[i]] = i;
            }
            return {};
        }
        /*
            Time complexity: O square
            Space complexity: O(1)
        */
        vector<int> twoSumBruteForce(vector<int>& nums, int target){
            for(int i = 0; i < nums.size(); i++){
                for(int j = i+1; j < nums.size(); j++){
                    if(nums[i] + nums[j] == target){
                        return{i,j};
                    }
                }
            }
            return {};
        }
};


int main(){
    solution mySolution;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = mySolution.twoSum(nums, target);
    cout << result[0] << " " << result[1] << endl; // in ra 0 1
}