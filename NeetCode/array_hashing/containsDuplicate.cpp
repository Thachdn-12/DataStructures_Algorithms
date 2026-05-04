/*
    Given an integer array nums, return true if any value appears more than once in the array, otherwise return false.
*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
class solution{
    public:
        bool hasDuplicate(int nums[], int size){
            int seen[] = {};
            for(int index = 0; index < size; index ++){
                if(nums[index] == seen[nums[index]]){
                    std::cout<<"Element Duplicate: "<<nums[index]<<"\n";
                    return false;
                }
                seen[nums[index]] = nums[index];
            }
            std::cout<<"Does not duplicate Element !";
            return true;
        }

        /*
            we can use std::vector <int> to create an array.
            then we can not use size variable to contain number of array, we have size() function for this task.
            Unordered_set
        */
        bool hasDuplicatewithSet(vector<int>& nums){
            unordered_set<int> seen;
            for (int num:nums){
                if(seen.count(num)){
                    cout<<"Element Duplicate with set: "<<num<<"\n";
                    return true;
                }
                seen.insert(num);
            }
            return false;
        } 
};

int main(){
    solution mySolution;
    int nums[] = {1,2,3,4,3};
    vector<int> list = {1,2,3,4,3};
    int size = sizeof(nums)/sizeof(nums[0]);

    mySolution.hasDuplicate(nums, size);
    mySolution.hasDuplicatewithSet(list);
    return 0;
}