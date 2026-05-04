/**
 * 643. Maximum Average Subarray I
 */

#include <iostream>
#include <vector>


using namespace std;

class solution{
    public:
        double findMaxAverage(vector<int>& nums, int k){
            int maxSum = 0;
            for(int i = 0; i < (k-1); i++){
                int temp = 0;
                for(int j = i; j < (i+k) && j < nums.size(); j++){
                    temp += nums[j];
                }  
                maxSum = max(maxSum, temp);
            }
            return (double)maxSum/k;
        }
        double findMaxAverage_slidingWindow(vector<int>& nums, int k){
            int window = 0;
            for(int i = 0; i < k; i++){
                window += nums[i];
            }

            int maxSum = 0;
            for(int i = k; i < nums.size(); i++){
                window += nums[i];
                window -= nums[i-k];

                maxSum = max(maxSum, window);
            }

            return (double)maxSum/k;
        }
};

int main(){
    solution sol;
    vector<int> nums = {1,12,-5,-6,50,3};
    int k = 4;
    double ret = sol.findMaxAverage(nums,k);
    cout<<"Maximum average is "<<ret<<endl;
    cout<<"++++++++++++++++++++++++++++++\n";
    double ret1 = sol.findMaxAverage_slidingWindow(nums, k);
    cout<<"Maximum average is "<<ret1<<endl;

    return 0;
}