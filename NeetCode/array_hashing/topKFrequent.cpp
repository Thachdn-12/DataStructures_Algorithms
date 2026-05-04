#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm> 

using namespace std;
class solution_1{
    public:
        vector<int> topKFrequent(vector<int> nums, int k){
           unordered_map<int, int> count;
           for(int num:nums){
                count[num] ++;
           }
           vector<pair<int,int>> arr;
           for(const auto& p:count){
            arr.push_back({p.second, p.first});
           }
           sort(arr.rbegin(), arr.rend());

           vector<int> res;
           for(int i = 0; i < k; i++){
            res.push_back(arr[i].second);
           }
           return res;
        }
};

int main(){
    solution_1 res1;
    vector<int> nums = {1,2,2,2,3,3};
    vector<int> result_1= res1.topKFrequent(nums, 2);
    cout << "[";
    for(int num : result_1){
        cout<<num;
        cout<<",";
    }
    cout << "]\n";

    return 0;

}