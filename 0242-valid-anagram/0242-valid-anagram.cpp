class Solution {
public:
    bool isAnagram(string s, string t) {
         if(s.length() != t.length()){
                return false;
            }
            std::vector<int> count(26,0);
            
            for(int i = 0; i < s.length(); i++){
                count[s[i] - 'a'] ++;
                count[t[i] - 'a'] --;
                std::cout<<"count[s["<<i<<"] - 'a'] = "<<count[s[i] - 'a']<<"\n";
                std::cout<<"count[t["<<i<<"] - 'a'] = "<<count[t[i] - 'a']<<"\n";
            }
            std::cout<<"\n----------------------------------\n";
            for(int value:count){
                if(value != 0){
                    std::cout<<"Value: "<<value<<"\n";
                    return false;
                }
            }
            return true;
    }
};