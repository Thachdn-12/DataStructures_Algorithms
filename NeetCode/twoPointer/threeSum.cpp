#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>

using namespace std;

class solution{
    public:
        vector<vector<int>> threeSumBruteForce(vector<int>& nums){
            int i,j,k;
            set<vector<int>> res;
            sort(nums.begin(), nums.end());
            for(i = 0; i < nums.size(); i++){
                for(j  = i+1; j < nums.size(); j++){
                    for(k = j+1; k < nums.size(); k++){
                        if(nums[i]+nums[j]+nums[k] == 0){
                            res.insert({nums[i],nums[j],nums[k]});
                        }
                    }
                }
            }
            return vector<vector<int>>(res.begin(), res.end());
        }   

        vector<vector<int>> threeSumHashMap(vector<int>& nums){
            sort(nums.begin(), nums.end());
            unordered_map<int,int> count;
            for(int num:nums){
                count[num]++;
            }

            vector<vector<int>> res;
            for(int i=0; i < nums.size(); i ++){
                count[nums[i]] --;
                if(i > 0 && nums[i] == nums[i-1]) continue; // Nhảy sang vòng lặp tiếp theo
                for(int j=i+1; j < nums.size(); j++){
                    count[nums[j]] --;
                    if(j > i +1 && nums[j] == nums[j-1]) continue; // Nhảy sang vòng lặp tiếp theo
                    int target = -(nums[i] + nums[j]);
                    if(count[target] > 0){
                        res.push_back({nums[i], nums[j], target});
                    }
                }
                for(int j = i+1; j < nums.size(); j++){
                    count[nums[j]] ++;
                }
            }
            return res;
        }
        vector<vector<int>> threeSumTwoPointer(vector<int>& nums){
            sort(nums.begin(), nums.end());
            vector<vector<int>> res;
            for(int i=0; i<nums.size(); i++){
                int l = i +1;
                int r = nums.size() -1;
                int target = nums[i] + nums[l] + nums[r];
                while(l < r){
                    if(target > 0){
                    r --;
                    }else if(target < 0){
                        l ++;
                    }else{
                        res.push_back({nums[i], nums[l], nums[r]});
                        l ++;
                        r --;
                        while (l < r && nums[l] == nums[l - 1]) {
                            l++;
                        }
                    }
                }
                
            }
            return res;
        }
};

int main(){
    solution sol;
    vector<int> nums = {-1,0,1,2,-1,-4};

    //vector<vector<int>> res = sol.threeSumBruteForce(nums);
    //vector<vector<int>> res = sol.threeSumHashMap(nums);
    vector<vector<int>> res = sol.threeSumTwoPointer(nums);
    for(const auto& row:res){
        for(int x:row){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}
