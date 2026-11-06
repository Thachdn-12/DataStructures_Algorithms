class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
         std::vector<int> res;
        std::unordered_set<int> contains(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++){
            if(contains.find(i+1) == contains.end()){
                res.push_back(i+1);
            }
        }
        return res;
    }
};