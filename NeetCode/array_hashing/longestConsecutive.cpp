#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <unordered_map>

using namespace std;

class solution_1{
    public:
        int longestConsecutive(vector<int>& nums){
            int res = 0;
            unordered_set<int> num_set(nums.begin(), nums.end());
            for(int num:nums){
                int streak = 0, curr = num;
                while(num_set.find(curr) != num_set.end()){
                    curr ++;
                    streak ++;
                }
                res = max(res,streak);
            }
            return res;
        }
};

class solution_2{
    public:
        int longestConsecutive_2(vector<int>& nums){
            if(nums.empty()) return 0;
            sort(nums.begin(), nums.end());
            int streak = 0, curr = nums[0], res = 0, n = 0;

            while(n < nums.size()){
                if(curr != nums[n]){
                    curr = nums[n];
                    streak = 0;
                }
                while(n < nums.size() && nums[n] == curr){
                    n ++;
                }
                streak ++;
                curr ++;
                res = max(res,streak);
            }
            return res;
        }
};

class solution_3{
    public:
        int longestConsecutive_3(vector<int>& nums){
            unordered_set<int> numSet(nums.begin(), nums.end());
            int longest = 0;
            for(int num:nums){
                if(numSet.find(num -1) == numSet.end()){
                    int length = 1;
                    while(numSet.find(num + length) != numSet.end()){
                        length ++;
                    }
                    longest = max(longest, length);
                }
            }
            return longest;
        }
};
class solution_4 {
public:
    int longestConsecutive_4(vector<int>& nums) {
        unordered_map<int, int> mp;
        int res = 0;

        for (int num : nums) {
            if (!mp[num]) {
                mp[num] = mp[num - 1] + mp[num + 1] + 1;
                mp[num - mp[num - 1]] = mp[num];
                mp[num + mp[num + 1]] = mp[num];
                res = max(res, mp[num]);
            }
        }
        return res;
    }
};