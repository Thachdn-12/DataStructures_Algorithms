class Solution {
public:
    int majorityElement(std::vector<int> &nums)
    {
        std::unordered_map<int, int> map;
        for (int num : nums)
        {
            map[num]++;
            if (map[num] > nums.size() / 2)
            {
                return num;
            }
        }
        return -1;
    }
};