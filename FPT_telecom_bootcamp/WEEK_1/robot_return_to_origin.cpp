/*
 *  657. Robot Return to Origin
 */

#include <iostream>

using namespace std;

class solution{
    public:
        bool jubgeCircle(string moves){
            int position[] = {0,0};
            for(char c:moves){
                if(c == 'U'){
                    position[0] ++;
                }
                if(c == 'D'){
                    position[0] --;
                }
                if(c == 'L'){
                    position[1] ++;
                }
                if(c == 'R'){
                    position[1] --;
                }
            }
            //if(position[0] == 0 && position[1] == 0){
            //    return true;
            //}
            //return false;
            return (position[0] == 0 && position[1] == 0);
        }
};

int main(){
    string moves = "UDRR";
    bool ret;
    solution sol;
    ret = sol.jubgeCircle(moves);
    cout<<ret<<endl;
    return 0;
}