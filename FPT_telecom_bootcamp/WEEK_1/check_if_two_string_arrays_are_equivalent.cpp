/*
    1662. Check If Two String Arrays are Equivalent
*/

#include <iostream>
#include <vector>


using namespace std;

class solution{
    public:
        bool arrayStringAreEqual(vector<string>& word1, vector<string>& word2){
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

int main(){
    solution sol;
    vector<string> word1 = {"a", "cb"};
    vector<string> word2 = {"ab", "c"};
    //string word = word1[0] + word1[1];

    bool ret = sol.arrayStringAreEqual(word1,word2);
    cout<<ret<<endl;

    return 0; 
}