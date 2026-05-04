#include <iostream>
#include <vector>

using namespace std;


class Solution_1{
    public:
        vector<int> productExceptionSelf(vector<int>& nums){
            vector<int> res;
            for(int i=0; i<nums.size(); i++){
                int prod = 1;
                for(int j =0; j<nums.size(); j ++){
                    if(i != j){
                        prod *= nums[j];
                    }
                }
                res.push_back(prod);
            }
            return res;
        }
};

class Solution_2{
    public:
        vector<int> productExceptSelf(vector<int>& nums) {
            int n = nums.size();
            vector<int> res(n);
            vector<int> pref(n);
            vector<int> suff(n);
        
            pref[0] = 1;
            suff[n - 1] = 1;
            for (int i = 1; i < n; i++) {
                pref[i] = nums[i - 1] * pref[i - 1];
            }
            for (int i = n - 2; i >= 0; i--) {
                suff[i] = nums[i + 1] * suff[i + 1];
            }
            for (int i = 0; i < n; i++) {
                res[i] = pref[i] * suff[i];
            }
            return res;
        }
};
int main(){
    vector<int> nums = {1,2,4,6};
    Solution_1 sol_1;
    vector<int> res_1 = sol_1.productExceptionSelf(nums);
    for(int num:res_1){
        cout<<num<<" ";
    }
    return 0;
}