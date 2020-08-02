#include "comm.h"
vector<int> plusOne(vector<int>& digits) {
    vector<int> res(digits.size()+1);
    int carry = 0;
    int resCur = res.size() - 1;
    digits.back()++;
    int digitsCur = digits.size() - 1;
    while(digitsCur >= 0){
        res[resCur] = (digits[digitsCur]+ carry) %10;
        cout<<res[resCur] <<endl;
        cout<<digits[digitsCur] <<endl;
        carry = (digits[digitsCur]+ carry) /10;
        resCur--;
        digitsCur--;
    }
    if(carry > 0){
        res[resCur] = 1;
    }
    auto begin = res.begin();
    while(*begin == 0) begin++;
    return vector<int>(begin, res.end());
}
int main(){
    vector<int> v = {0};
    auto res = plusOne(v);
    for(auto ele :res){
        cout<< ele<<' ';
    }
}