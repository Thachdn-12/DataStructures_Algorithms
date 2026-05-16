class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string tempWord1;
            string tempWord2;
            for(int i=0; i<word1.size(); i++){
                tempWord1 += word1[i];
            }
            for(int i=0; i<word2.size(); i++){
                tempWord2 += word2[i];
            }
            cout<<tempWord1<<endl;
            cout<<tempWord2<<endl;
            if(tempWord1.length() != tempWord2.length()){
                return false;
            }
            for(int i = 0; i < tempWord1.length(); i++){
                if(tempWord1[i] != tempWord2[i]){
                    return false;
                }
                cout<<tempWord1[i]<<endl;
                cout<<tempWord2[i]<<endl;
            }
            return true;
    }
};