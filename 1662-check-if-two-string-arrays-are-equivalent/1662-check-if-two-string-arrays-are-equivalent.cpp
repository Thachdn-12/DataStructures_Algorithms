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
        if(tempWord1 == tempWord2){
            return true;
        }
        return false;
    }
};