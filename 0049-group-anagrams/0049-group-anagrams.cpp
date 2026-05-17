class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
         unordered_map<string, vector<string>> res;
        /**
         * Sort all element in string list
         */
        for(const auto& item:strs){
            string sort_item = item;
            sort(sort_item.begin(), sort_item.end());
            res[sort_item].push_back(item);
        }
        /**
         * Create container and push item to this.
         */
        vector<vector<string>> result;
        for(auto& pair: res){
            result.push_back(pair.second);
        }
        return result;
    }
};