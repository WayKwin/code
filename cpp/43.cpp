#include"comm.h"

void strSum(string& target, const string& add){
    int i = add.size() - 1;
    int cur = target.size() - 1;
    int lastCarry = 0;
    for(; i >= 0;  i--){
        int a = target[cur] - '0';
        int b = add[i] - '0';
        int c = (a+b +lastCarry) %10;
        int carry = (a+b + lastCarry) /10;
        lastCarry = carry;
        target[cur--] = c + '0';
    }
    if(lastCarry != 0){
        target[cur] = lastCarry;
    }
}
string multiply(string num1, string num2) {
    if(num1.empty() || num2.empty()){
        return "";
    }
    bool isNegetive;
    if(num1[0] == '-' &&num2[0] == '-'){
        isNegetive = false;
    }else if( num1[0] !='-' && num2[0] != '-'){
        isNegetive = false;
    }else{
        isNegetive = true;
    }
    int aBegin = num1[0] == '-'?1:0;
    int bBegin = num2[0] == '-'?1:0;
    // 9 * 9 < 9 * 10 所以两个数乘法肯定小于两个树的乘法 
    string res(num1.size()+num2.size(),'0');
    int offset = 0;
    int lastCarry = 0 ;
    for(int i = num1.size() - 1; i >=aBegin; i--, offset++){
        int a = num1[i] - '0';
        string curSum(num1.size()+num2.size(),'0');
        int curSumIndex = curSum.size() - 1;
        lastCarry = 0;
        for(int j = num2.size() - 1; j >= bBegin; j--){
            int b = num2[j] - '0';
            int carry = (a*b + lastCarry) /10;
            int cur = (a*b+lastCarry) %10;
            lastCarry = carry;
            curSum[curSumIndex - offset] = cur + '0';
            curSumIndex--;
            //进位
        }
        if(lastCarry != 0){
            curSum[curSumIndex -offset] = lastCarry + '0';
        }
        // cout << res<<endl;
        // cout <<curSum<<endl;
        // cout <<"-------" <<endl;
        strSum(res,curSum);
    }
    int begin = 0;
    while(begin < res.size() && res[begin] == '0'){
        begin++;
    }
    if(begin == res.size()){
        return "0";
    }
    if(isNegetive){
        string s;
        s.push_back('-');
        s += res.substr(begin,res.size() - begin);
        return s;
    }
    return res.substr(begin,res.size() - begin);
}
int main(){
    string a = "-999999";
    string b = "99";
    cout << multiply(a,b) << endl;
}