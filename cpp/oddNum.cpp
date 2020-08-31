#include"comm.h"
vector<int> findOddInOrder(vector<int> vec){
    vector<int> result;
    int base = vec[1];
    for(int i = 1 ; i < vec.size(); i++){
        base ^= vec[i];
    }
    int a = 0x1;
    while((base&a) == 0){
        a = a<<1;
    }
    int s1 = 0;
    int s2 = 0;
    for(int i = 0; i < vec.size(); i++){
        if (vec[i] & a){
            s1 ^= vec[i];
        }else{
            s2 ^= vec[i];
        }
    }
    for(int i = 0; i < vec.size(); i++){
        if(vec[i] == s1 || vec[i]== s2){
            if (vec[i] == s1){
                result.push_back(s1);
                result.push_back(s2);
            }else{
                result.push_back(s2);
                result.push_back(s1);
            }
            break;
        }
    }
    return result;
}
int main(){
    vector<int> test = {1,1,2,2,3,3,4,4,4,5,5,5};
    auto s = findOddInOrder(test);
    for(auto ele : s){
        cout<< ele << endl;
    }
}
