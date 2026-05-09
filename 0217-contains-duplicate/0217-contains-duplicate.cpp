class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
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